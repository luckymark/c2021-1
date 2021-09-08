//Based on Caesar cipher

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;
void encrypt(){
	int n = s.size();
	for (int i = 0; i < n; i++) s[i] = ((s[i] - 'a') + 5) % 26 + 'a';
}
void decrypt(){
	int n = s.size();
	for (int i = 0; i < n; i++) s[i] = ((s[i] - 'a') - 5 + 26) % 26 + 'a';
}

int main(){
	
	while (1){
		printf("Please input s\n");
		cin >> s;
		
		printf("Please press: 1 for encrypt or 0 for decrypt\n");
		int type;
		scanf("%d", &type);
		if (type) encrypt();
		else decrypt();
		
		cout << s << endl;
	}
	return 0;
}
