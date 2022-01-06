#include<bits\stdc++.h>
int main(){
    double f=30,s;
    while(f<=100){
        f++;
        s=f/2;
        if(s+4+5+f*11/28==f){ 
            printf("%.0lf\n",f-4);
            break;
        }
    }
    system("pause");
    return 0;
}