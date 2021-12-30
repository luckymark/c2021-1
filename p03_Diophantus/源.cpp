#include<stdio.h>
/*
取自《希腊诗选》（Greek Anthology）：
丢番图的童年经过了他一生的六分之一，
青年经过了十二分之一，
又有七分之一的时间是单身汉。
结婚五年后得了个儿子，
儿子比父亲先死四年，
年级是他的一半。
问儿子死时丢番图多大？
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