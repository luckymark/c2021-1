#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a='a';
    int m=0;
	int n=0;
    for (;n<120;n++){
    	printf("%*c",n,a);
       m++;
    system ("cls");
};
    for (;m>0;m--){
    	printf("%*d",m,a);
    	system ("cls");
    	Sleep(50);
    	
    }
		 return 0;
}
