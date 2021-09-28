#include<stdio.h>
#include<stdlib.h>
int main()
{char *a=0;
int i;
char *b;
//b=(char*)malloc()
scanf("%s",&a);
for(i=0;i<=strlen(a);i++)
{*(b+i)=*(a+i)+1;
}*(b+strlen(a)+1)='/0';
printf("%s",b);
return 0;

}
