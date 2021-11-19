#include<stdio.h>
#include<string.h>
void encrypt(char p[],char p_1[]);
void decode(char n[],char n_1[]);
void encrypt(char p[],char p_1[]){
	int i =0;
	
	for (i = 0;p[i]!=0; i++) {
		
	
			p_1[i] = p[i] + 1;
	

	}
	
	
	}
void decode(char n[],char n_1[]) {
	int i = 0;
	for (i = 0; n[i] != 0; i++) {
		
			
		
		
			n_1[i] = n[i] - 1;
		

	}
	
	


}
int main() {
	char a[200] = { '\0' }; char a_1[200] = {'\0'};
	printf("需要加密的密文：");
	scanf("%s", a);
	 encrypt(a, a_1);
	printf("\n");
	printf("加密后的密文：%s", a_1);
	char b[200] = { '\0' }; char b_1[200] = {'\0'};
   printf("需要解密的密文：");
   scanf_s("%s", b,6);
   printf("\n");
   decode(b, b_1);
	   printf("解密后的密文：%s", b_1);


}