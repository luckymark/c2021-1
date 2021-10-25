#include<cstdio>
#include<stdlib.h>
#include<windows.h>
#define maxn 115
using namespace std;
int main()
{
	int cnt=0,fl=0;
	while(1)
	{
		for(int i=1;i<=cnt;++i)
		printf(" ");
		printf("A");
		if(!fl)
		cnt++;
		else cnt--;
		if(cnt>maxn)
		{
			cnt=maxn-1;
			fl^=1;
		}
		if(cnt<0)
		{
			cnt=1;
			fl^=1;
		}
		Sleep(10);
		system("cls");
	}
	return 0;
}
//闻到了重复的味道