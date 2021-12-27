#include<stdio.h>
#include<math.h>
int check(int n){
	int i;
	if(!(n%2))
		return 0;
	else{
		for(i=2;i<=(int)(sqrt(n));i++){
			if(!(n%i))
				return 0;
		} 
	}
	return 1;
} 
void Goldbach(int n){
	int i,j;
	for(i=3;i<n-2;i++){
		for(j=i;j<n-2;j++){
			if((i+j==n)&&check(i)&&check(j)){
				printf("%d %d\n",i,j);
			}
		}
	}
}
int main(){
	int n;
	printf("请输入一个大于等于6的偶数\n");
	scanf("%d",&n);
	if(n%2)
		printf("请重新输入一个正确的数\n");
	else
		Goldbach(n);
	return 0; 
} 
