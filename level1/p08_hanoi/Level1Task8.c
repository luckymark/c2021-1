#include<bits\stdc++.h>
void hanoi(int n,char x,char y,char z){//把n块通过柱子y从柱子x移动到柱子z
    if(n==1) printf("%c-->%c\n",x,z);
    else{
        hanoi(n-1,x,z,y);
        printf("%c-->%c\n",x,z);//打印：把第n块从柱子x移动到柱子z
        hanoi(n-1,y,x,z);
    }
    return;
}
int main(){
    int x;
    scanf("%d",&x);
    hanoi(x,'A','B','C');
    system("pause");
    return 0;
}