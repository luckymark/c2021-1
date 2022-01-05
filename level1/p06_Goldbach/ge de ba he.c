#include <stdio.h>

int thenumberofzhishu(int x)
{
    int i,a,b;
    b=0;
    for(i=2;i<=100;i++)
    {
        for(a=2;a<i;a++)
        {
            if(i%a==0)
            {
                b++;
                break;
            }
        }
    }
    return x-b-1;
}

void zhishulie(int p[])
{
    int i,a,b,c;
    b=0;c=0;
    for(i=2;i<=100;i++)
    {
        for(a=2;a<i;a++)
        {
            if(i%a==0)
            {   b++;
                break;
            }
        }
        if(b==0)
        {   p[c++]=i;
        }else{b--;}
    }
}
void zhengming(int p[],int y)
{
    int even,count1=0,count2=0;
    int *pb,*pc;
    pb=&p[0];pc=&p[0];
    for(even=4; even <= 100; even+=2)
    {
        for(int i=0;i<=y-1;i++)
        {for(int j=0;j<=y-1;j++)
            {if(even==(*pb)+(*pc))
                {count1++;
                break;}
                else{pc++;}
            }
         if(count1==count2)
            {pb++;
            pc=&p[0];}
         else{pb=&p[0];pc=&p[0];
              break;}
        }
        if(count1!=count2)
            {
                count2++;
            }

    }
    if(count1==49)
    {printf("ge de ba he cai xiang cheng li\n");}
    else{printf("ge de ba he cai xiang bu cheng li\n");}

}

int main() {
    int y=thenumberofzhishu(100);
    int pt[y];
    zhishulie(pt);
    zhengming(pt,y);

    return 0;
}
