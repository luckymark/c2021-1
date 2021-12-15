#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct _node {
    struct _node* before;
    int value;
    struct _node* next;
}Node;
int main()
{
    Node* head = NULL;
    Node* tail = head;
    int number;
    int i = 0;
    int n[6];
    printf("请输入五个数并在最后加上-1\n");
    do
    {
        scanf("%d", &number);
        n[i] = number;
        i++;
        if (number != -1)
        {
            Node* p = (Node*)malloc(sizeof(Node));
            p->before = NULL;
            p->value = number;
            p->next = NULL;
            if (tail) {
                p->before = tail;
                tail->next = p;
                tail = p;
            }
            else {
                tail = p;
                head = tail;
            }
        }
    } while (number != -1);
    Node* p;
    printf("逆序后的结果是：");
    for (p = tail; p; p = p->before) {
        printf(" %d", p->value);
    };
    printf("\n链表中值为5的节点为：");
    for (i=0;i<=5;i++) {
        if (n[i] == 5)
        {
            printf("%d ", i + 1);
        }
    }  
    printf("\n链表中无剩下的值为5的节点输出-1结束：-1");
    return 0;
}
