#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<windows.h>

#define MAXN 15
#define KEY_PRESSED(KEY_ID) GetAsyncKeyState(KEY_ID)&32768?1:0

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) {int T=x; x=y; y=T;}
#define wipe(x,y) memset(x,y,sizeof(x))
#define rep(x,y,z) for(int x=y,I=z;x<=I;++x)

char G[MAXN+3][MAXN+3]={
	"",
	" ###############",
	" #           ###",
	" ### ####### ###",
	" ### ####### ###",
	" ###     ###   #",
	" ### ####### # #",
	" ### ### ##### #",
	" ###           #",
	" ####### ### ###",
	" ##      ### ###",
	" #  #### ### ###",
	" # ##    ### ###",
	" # ## ##########",
	" ####           ",
	" ######## ######",
};

int CurX=2;
int CurY=2;
int KeyStat;

void PrintGraph();
int GetCurrentKey();
bool isBarrier(int X,int Y);
bool isEscaped(int X,int Y);

int main(){
	PrintGraph();
	while(1){
		KeyStat=GetCurrentKey();
		switch(KeyStat){
			case VK_UP:
				if(isBarrier(CurX-1,CurY))
					CurX--;
				break;
			case VK_DOWN:
				if(isBarrier(CurX+1,CurY))
					CurX++;
				break;
			case VK_LEFT:
				if(isBarrier(CurX,CurY-1))
					CurY--;
				break;
			case VK_RIGHT:
				if(isBarrier(CurX,CurY+1))
					CurY++;
				break;
			default:
				break;
		}
		if(KeyStat){
			PrintGraph();
			Sleep(80);
		}
		if(isEscaped(CurX,CurY)){
			printf("You Win!\n");
			return 0;
		}
	}
	return 0;
}

void PrintGraph(){
	system("cls");
	rep(i,1,MAXN){
		rep(j,1,MAXN){
			if(i==CurX && j==CurY)
				putchar('*');
			else
				putchar(G[i][j]);
		}
		putchar('\n');
	}
}

int GetCurrentKey(){
	if(KEY_PRESSED(VK_UP))
		return VK_UP;
	if(KEY_PRESSED(VK_DOWN))
		return VK_DOWN;
	if(KEY_PRESSED(VK_LEFT))
		return VK_LEFT;
	if(KEY_PRESSED(VK_RIGHT))
		return VK_RIGHT;
	return 0;
}

bool isBarrier(int X,int Y){
	if(G[X][Y]=='#')
		return false;
	return true;
}

bool isEscaped(int X,int Y){
	if(X<2 || X>15)
		return true;
	if(Y<2 || Y>15)
		return true;
	return false;
}
