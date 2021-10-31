#include<stdio.h>

void move(int x, int y)
{
	printf("%c->%c\n", x, y);
}
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);//��A���ϵ�n-1�����ӽ���C������B��
		move(a, c);//��A�������һ����������C��
		hanoi(n - 1, b, a, c);//��B���ϵ�n-1�����ӽ���A������C��
	}
}
//move�е�ʵ����hanoi�����е��β����Ӧ����hanoi�������β�a��b��c����Ӧ��ֵҲ�����й��ɵı仯
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
