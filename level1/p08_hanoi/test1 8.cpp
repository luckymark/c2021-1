#include <stdio.h>
int i;
void h(int n,char a,char b,char c){
    
   
    if (n==1){

        printf ("第%d步：%c->%c\n",++i,a,c);
        
    }
    else {
        h(n-1,a,c,b);
        printf("第%d步：%c->%c\n",++i,a,c);
    
        h(n-1,b,a,c);
    }
}
int main (){
    int n;
    int i=0;
   
    scanf("%d",&n);
    char a='a';
    char b='b';
    char c='c';
    h(n,a,b,c);
}

