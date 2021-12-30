#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int main(){
	cout<<"请输入一个长度不大于50的字符串:"<<endl;
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
    cout<<"加密后："<<ch;
	return 0;
}
