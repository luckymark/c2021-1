#include<iostream>
using namespace std;
int hahaha(int j) {
	for (int i = 2;i < j;i++) {
		if (j%i == 0) return 0;
		else return 1;
	}
}
int main() {
	cout<<"������һ������2��ż����"; 
	int a; cin >> a;
    for (int b = 2;b < a;b++) {
		if ((hahaha(b) == 1)) {
			for (int c = 2;c < a;c++) {
				if ((hahaha(c) == 1) && a == b + c)  cout << a << "=" << b << "+" << c<<endl;
			}
		}
    }
	return 0;
}
