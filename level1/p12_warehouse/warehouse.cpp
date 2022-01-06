#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int num;
struct warehouse {
    int size=0;
    int mount=0;
}pro[100];
int writein () {
    int i = 0,x,y;
    ifstream fp("C:\\clion-kit\\warehouse\\program.txt",ios::in);
    while (fp >> x >> y) {
        pro[i + 1].size = x;
        pro[i + 1].mount = y;
        i++;
    }
    fp.close();
    return i;
}

void show () {
    int i=writein();
    for (int i = 1; i <= num; i++) {
        cout << pro[i].size << "    " << pro[i].mount << endl;
    }
    system("pause");
}

void inp () {
    int x,y;
    cout << "请按照型号(1，2，3表示小，中，大),数量的顺序输入" << endl;
    cin >> x >> y;

    ofstream fp;
    fp.open("C:\\clion-kit\\warehouse\\program.txt",ios::app);
    fp << x << " " << y << endl;
    fp.close();

    num++;
}

void outp () {
    int del;
    cout << "现在共有" << num << "行" << endl;
    cout << "请输入需要取出的物品（第几行）" << endl;
    cin >> del;
    int t=writein();

    ofstream fp;
    fp.open("C:\\clion-kit\\warehouse\\program.txt",ios::trunc);
    fp.close();

    ofstream fp1;
    fp1.open("C:\\clion-kit\\warehouse\\program.txt",ios::app);
    for (int i = 1; i <= num; i++)
        if (i!=del) fp1 << pro[i].size << " " << pro[i].mount<<endl;
    fp1.close();

    num--;
}

int main () {
    int n;
    num = writein();
    cout << "*********************" << endl;
    cout << "*    1.显示存货列表   *" << endl;
    cout << "*       2.入库       *" << endl;
    cout << "*       3.出库       *" << endl;
    cout << "*     4.退出程序      *" << endl;
    cout << "*********************" << endl;
    while (1) {
        cin >> n;
        system("cls");
        switch (n) {
            case 1:
                show();
                break;
            case 2:
                inp();
                break;
            case 3:
                outp();
                break;
            case 4:
                return 0;
            default:
                cout << "error" << endl;
                break;
        }
        cout << "*********************" << endl;
        cout << "*    1.显示存货列表   *" << endl;
        cout << "*       2.入库       *" << endl;
        cout << "*       3.出库       *" << endl;
        cout << "*     4.退出程序      *" << endl;
        cout << "*********************" << endl;
    }
}
