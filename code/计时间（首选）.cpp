#include<iostream>
#include<ctime>
using namespace std;
int main() {
	clock_t st, et;
	st = clock();
	for(int i=0;i<10000000;i++)
	et = clock();
	cout << "����ʱ��Ϊ"<<(double)(et - st) / CLOCKS_PER_SEC <<"ms"<< endl;


	return 0; 
}
