#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* pNext;
} Node;

Node* create_LinkedList(int);
void show_LinkedList(Node*);
Node* reverse_LinkedList(Node*);
void find_Data(Node*,int);

int main() {
    int len = 0;
    printf("请输入长度：");
    scanf_s("%d", &len);
    Node* pHead = create_LinkedList(len);
    show_LinkedList(pHead);
    printf("链表反转：\n");
    Node* unpHead = reverse_LinkedList(pHead);
    show_LinkedList(unpHead);

    find_Data(pHead, 5);

    return 0;
}

Node* create_LinkedList(int len)
{
    int val;
    Node* pHead = (Node*)malloc(sizeof(Node));
    if(pHead == NULL){
        printf("创建失败，程序终止!");
        exit(-1);
    }
    Node* p = pHead;
    p->pNext = NULL;
    for(int i = 0; i < len; i++){
        printf("请输入第%d个节点的值：", i+1);
        scanf_s("%d",&val);
        Node* pNew = (Node*)malloc(sizeof(Node));
        if(pNew == NULL){
            printf("创建失败，程序终止!");
            exit(-1);
        }
        pNew->data = val;
        p->pNext = pNew;
        pNew->pNext = NULL;
        p = pNew;
    }
    return pHead;
}

void show_LinkedList(Node* pHead)
{
    int i = 1;
    while(pHead->pNext != NULL){
        printf("第%d个节点的数据为：%d\n",i++, pHead->pNext->data);
        pHead = pHead->pNext;
    }
}

Node* reverse_LinkedList(Node* pHead)
{
    if(pHead == NULL || pHead->pNext == NULL){
        return pHead;
    }
    Node* left = NULL;
    Node* mid = pHead->pNext;
    Node* right = mid->pNext;
    while (1){
        mid->pNext = left;
        if(!right)break;
        left = mid;
        mid = right;
        right = right->pNext;
    }
    pHead->pNext = mid;
    return pHead;
}

void find_Data(Node* pHead, int data)
{
    int i = 0, flag = 0;

    while(pHead->pNext != NULL){
        i++;
        if(pHead->pNext->data == 5){
            printf("第%d个节点的值为5\n", i);
            flag = 1;
        }
        pHead = pHead->pNext;
    }
    if(!flag){
        printf("未找到值为5的节点\n");
    }
}
