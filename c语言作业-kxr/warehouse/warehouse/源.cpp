#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

typedef struct Things {
    char mark;
    int number;
    struct Things* next;
}Things;

//��ӡ�˵�
void PrintManu() {
	printf("*******************************\n");
	printf("**     ��ӭʹ�ý�����ϵͳ    **\n");
	printf("*******************************\n");
	printf("\n");
	printf("\n");
	printf("###############################\n");
	printf("##    ��������ѡ�����Ĳ���   ##\n");
	printf("###############################\n");
	printf("\n");
	printf("\n");
	printf("��������������������������������\n");
	printf("��                            ��\n");
	printf("��         1.��ѯ���         ��\n");
	printf("��                            ��\n");
	printf("��                            ��\n");
	printf("��         2.��    ��         ��\n");
	printf("��                            ��\n");
    printf("��                            ��\n");
    printf("��         3.��    ��         ��\n");
    printf("��                            ��\n");
    printf("��                            ��\n");
	printf("��         4.�˳�����         ��\n");
	printf("��                            ��\n");
	printf("��������������������������������\n");
}


//��������
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
//��������
int travelLink(Things* head) {
    Things* p = head->next;
    while (p != NULL) {
        if (p->mark != '*') {
            printf("��                                            ��\n");
            printf("��             �ͺ� %c ����Ϊ%d                ��\n", p->mark, p->number);
            printf("��                                            ��\n");
            p = p->next;
        }
        else if (p->mark == '*') {
            printf("���˵���\n");
            printf("������������������������������������������������\n");
            printf("��                                            ��\n");
            p = p->next;
        }
    }
    printf("��                                            ��\n");
    printf("������������������������������������������������\n");
    putchar('\n');
    return 0;
}
//���
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
//����
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
    printf("���ڳ�ʼ�����ã����Ժ�......\n");
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
            printf("�������������Ʒ���ͺţ�\n");
            c = _getch();
            printf("%c \n", c);
            printf("�����������Ʒ��������\n");
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
            printf("���������Ĳ�Ʒ�ͺţ�");
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
