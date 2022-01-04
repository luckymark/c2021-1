#include <stdio.h>
#include "pushBoxes.h"

int main() {
	char choice;
	printf("Input 'y' to start('n' to quit):");
	scanf_s("%c", &choice, 1);
	if (choice == 'y') {
		system("cls");
		pMap p = (pMap)malloc(sizeof(Map));
		char* path = "C:\\Users\\24962\\Repository\\c2021-1\\level1\\p10_pushBoxes\\map";
		char* tail = ".txt";
		int i = 1;
		int lenth = sizeof(char) * (strlen(path) + strlen(tail) + 2);
		char* newPath = (char*)malloc(lenth);
		sprintf_s(newPath, lenth, "%s%d%s", path, i, tail);
		while (i <= 3) {
			
			load(newPath, p);
			display(p);
			play(p);
			printf("\nYou win!\n");
			printf("Input 'y' to continue('n' to quit):\n");
			scanf_s("%*[^\n]%*c", &choice, 1);
			if (choice == 'n')break;
			if (choice == 'y') {
				system("cls");
				i += 1;
				sprintf_s(newPath, lenth, "%s%d%s", path, i, tail);
			}
		}
	}
	return 0;
}
