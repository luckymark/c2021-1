#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * pNext;
} Node, * pNode;

pNode create_LinkedList(int);
void show_LinkedList(pNode);
pNode reverse_LinkedList(pNode);
void find_Data(pNode,int);

int main() {
    int len = 0;
    printf("�����������ȣ�");
    scanf("%d", &len);
    pNode pHead = create_LinkedList(len);
    show_LinkedList(pHead);
    printf("����ת��\n");
    pNode unpHead = reverse_LinkedList(pHead);
    show_LinkedList(unpHead);

    find_Data(pHead, 5);

    return 0;
}

pNode create_LinkedList(int len)
{
    int val;
    pNode pHead = (pNode)malloc(sizeof(Node));
    if(pHead == NULL){
        printf("����ʧ�ܣ�������ֹ!");
        exit(-1);
    }
    pNode p = pHead;
    p->pNext = NULL;
    for(int i = 0; i < len; i++){
        printf("�������%d���ڵ��ֵ��", i+1);
        scanf("%d",&val);
        pNode pNew = (pNode)malloc(sizeof(Node));
        if(pNew == NULL){
            printf("����ʧ�ܣ�������ֹ!");
            exit(-1);
        }
        pNew->data = val;
        p->pNext = pNew;
        pNew->pNext = NULL;
        p = pNew;
    }
    return pHead;
}

void show_LinkedList(pNode pHead)
{
    int i = 1;
    while(pHead->pNext != NULL){
        printf("��%d���ڵ������Ϊ��%d\n",i++, pHead->pNext->data);
        pHead = pHead->pNext;
    }
}

pNode reverse_LinkedList(pNode pHead)
{
    if(pHead == NULL || pHead->pNext == NULL){
        return pHead;
    }
    pNode left = NULL;
    pNode mid = pHead->pNext;
    pNode right = mid->pNext;
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

void find_Data(pNode pHead, int data)
{
    int i = 0, flag = 0;

    while(pHead->pNext != NULL){
        i++;
        if(pHead->pNext->data == 5){
            printf("��%d���ڵ��ֵΪ5\n", i);
            flag = 1;
        }
        pHead = pHead->pNext;
    }
    if(!flag){
        printf("δ�ҵ�ֵΪ5�Ľڵ�\n");
    }
}
