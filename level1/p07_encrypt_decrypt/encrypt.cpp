#include<stdio.h>
#include<string.h>
using namespace std;
char origin[30];
void encrypt(char *p);
void decrypt(char *p);
int main()
{	
	int f;
	printf("please press phrase\n") ;
	scanf("%s",origin) ;
	printf("press 1 for encrypt or 0 for decrypt %d\n");
	scanf("%d",&f);
	if (f)
	{
		encrypt(origin);
		puts(origin);
	}
	else 
	{
		decrypt(origin);
		puts(origin);
	}
	return 0;
}
void encrypt(char *p)
{
	int n=strlen(p);
	for(int i=0;i<n;++i)
		{
			*p=((*p-'a'+5)%26+'a'); 
			++p;
		}
}
void decrypt(char *p)
{
 	int n=strlen(p);
	for(int i=0;i<n;++i)
		{
			*p=((*p-'a'+21)%26+'a');
			++p;
		}
}
