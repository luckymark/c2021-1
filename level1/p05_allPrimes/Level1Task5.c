#include<bits\stdc++.h>
int main(){
    clock_t start,end;
    start=clock();
    bool num[1001];
    memset(num,0,sizeof(num));
    for(int i=2;i<=32;i++){
        if(!num[i])
        {
            for(int j=2;i*j<=1000;j++)
                num[i*j]=true;
        }
    }
    for(int i=2;i<=1000;i++)
        if(!num[i]) printf("%-6d",i);
    printf("\n");
    end=clock();
    printf("It takes %lfs to run this program.\n",double(end-start)/CLOCKS_PER_SEC);
    system("pause");
    return 0;
}