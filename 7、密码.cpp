#include<cstdio>
#include<cstring>
#define maxn 500005
using namespace std;

void jiami(char a[])
{
	int len=strlen(a);
	char b[maxn];
	for(int i=0;i<len;++i)
	{
		if(a[i]>='0'&&a[i]<='9')//����
		{
			b[i]=a[i]+3;
			if(b[i]>'9')
			b[i]=b[i]-'9'+'0'-1;
		}
		if(a[i]>='a'&&a[i]<='z')//Сд��ĸ
		{
			b[i]=a[i]+4;
			if(b[i]>'z')
			b[i]=b[i]-'z'+'a'-1;
		}
		if(a[i]>='A'&&a[i]<='Z')//��д��ĸ
		{
			b[i]=a[i]+5;
			if(b[i]>'Z')
			b[i]=b[i]-'Z'+'A'-1;
		}
	}
	puts(b);
}

void jiemi(char a[])
{
	int len=strlen(a);
	char b[maxn];
	for(int i=0;i<len;++i)
	{
		if(a[i]>='0'&&a[i]<='9')//����
		{
			b[i]=a[i]-3;
			if(b[i]<'0')
			b[i]=b[i]+'9'-'0'+1;
		}
		if(a[i]>='a'&&a[i]<='z')//Сд��ĸ
		{
			b[i]=a[i]-4;
			if(b[i]<'a')
			b[i]=b[i]+'z'-'a'+1;
		}
		if(a[i]>='A'&&a[i]<='Z')//��д��ĸ
		{
			b[i]=a[i]-5;
			if(b[i]<'A')
			b[i]=b[i]+'Z'-'A'+1;
		}
	}
	puts(b);
}

int main()
{
	int op;
	char s[maxn];
	scanf("%d",&op);
	getchar();
	gets(s);
	if(op==1)//����
	jiami(s);
	if(op==2)//����
	jiemi(s);
	return 0;
}