#include<bits\stdc++.h>
bool num[101];
void Goldbach(int x){
    for(int i=2;i*2<=x;i++)
        if(!num[i]&&!num[x-i]) printf("%d=%d+%d\n",x,i,x-i);
    return;
}
int main(){
    memset(num,0,sizeof(num));
    num[0]=num[1]=true;
    for(int i=2;i<=10;i++){
        if(!num[i])
        {
            for(int j=2;i*j<=100;j++)
                num[i*j]=true;
        }
    }
    for(int i=4;i<=100;i++)
    {
        if(num[i]) Goldbach(i);
    }
    system("pause");
    return 0;
}