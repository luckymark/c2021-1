/*
 * @Author: your name
 * @Date: 2021-09-06 20:22:55
 * @LastEditTime: 2021-10-25 19:26:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\VScode_c\level1\p01.cpp
 */
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <cstdlib>

using namespace std;

int main(){
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
	int n = 1;
	int c = 1;
	while(1){
		
		for (int j = 1; j <= abs(n); j++) printf(" ");
		printf("%c", c == 1 ? '>':'<');
		system("cls");
		n += c;
		if (abs(n) == cx) c = -c;
	}
	return 0;
}
