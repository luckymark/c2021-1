#include<stdio.h>
#include<stdlib.h>

int main() {
	char code[10],password[10];
	gets_s(code);
	for (int i = 0; i < 10; i++) {
		if (code[i] != 'z')
			code[i] += 1;
		else if (code[i] == 'z')
			code[i] = 'a';
	}
	printf("%s", code);
	system("pause");
	gets_s(password);
	for (int j = 0; j < 10; j++) {
		if (password[j] != 'a')
			password[j] -= 1;
		else if (password[j] == 'a')password[j] = 'z';
		}
	printf("%s", password);
	system("pause");
	return 0;
}