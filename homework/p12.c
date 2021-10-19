#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#define MAXL 100
typedef struct goods {
	char name[MAXL];
	int num;
	struct goods* next;
}goods;
void printmenu() {
	printf("********************************************\n");
	printf("***************1.显示存货列表***************\n");
	printf("*******************2.入库*******************\n");
	printf("*******************3.出库*******************\n");
	printf("*****************4.退出程序*****************\n");
	printf("********************************************\n");
	printf("Tips: 请输入选项前数字进行操作(按回车键确认)\n");
	printf("      请正常退出程序，否则新做修改无法保存。\n");
}
goods* readdata(int* n) {
	FILE* data = fopen("p12.data", "r");
	goods* head = (goods*)malloc(sizeof(goods));
	fscanf(data, "%d", n);//文件第一行为货物种类数n
	fscanf(data, "%s%d", head->name, &head->num);
	head->next = NULL;
	goods* end = head;
	for (int i = 1; i < *n; ++i) {
		end->next = (goods*)malloc(sizeof(goods));
		end = end->next;
		fscanf(data, "%s%d",end->name, &end->num);
		end->next = NULL;
	}
	fclose(data);
	return head;
}
void writedata(goods* head,int n) {
	FILE* data = fopen("p12.data", "w");
	fprintf(data, "%d\n", n);
	for (int i = 1; i <= n; ++i) {
		fprintf(data, "%s %d\n", head->name, head->num);
		head = head->next;
	}
}
goods* findgood(goods* head, char* name) {
	while (head!=NULL) {
		if (!strcmp(head->name, name)) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}
int main() {
	int option, n, num;
	char name[MAXL];
	goods* head = readdata(&n);//读取数据到链表，记录首位
	goods* temp = NULL;
	while (1) {
		printmenu();
		CIN:
		scanf("%d", &option);
		switch (option) {
		case 1:
			temp = head;
			for (int i = 1; i <= n; ++i) {
				printf("%d、%s %d\n", i, temp->name, temp->num);
				temp = temp->next;
			}
			break;
		case 2:
			scanf("%s%d", name, &num);
			temp = findgood(head, name);
			if (temp != NULL) {
				temp->num += num;
			}
			else {
				temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				++n;
				temp->next = (goods*)malloc(sizeof(goods));
				temp = temp->next;
				temp->next = NULL;
				strcpy(temp->name, name);
				temp->num = num;
			}
			break;
			printf("操作成功！\n");
		case 3:
			scanf("%s%d", name, &num);
			temp = findgood(head, name);
			if (temp != NULL&&temp->num - num >= 0) {
				temp->num -= num;
				printf("操作成功！\n");
			}
			else {
				printf("操作失败，库存不足。\n");
			}
			break;
		case 4:
			writedata(head, n);
			return 0;
		default:
			printf("无法识别，请重新输入：");
			goto CIN;
			break;
		}
		system("pause");
		system("cls");
	}
}