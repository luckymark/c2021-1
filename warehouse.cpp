#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int choise;
int input;
void menu() {
	printf("---------------欢迎使用进销存管理系统---------------\n");
	printf("|----------------请根据需求输入数字----------------|\n");
	printf("|------------------1.显示存货列表------------------|\n");
	printf("|------------------2.入库（总数小于100） ----------|\n");
	printf("|------------------3.出库（总数小于100） ----------|\n");
	printf("|------------------4.退出        ------------------|\n");
    scanf_s("%d", &choise);
}
void ware() {
    printf("---------------欢迎使用进销存管理系统---------------\n");
    printf("|----------------请根据商品输入数字----------------|\n");
    printf("|------------------1.Calculus     -----------------|\n");
    printf("|------------------2.University Physics -----------|\n");
    printf("|------------------3.discrete mathematics ---------|\n");
    printf("|------------------4.Linear algebra  --------------|\n");
    printf("|------------------5.exit            --------------|\n");
    scanf_s("%d", &input);
}
void show(){
    char buffer[256];
    ifstream in("out.txt");
    if (!in.is_open())
    {
        cout << "Error opening file"; exit(1);
    }
    while (!in.eof())
    {
        in.getline(buffer, 100);
        cout << buffer << endl;
    }
}
int main() {
    bool flat = 1;
    while (flat == 1) {
        system("cls");
        menu();
            system("cls");
            switch (choise) {
            case 1:show();
                system("pause");
                break;
            case 2:ware();
                if (input == 4) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(112, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 1) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(26, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 2) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(55, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 3) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(87, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 5) {
                    choise = 1;
                    flat = 0;
                }
                break;
            case 3:
                ware();
                if (input == 4) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(112, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 1) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(26, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 2) {
                    system("cls");
                    printf("请输最终货量:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(55, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 3) {
                    system("cls");
                    printf("请输入进货数:");
                    char nums[4];
                    scanf_s("%s", nums, 4);
                    fstream fs("out.txt", ios::binary | ios::out | ios::in);
                    fs.seekp(87, ios::beg);
                    fs.write(nums, sizeof(nums));
                    fs.close();
                }
                else if (input == 5) {
                    choise = 1;
                    flat = 0;
                }
                break;
            case 4:
                flat = 0;
                break;
        }
    }
    return 0;
}