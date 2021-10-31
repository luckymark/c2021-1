#include<iostream>  
#include<Windows.h>  

using namespace std;

int main()
{
	double st = GetTickCount();
	for (int i = 0; i < 100000000; i++)
	{
		i++;
	}
	double et = GetTickCount();
	cout << "running time=" << (et - st) << "ms!" << endl;
	system("pause");
	return 0;
}
