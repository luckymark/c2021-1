#include<iostream>
using namespace std;

int main() {
	for (double i = 1;i > 0;i++) {
		if (2*(i/6+i/12+i/7)+i+9-2*i==0) {
			cout << "������ʱ����ͼ" <<2*i-4<<"��";
		break;
		}
	}
	system("pause");
	return 0;
}
