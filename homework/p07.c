#include<stdio.h>
#include<string.h>
void jiami(char* p,int l) {
	for (int i = 0; i < l; i++) {
		p[i]++;
	}
}
void jiemi(char* p, int l) {
	for (int i = 0; i < l; i++) {
		p[i]--;
	}
}
int main() {
	char s[10000];
	int l;
	gets(s);
	l = strlen(s);
	jiami(s, l);
	printf("%s\n", s);
	jiemi(s, l);
	printf("%s", s);
	return 0;
}