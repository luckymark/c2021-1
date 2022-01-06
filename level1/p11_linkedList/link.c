#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LIMIT 8//����data��С



typedef struct learn {
		int data;
		struct learn* next;
	}linklist;

linklist* Creat(int num);

int Rand(void);//�������С�ڻ����LIMIT��������

void Judge(linklist* p);//�ж�malloc�Ƿ����ɹ�

void Find(linklist* pt, int value, int num, int index, int* flag);

void main() {
	int num;//�ڵ����
	srand((unsigned int)time(0));//������������data�����������
	printf("������ڵ���,���븺���뿪\n");
	scanf_s("%d", &num);
	linklist* p=Creat(num);//��������,����ָ��ָ���ͷ

	printf("������Ҫ���ҵ�ֵ������-1�뿪��\n");

	
	
	int value;
	while (scanf_s("%d", &value) != 0 && value != -1) {
		int index = 1;//����
		linklist* copy = p;//����p����ʼ��ַ�Ա��´α���
		int flag = 1;//�ж��Ƿ��ҵ��ı�־
		if (num == 0) {
			printf("������Ϊ�ա�Bye!");
			exit(0);
			
		}
		else {
			Find(p, value, num,index,&flag);
			puts("done");
			p = copy;//�ظ�p��ʹָ���ͷ
			printf("������Ҫ���ҵ�ֵ������-1�뿪��\n");

		}
	}
	
}


linklist* Creat(int num) {
	linklist* head = (linklist*)malloc(sizeof(linklist));
	head->data = 0;//test
	Judge(head);
	head->next = NULL;
	

	if (num >= 0) {

		if (num >= 1) {
			linklist* first = (linklist*)malloc(sizeof(linklist));//��һ���ڵ�
			Judge(first);
			first->next = NULL;
			head->next = first;
			first->data = Rand();
			for (int i = 1; i < num; i++) {
				linklist* node = (linklist*)malloc(sizeof(linklist));
				Judge(node);
				first->next = node;
				node->data = Rand();
				first = node;
				first->next = NULL;
			}

		}
		
	}
	else {
		
		exit(0);
	}

	return head;
}

int Rand(void) {
	return (rand()%LIMIT+1);

}

void Judge(linklist* p) {
	if (p==NULL) {
		printf("�ڴ�ռ䲻�㡣Bye\n");
		exit(1);
	}
	
}

void Find(linklist* pt,int value,int num,int index,int* flag) {
	if (pt->data == value && num>0 ) {
		printf("��%d��ֵΪ%d�Ľڵ����ţ�%d\n", index, value, num);
		num--;
		index++;
		*flag = 0;//�ҵ���value
		pt = pt->next;//ָ����һ���ڵ�
		Find(pt, value, num, index,flag);
	}
	else if(num==0) {
		if (*flag) {
			printf("��%d��ֵΪ%d�Ľڵ����ţ�-1\n", index, value);//û�ҵ�������-1
		}
		return 0;
	}
	else if (pt->data != value && num > 0) {
		pt = pt->next;
		num--;
		Find(pt, value, num, index, flag);
	}
}