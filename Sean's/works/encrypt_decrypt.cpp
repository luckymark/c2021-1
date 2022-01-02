#include<cstdio>
using namespace std;

const int key = 5;
const int MOD = 128;
const int MAX = 1e6 + 1;

int len,option;
char str[MAX],New[MAX];

void encrypt(char str[]) {
	for (int i = 1; i <= len; ++i) {
		str[i] = (char)(((int)str[i] + key)%MOD+1);
		printf("%c",str[i]);
	}
	return;
}

void decrypt(char str[]) {
	for (int i = 1; i <= len; ++i) {
		str[i] = (char)(((int)str[i] + key)%MOD+1);
		printf("%c", str[i]);
	}
	return;
}

int main()
{
	printf("Please input one choice:\n");
	printf("1:encrypt\n");
	printf("2:decrypt\n");
	scanf_s("%d", &option);
	printf("Please input the string:\n");
	getchar();
	while (str[++len] = getchar()) 
		if (str[len] == '\n') {
			--len;
			break;
		}
	if (option == 1) encrypt(str);
	else decrypt(str);
	return 0;
}//sunxiaorui