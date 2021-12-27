#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

typedef struct Things {
    char mark;
    int number;
    struct Things* next;
}Things;

//打印菜单
void PrintManu() {
	printf("*******************************\n");
	printf("**     欢迎使用进销存系统    **\n");
	printf("*******************************\n");
	printf("\n");
	printf("\n");
	printf("###############################\n");
	printf("##    输入数字选择您的操作   ##\n");
	printf("###############################\n");
	printf("\n");
	printf("\n");
	printf("┌——————————————┐\n");
	printf("│                            │\n");
	printf("│         1.查询库存         │\n");
	printf("│                            │\n");
	printf("│                            │\n");
	printf("│         2.入    库         │\n");
	printf("│                            │\n");
    printf("│                            │\n");
    printf("│         3.出    库         │\n");
    printf("│                            │\n");
    printf("│                            │\n");
	printf("│         4.退出程序         │\n");
	printf("│                            │\n");
	printf("└——————————————┘\n");
}


//创建链表
int createLink(Things* head) {
    Things* rear = head;
    int i;
    for (i = 0; i < 1; ++i) {
        Things* newnode = (Things*)malloc(sizeof(Things));
        newnode->next = NULL;
        newnode->mark = '*';
        newnode->number = 0;
        rear->next = newnode;
        rear = newnode;
    }
    return 0;
}
//遍历链表
int travelLink(Things* head) {
    Things* p = head->next;
    while (p != NULL) {
        if (p->mark != '*') {
            printf("│                                            │\n");
            printf("│             型号 %c 数量为%d                │\n", p->mark, p->number);
            printf("│                                            │\n");
            p = p->next;
        }
        else if (p->mark == '*') {
            printf("库存菜单：\n");
            printf("┌——————————————————————┐\n");
            printf("│                                            │\n");
            p = p->next;
        }
    }
    printf("│                                            │\n");
    printf("└——————————————————————┘\n");
    putchar('\n');
    return 0;
}
//入库
int insertBack(Things* head, char mark, int number) {
    Things* newnode = (Things*)malloc(sizeof(Things));
    newnode->next = NULL;
    newnode->mark = mark;
    newnode->number = number;
    Things* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newnode;
    p = newnode;
    return 0;
}
//出库
void delete0(Things* head,char c) {
    Things* curr = head->next;
    while (curr != NULL) {
        Things* pre = curr;
        Things* p = curr->next;
        while (p != NULL) {
            if (p->mark == c) {
                pre->next = p->next;
                free(p);
                p = pre->next;
            }
            else {
                pre = pre->next;
                p = p->next;
            }
        }
        curr = curr->next;
    }
}


int main() {
    int  k = 1, y,ret=0;
    char x,r;
    Things* head = (Things*)malloc(sizeof(Things));
    head->next = NULL;
    system("color 72");
    printf("正在初始化设置，请稍候......\n");
    Sleep(2000);
    createLink(head);
 A:   system("cls");
    PrintManu();
    while (ret == 0) {
        r = _getch();
        if (r == '1') {
            system("cls");
            travelLink(head);
            system("pause");
            r = 0;
            goto A;
        }
        else if (r == '2') {
            char c;
            int i,n=0;
            printf("请输入需入库物品的型号：\n");
            c = _getch();
            printf("%c \n", c);
            printf("请输入入库物品的数量：\n");
            scanf_s("%d", &i);
            insertBack(head, c, i);
            PrintManu();
            r = 0;
            goto A;
        }
        else if (r == '3') {
            char s;
            system("cls");
            travelLink(head);
            printf("请输入出库的产品型号：");
            s = _getch();
            printf("%c", s);
            system("pause");
            delete0(head, s);
            r = 0;
            goto A;
        }
        else if (r == '4') {
            ret = 1;
        }
    }
	return 0;
}
