#include<stdio.h>
/*
ȡ�ԡ�ϣ��ʫѡ����Greek Anthology����
����ͼ��ͯ�꾭������һ��������֮һ��
���꾭����ʮ����֮һ��
�����߷�֮һ��ʱ���ǵ�����
����������˸����ӣ�
���ӱȸ����������꣬
�꼶������һ�롣
�ʶ�����ʱ����ͼ���
*/
int main()
{
	float age, child, youth, marry, sonage,t=0;
	int AGE;
	for (age = 1; t ==0; age++)
	{
		child = age / 6;
		youth = age / 12;
		marry = child + youth + age / 7;
		sonage = age - marry - 5 - 4;
		if (age == (sonage * 2))
		{
			t = 1;
			AGE = (int)age;
			printf("%d", AGE-4);
		}
	}
	return 0;
}