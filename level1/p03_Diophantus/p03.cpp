/*
 * @Author: your name
 * @Date: 2021-09-08 23:25:33
 * @LastEditTime: 2021-10-25 19:45:02
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\VScode_c\level1\p03.cpp
 */
#include <cstdio>
#include <string>
using namespace std;

const int MAX_Age = 9999;
bool is_rightAge(int x){
	if ((x % 12) || (x % 7)) return false;
	else return (x / 12 + x / 6 + x / 7 + 5 + x / 2 + 4 == x);
}
int main(){
	for (int i = 1; i <= MAX_Age; i++) if (is_rightAge(i)){
		printf("Diophantus was at the age of %d when his son died\n", i - 4);
		break;
	}
	return 0;
}
