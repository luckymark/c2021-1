#include<stdio.h>
#include<stdlib.h>

typedef struct linklist {
	double value;
	linklist *next;
}list;
int getlink();
void printfvalue(list*);
int nixu(int i);//逆序
int finding(int);
void swap(list *,list*);
void freeall();

list *head = NULL;
list *prev, *current,*end;
int main()
{
	int i,count=0;
	i=getlink();
	printfvalue(head);
	nixu(i);
	printfvalue(head->next);
	printf("%f\n", head->value);
	nixu(i);
	count = finding(count);
	freeall();
	return 0;
}
int getlink()
{
	printf("输入一个数值，按其他字符离开\n");
	double gis;
	int i=0;
	while (scanf_s("%lf",&gis))
	{
		current = (list *)malloc(sizeof(list));
		if (head == NULL)
			head = current;
		else
		    prev ->next = current;
		current->next = NULL;
		current->value = gis;
		i++;
		prev = current;
	}
	end = current;
	return i;
}
void printfvalue(list*head)
{
	current = head;
	while (current != NULL)
	{
		printf("%f\n", current->value);
		current = current->next;
	}
}
int nixu(int i)
{    
	list* stay;
	if (head->next == NULL|| head->next->next== NULL)
	{
		return 0;
	}
	prev = head->next;
	current = head->next->next;
	while (current!= NULL)
	{
		stay= current->next;
		current->next = prev;
		prev = current;
		current = stay;
	}
	head->next->next = NULL;
	head->next = prev;
	return 0;
}

int finding(int count)
{
	current = head;
	int i =1;
	while (current != NULL)
	{
		if (current->value == 5)
		{
			count++;
			printf("第%d个数字是5",i);
		}

		current = current->next;
		i++;
	}
	return count;
}
void swap(list *current,list *next )
{
	prev = current;
	current = next;
	next = prev ;
}
void freeall()
{
    current = head->next;
	free(head);
	while (current != NULL)
	{
    head = current->next;
	free(current);
	current = head;
	}
}



