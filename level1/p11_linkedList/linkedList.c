#include <stdio.h>
#include <stdlib.h>

struct list{
    int value;
    struct list * next;
};

struct list * creatList(int value);
int findValue(struct list * list,int startNum,int value);
int getValue(struct list * list,int num);
void insNode(struct list * list,int num,int value);
struct list * invertedOrder(struct list * list);


int main(){

    struct list * head = creatList(1);
    for (int i = 2; i < 101; ++i) {
        insNode(head,i,i);
    }
    for (int i = 1; i < 101; ++i) {
        printf("Node%3d:%3d\n",i, getValue(head,i));
    }

    head = invertedOrder(head);
    printf("\n");

    for (int i = 1; i < 101; ++i) {
        printf("Node%3d:%3d\n",i, getValue(head,i));
    }

    int num = findValue(head, 1, 5);
    if(num != -1){
        printf("node%3d is 5.\n", num);
    } else{
        printf("No 5 in the list.\n");
    }

    num = findValue(head, num + 1, 5);
    if(num != -1){
        printf("node%3d is 5.\n", num);
    } else{
        printf("No more 5 in the list.\n");
    }
}

struct list * creatList(int value){
    struct list *head = NULL;
    head = malloc(sizeof(struct list));
    if(head != NULL){
        head->value = value;
        head->next = NULL;
    }
    return head;
}

int findValue(struct list * list,int startNum,int value){
    for (int i = 1; i < startNum; ++i) {
        list = list->next;
    }
    while(list != NULL){
        if(list->value == value){
            return startNum;
        } else{
            list=list->next;
            ++startNum;
        }
    }
    return -1;
}

int getValue(struct list * list,int num){
    for (int i = 1; i < num; ++i) {
        list = list->next;
    }
    return list->value;
}

void insNode(struct list * list,int num,int value){
    for (int i = 1; i < num-1; ++i) {
        list = list->next;
    }
    struct list *tem = list->next;
    list->next= malloc(sizeof(struct list));
    list = list->next;
    list->next = tem;
    list->value = value;
}

struct list * invertedOrder(struct list * list){
    struct list *tem1,*tem2;
    tem1 = list;
    list = list->next;
    tem1 -> next=NULL;
    while(list != NULL){
        tem2 = list->next;
        list->next = tem1;
        tem1 = list;
        list = tem2;
    }
    return tem1;
}