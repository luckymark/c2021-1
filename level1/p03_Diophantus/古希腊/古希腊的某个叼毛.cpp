#include<stdio.h>
int main()
{
	double life = 1;
	for (; ; life++)
	{
		double child = life / 6, youth = life / 12, single = life / 7, nosex = 5;
		double son_life = life / 2;
		if ( life == child + youth + single + nosex + son_life + 4)
		{
			int fatherlife = (int)life;
			printf("%d", fatherlife-4);
			break;
		}
		
	}
	return 0;
}