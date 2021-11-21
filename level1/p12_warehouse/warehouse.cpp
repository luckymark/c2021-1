#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define FULL 10
typedef struct stack {
	char **name;
	int num;
}STACK;
void Interface(STACK* stack,int i);
void push(STACK*stack,int i);
void pop(STACK*stack);
STACK*  Creatstack(int y );
void display(STACK*stack);
int main() {
	STACK*stack=Creatstack(FULL);
	Interface(stack,FULL);
	for (int i = 0; i < FULL; i++) {
		free(stack->name[i]);
		
	}
	free(stack);
}
void Interface(STACK*stack,int i) {
	while (1) {
		printf("请选择需要的服务：\n");
		printf("1.显示存货列表\n2.入库\n3.出库\n4退出程序\n");
		int m = 0;
		scanf_s("%d", &m);
		switch (m) {
		case 1:display(stack);
			break;
		case 2:push(stack, i);
			break;
		case 3: pop(stack);
			break;
		case 4:break;

		}
		if (m == 4) {
			break;
		}
	}

}
void push(STACK*stack,int i) {
	if (stack->num < i) {
		printf("请输入要入库的物品");
		scanf("%s",stack->name[stack->num]);
		
		stack->num++;
	}
	else(printf("满了"));
}
void pop(STACK*stack) {
	if (stack->num > 0) {
		printf("%s已出货", stack->name[stack->num-1]);
		stack->num--;
	}
	else {
		printf("没货了");
	}

}
STACK* Creatstack(int y ) {
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->num = 0;
	stack->name = (char**)malloc(y * sizeof(char*));
	for (int i = 0; i < y; i++) {
		stack->name[i] = (char*)malloc(10 * sizeof(char));
	}
	return stack;
}
void display(STACK*stack) {
	for (int i = 0; i < (stack->num); i++) {

		printf("第%d件货物是%s", i+1, stack->name[i]);


	}



}