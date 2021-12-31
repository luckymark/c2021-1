#include<stdio.h> 
int main(int argc,char *argv[]){
int a,b;
printf("请输入需要判断的数：");
scanf("%d,&a");
if(a>0)
{b=1;
}
 else if(a=0)
 {b=0;
 }
 else if(a<0)
{b=-1;
}
printf("输出\n-1,则小于0;\n0,则等于零;\n1则大于0;\n输出为:%d",b);
return 0;
}
