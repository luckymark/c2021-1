#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
const int dox[5] = {0,-1,1,0,0},doy[5] = {0,0,0,-1,1};
int sum = 0,a[12][12] = {0},x1 = 0,x2 = 0;

int end () {
    int sum0 = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j <= 11; j++) {
            if (a[i][j] == 2) { sum0++; }
        }
    }
    if (sum0 == 0) { return 1; }
    else { return 0; }
}

void draw () {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            switch (a[i][j]) {
                case -1:
                    cout << "#";
                    break;
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << "@";
                    break;
                case 2:
                    cout << "Q";
                    break;
                case -2:
                    cout << "T";
                    break;
            }
        }
        cout << endl;
    }
}

int panduan (char n) {
    switch (n) {
        case 'a':
        case 'A':
            return 3;
        case 's':
        case 'S':
            return 2;
        case 'D':
        case 'd':
            return 4;
        case 'W':
        case 'w':
            return 1;
    }
}

void move (int dd) {
    if ((a[x1 + dox[dd] * 2][x2 + doy[dd]] * 2 == -1) || (x1 + dox[dd] * 2 < 0) || (x1 + dox[dd] * 2 > 11) ||
        (x2 + dox[dd] * 2 > 11) || (x2 + dox[dd] * 2 < 0) || (a[x1 + dox[dd]][x2 + doy[dd]] == -1) ||
        (a[x1 + dox[dd]][x2 + doy[dd]] == 1)) {
        cout << "you can't do this" << endl;
    }
    else {
        if (a[x1 + dox[dd]][x2 + doy[dd]] == 2) {
            if (a[x1 + dox[dd] * 2][x2 + doy[dd] * 2] == -1) {
                cout << "error" << endl
                     << "restart";
            }
            if (a[x1 + dox[dd] * 2][x2 + doy[dd] * 2] == 1) {
                a[x1][x2] = 0;
                x1 = x1 + dox[dd];
                x2 = x2 + doy[dd];
                a[x1][x2] = -2;
                a[x1 + dox[dd]][x2 + doy[dd]] = 0;
            }
            else if (a[x1 + dox[dd] * 2][x2 + doy[dd] * 2] == 0) {
                a[x1][x2] = 0;
                x1 = x1 + dox[dd];
                x2 = x2 + doy[dd];
                a[x1][x2] = -2;
                a[x1 + dox[dd]][x2 + doy[dd]] = 2;
            }
        }
        else {
            a[x1][x2] = 0;
            x1 = x1 + dox[dd];
            x2 = x2 + doy[dd];
            a[x1][x2] = -2;
        }
        sum++;
    }
    if (end() == 1) {
        cout << "恭喜你到达了终点!" << endl;
        cout << "你的分数是：" << sum;
    }
}

int main () {
    char n;
    ifstream fp("C:\\clion-kit\\pushbox\\guanka1.txt",ios::in);
    for (int i = 0; i <= 11; i++) {
        fp >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5] >> a[i][6] >> a[i][7] >> a[i][8] >> a[i][9]
           >> a[i][10] >> a[i][11];
    }
    fp.close();
    cout << "这是12*12的推箱子" << endl;
    cout << "#号是墙体,@是坑，Q是箱子，T是小人" << endl;
    cout << "按A,S,D,W控制小人移动" << endl;
    system("pause");
    draw();
    while (true) {
        cin.get(n);
        cin.get();
        int i = panduan(n);
        move(i);
        if (end() == 1) {
            ofstream fp;
            fp.open("C:\\clion-kit\\pushbox\\guanka1.txt",ios::app);
            fp << sum;
            fp.close();
            break;
        }
        else {
            draw();
        }
    }
    return 0;
}