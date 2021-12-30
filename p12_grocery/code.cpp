#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void menu(void);
void display(void);
void in_out(int choice);

int main()
{
	menu();
	return 0;
}



void menu(void)
{
	int key;
	int proper = 0;
	while (!proper)
	{
		system("cls");
		printf("1.��ʾ����б�\n");
		printf("2.���\n");
		printf("3.����\n");
		printf("4.�ر�ϵͳ\n");
		printf("\n��ѡ���ܣ�\n");
		key = _getch();
		switch (key)
		{
		case '1':display(); break;
		case '2':in_out(1); break;
		case '3':in_out(2); break;
		case '4':proper = 1; break;
		default:break;
		}
	}
}

void display(void)
{
	system("cls");
	int key;
	char buf[64];
	FILE* file;
	errno_t err = 0;
	err = fopen_s(&file, "store.txt", "r");
	if (err)  printf("�ļ��򿪴���/n");
	else
	{
		while (fgets(buf, 64, file) != NULL)
		{
			printf("%s", buf);
		}
		printf("\n��������˳�");
		key = _getch();
		fclose(file);
	}
}

void in_out(int choice)
{
	system("cls");
	typedef struct linklist
	{
		char name[64];
		int quantity;
		struct linklist* next;
	}a;
	a* head = NULL, * node = NULL, * end = NULL;
	head = (a*)malloc(sizeof(a));
	char buf[64];
	int number;
	int over = 0;
	char c;

	//�����ֿ���Ϣ
	if (head != NULL)
	{
		end = head;
		node = head;
		FILE* file;
		errno_t err = 0;
		err = fopen_s(&file, "store.txt", "r");
		if (err)  printf("�ļ��򿪴���/n");
		else
		{
			over = 0;
			while (!over)
			{
				
				if (fgets(buf, 64, file) == NULL) over = 1;
				else 
				{
					strcpy_s(node->name, buf);
					fscanf_s(file, "%d\n", &number);
					node->quantity = number;
				}
				end = node;
				if (!over)
				{
					node->next = (a*)malloc(sizeof(a));
					if (node->next != NULL)
					{
						end = node->next;
						node = end;
					}
					else
					{
						printf("����ռ�ʧ�ܣ�\n");
						over = 1;
					}
				}
			}
			end->next = NULL;
			fclose(file);
		}
	}
	else printf("����ռ����\n");

	//display
	node = head;
	if (node)
	{
		while (node->next != NULL)
		{
			printf("%s", node->name);
			printf("%d\n", node->quantity);
			node = node->next;
		}
	}

	//�����
	if (choice == 1) printf("��ѡ����Ҫ������Ʒ�����س���������\n");
	if (choice == 2) printf("��ѡ����Ҫ�������Ʒ�����س���������\n");
	while (gets_s(buf, 64) == NULL)
	{
		gets_s(buf, 64);
	}
	strcat_s(buf, "\n");
	if (choice == 1) printf("��ѡ���������������س���������\n");
	if (choice == 2) printf("��ѡ���������������س���������\n");
	while (scanf_s("%d", &number) == EOF)
	{
		c = getchar();
		scanf_s("%d", &number);
	}
	c = getchar();
	over = 0;
	node = head;
	if (node)
	{
		while (!over && node->next != NULL)
		{
			if (strcmp(buf, node->name) == 0) over = 1;
			else node = node->next;
		}
		if (over)
		{
			if (choice == 1)node->quantity += number;
			if (choice == 2)
			{
				if (node->quantity - number >= 0) node->quantity -= number;
				else
				{
					system("cls");
					printf("��治����\n");
					printf("����������أ�\n");
					c = getchar();
				}
			}
		}
		else
		{
			if (choice == 1)
			{
				if (node)
				{
					strcpy_s(node->name, buf);
					node->quantity = number;
					node->next = (a*)malloc(sizeof(a));
					if (node->next)
					{
						end = node->next;
						end->next = NULL;
					}
					else printf("����ռ����\n");
				}
			}
			else if (choice == 2)
			{
				system("cls");
				printf("����Ʒ�����ڣ�\n");
				printf("����������أ�\n");
				c = getchar();
			}
		}
	}

	//����д������Ϣ
	FILE* file;
	errno_t err = 0;
	err = fopen_s(&file, "store.txt", "r+");
	if (err)  printf("�ļ��򿪴���/n");
	else
	{
		node = head;
		if (node)
		{
			while (node->next != NULL)
			{
				fprintf(file, "%s", node->name);
				fprintf(file, "%d\n", node->quantity);
				node = node->next;
			}
			fclose(file);
		}
	}
	

	//free����
	node = head;
	if (head)
	{
		node = head->next;
		free(head);
		head = node;
	}
}