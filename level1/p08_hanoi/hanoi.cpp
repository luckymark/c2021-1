#include<bits/stdc++.h>
using namespace std;
int n;
inline void dfs(int x,int st,int ed){
	if(x==3){
		printf("%c -> %c\n",st+'A',3-st-ed+'A');
		printf("%c -> %c\n",st+'A',ed+'A');
		printf("%c -> %c\n",3-st-ed+'A',ed+'A');
		return;
	}
	dfs(x-1,st,3-st-ed);
    printf("%c -> %c\n",st+'A',ed+'A');
    dfs(x-1,3-st-ed,ed);
}
int main(){
	scanf("%d",&n);
	dfs(n,0,2);
	return 0;
} 
