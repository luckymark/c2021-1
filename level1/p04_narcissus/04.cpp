#include<stdio.h>
/*
��ӡ������3λˮ�ɻ���
ˮ�ɻ�����nλ����ÿ����λ��n�η�֮�͵��ڸ�nλ������
���磺153=1^3+5^3+3^3
*/
int main()
{
	int a, x,y,z;
	for (a = 100; a < 1000; a++)
	{
		x = a / 100;
		y = (a / 10) % 10;
		z = a % 10;
		if ((x * x * x + y *y* y + z*z*z) == a)
		{
			printf("%d\n", a);
		}
	}
	return 0;
}