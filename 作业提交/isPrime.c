#include<stdio.h>
#include<math.h>

int main()
{
	int num, cnt;
	printf("please insert a number:");
	scanf("%d", &num);
	for( cnt = 2; cnt<=sqrt(num); cnt++ )
	{
		if(num % cnt == 0)
		{
			printf("%d is not Prime", num);
			break;
		}
	}
	if(cnt > sqrt(num))
	{
		printf("%d is Prime", num);
	}
	return 0;
}
