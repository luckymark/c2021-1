#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int main(){
	cout<<"������һ�����Ȳ�����50���ַ���:"<<endl;
	char ch[100];
	gets(ch);
	int len=strlen(ch);
	for(int i=0;i<len;i++){
	if(ch[i]>='a'&&ch[i]<='z'||ch[i]>='A'&&ch[i]<='Z'){
	if(ch[i]>='a'&&ch[i]<='z'&&ch[i]+3>'z'
	  ||ch[i]>='A'&&ch[i]<='Z'&&ch[i]+3>'Z') ch[i]=ch[i]-23;
	else ch[i]=ch[i]+3;
	   } 
	} 
    cout<<"���ܺ�"<<ch;
	return 0;
}
