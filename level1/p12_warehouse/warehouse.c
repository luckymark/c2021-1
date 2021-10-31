#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE* storage;

void printMenu();
void mainCycle();
void showList();
void putIn();
void putOut();

int main() {
    fopen_s(&storage, "storage.dat", "r+");
    mainCycle();

    return 0;
}

void printMenu() {
    system("cls");
    printf("########################### STORAGE MENU ###########################\n");
    printf("#                                                                  #\n");
    printf("#     1 .SHOW GOODS-LIST                                           #\n");
    printf("#     2 .STOCK IN                                                  #\n");
    printf("#     3 .STOCK OUT                                                 #\n");
    printf("#                                                                  #\n");
    printf("#     4 .EXIT                                                      #\n");
    printf("#                                                                  #\n");
    printf("####################################################################\n");
}

void mainCycle() {
    while (1) {
        printMenu();
        int input;
        if (!scanf_s("%d", &input)) {
            printf("Error:Invalid input.\n");
            for (char ch = getchar(); ch != '\n';) {
                ch = getchar();
            }
        }
        else {
            switch (input) {
                case 1:
                    showList();
                    break;
                case 2:
                    putIn();
                    break;
                case 3:
                    putOut();
                    break;
                case 4:
                    fclose(storage);
                    exit(0);

                default:
                    printf("Error:Invalid number.");
                    break;
            }
        }
    }

}

void showList() {
    int number, i = 1;
    char name[20];
    system("cls");
    fseek(storage, 0, SEEK_SET);
    while (fscanf_s(storage, "%d,%[a-z A-Z]", &number, name, 19) == 2) {
        printf("GOOD %d : %-20s NUMBER:%d\n", i++, name, number);
    }
    printf("\nPress any key to continue.");
    getchar();
    getchar();
}

void putIn() {
    int amount;
    unsigned int add;
    char name[20] = {'\0'};
    char toName[20] = {'\0'};
    long offset=0;
    system("cls");
    fseek(storage, 0, SEEK_SET);
    printf("Please put in the name of the goods\n");
    getchar();
    if (!scanf_s("%[a-z A-Z]", toName, 19)) {
        printf("Invalid input.");
        return;
    }
    printf("Please input the amount of the new goods.\n");
    if (!scanf_s("%ud", &add)) {
        printf("Invalid input.\n");
        return;
    }
    getchar();
    while (fscanf_s(storage, "%d,%[a-z A-Z]", &amount, name, 19) == 2) {
        if (!strcmp(name, toName)) {
            fseek(storage, offset, SEEK_SET);
            fprintf(storage,"%12d,%s", amount + add, name);
            return;
        }
        offset += 14+strlen(name);
    }
    fprintf(storage,"%12d,%s\n", add, toName);
    return;
}

void putOut() {
    int amount;
    unsigned int add;
    char name[20] = {'\0'};
    char toName[20] = {'\0'};
    long offset=0;
    system("cls");
    fseek(storage, 0, SEEK_SET);
    printf("Please put in the name of the goods\n");
    getchar();
    if (!scanf_s("%[a-z A-Z]", toName, 19)) {
        printf("Invalid input.");
        return;
    }
    printf("Please input the amount of the goods.\n");
    if (!scanf_s("%ud", &add)) {
        printf("Invalid input.\n");
        return;
    }
    getchar();
    while (fscanf_s(storage, "%d,%[a-z A-Z]", &amount, name, 19) == 2) {
        if (!strcmp(name, toName) && amount>=add) {
            fseek(storage, offset, SEEK_SET);
            fprintf(storage,"%12d,%s", amount - add, name);
            return;
        }
        offset += 14+strlen(name);
    }
    printf("No that good.");
    return;
}