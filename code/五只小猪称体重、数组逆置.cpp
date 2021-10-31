#include<iostream>
using namespace std;
int main() {
	/*int arr[5]= { 300,350,200,100,250 };
	int max= 0;
	for (int i = 0;i < 5;i++) {
		max = max > arr[i] ? max : arr[i];
	}
	cout << max;*/  //五只小猪称体重
	
	int arr[5] = { 1,2,3,4,5 };
	int ed1= sizeof(arr) / sizeof(arr[0]);
	for (int q = 0;q < ed1;q++) {
		cout << arr[q] << " ";
	}
	cout << endl;
	int ed2 = sizeof(arr) / sizeof(arr[0])-1;
	for (int st = 0;st < ed2;st++,ed2--) {
		int temp = arr[st]; arr[st] = arr[ed2]; arr[ed2] = temp;	
	}
	for (int q = 0;q < ed1;q++) {
		cout << arr[q] << " ";
	}  //数组逆置
	return 0;
} 
