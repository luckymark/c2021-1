#include<stdio.h> 
int main(int argc,char *argv[]){
int a,b;
printf("��������Ҫ�жϵ�����");
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
printf("���\n-1,��С��0;\n0,�������;\n1�����0;\n���Ϊ:%d",b);
return 0;
}
