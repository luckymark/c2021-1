#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
bool check(int x){//ÊÇ·ñÎªËØÊı 
	for(int j=2;j*j<=x;j++){
		if(x%j==0) return 0;
	} 
	return 1;
}
void find(int x){
	
}
int main(){
	for(int i=2;i<=100;i+=2){
		find(i);
	}
	return 0;
} 
