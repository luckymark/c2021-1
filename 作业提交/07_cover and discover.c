#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define argot "I am the **** of the world!" 
void cover(char*p, int l) {
	for(; l >= 0; l--) {
		p[l-1]--;
	}
}

void discover(char*p, int l) {
	for(; l >= 0; l--) {
		p[l-1]++;
	}
}

int main() {
	int l = strlen(argot);
	char string[1000] = argot;
	cover(string, l);
	printf("%s\n", string);
	discover(string, l);
	printf("%s\n", string);
	return 0;
}
