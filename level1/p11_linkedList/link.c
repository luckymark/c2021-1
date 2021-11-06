#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LIMIT 8//限制data大小



typedef struct learn {
		int data;
		struct learn* next;
	}linklist;

linklist* Creat(int num);

int Rand(void);//随机生成小于或等于LIMIT的正整数

void Judge(linklist* p);//判断malloc是否分配成功

void Find(linklist* pt, int value, int num, int index, int* flag);

void main() {
	int num;//节点个数
	srand((unsigned int)time(0));//用于生成链表data的随机数种子
	printf("请输入节点数,输入负数离开\n");
	scanf_s("%d", &num);
	linklist* p=Creat(num);//创建链表,并用指针指向表头

	printf("请输入要查找的值，输入-1离开：\n");

	
	
	int value;
	while (scanf_s("%d", &value) != 0 && value != -1) {
		int index = 1;//计数
		linklist* copy = p;//保存p的起始地址以便下次遍历
		int flag = 1;//判断是否找到的标志
		if (num == 0) {
			printf("此链表为空。Bye!");
			exit(0);
			
		}
		else {
			Find(p, value, num,index,&flag);
			puts("done");
			p = copy;//回复p，使指向表头
			printf("请输入要查找的值，输入-1离开：\n");

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
			linklist* first = (linklist*)malloc(sizeof(linklist));//第一个节点
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
		printf("内存空间不足。Bye\n");
		exit(1);
	}
	
}

void Find(linklist* pt,int value,int num,int index,int* flag) {
	if (pt->data == value && num>0 ) {
		printf("第%d个值为%d的节点的序号：%d\n", index, value, num);
		num--;
		index++;
		*flag = 0;//找到了value
		pt = pt->next;//指向下一个节点
		Find(pt, value, num, index,flag);
	}
	else if(num==0) {
		if (*flag) {
			printf("第%d个值为%d的节点的序号：-1\n", index, value);//没找到，返回-1
		}
		return 0;
	}
	else if (pt->data != value && num > 0) {
		pt = pt->next;
		num--;
		Find(pt, value, num, index, flag);
	}
}