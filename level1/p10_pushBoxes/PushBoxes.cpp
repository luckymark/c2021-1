#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<windows.h>

#define MAXN 30
#define KEY_PRESSED(KEY_ID) GetAsyncKeyState(KEY_ID)&32768?1:0

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) {int T=x; x=y; y=T;}
#define wipe(x,y) memset(x,y,sizeof(x))
#define rep(x,y,z) for(int x=y,I=z;x<=I;++x)

using namespace std;

char G[MAXN+3][MAXN+3];

vector<int>score;

bool Moved;

int N;
int T;
int CN;
int CM;
int Step;
int CurX;
int CurY;
int Boxes;
int Finished;
int KeyStat;

void Init();
void PrintGraph();
int GetCurrentKey();
bool isBox(int X,int Y);
bool isExit(int X,int Y);
bool isBarrier(int X,int Y);
bool isEscaped(int X,int Y);

int main(){
	freopen("Mapp.txt","r+",stdin);
	scanf("%d",&N);
	while(N--){
		T++;
		Init();
		PrintGraph();
		while(1){
			Moved=0;
			KeyStat=GetCurrentKey();
			switch(KeyStat){
				case VK_UP:
					if(isBarrier(CurX-1,CurY))
						CurX--,Moved=1;
					else if(isBox(CurX-1,CurY))
						if(isBarrier(CurX-2,CurY))
							G[CurX-1][CurY]=' ',G[CurX-2][CurY]='B',CurX--,Moved=1;
						else if(isExit(CurX-2,CurY))
							G[CurX-1][CurY]=' ',CurX--,Finished++,Moved=1;
					else
						Moved=0;
					break;
				case VK_DOWN:
					if(isBarrier(CurX+1,CurY))
						CurX++,Moved=1;
					else if(isBox(CurX+1,CurY))
						if(isBarrier(CurX+2,CurY))
							G[CurX+1][CurY]=' ',G[CurX+2][CurY]='B',CurX++,Moved=1;
						else if(isExit(CurX+2,CurY))
							G[CurX+1][CurY]=' ',CurX++,Finished++,Moved=1;
					else
						Moved=0;
					break;
				case VK_LEFT:
					if(isBarrier(CurX,CurY-1))
						CurY--,Moved=1;
					else if(isBox(CurX,CurY-1))
						if(isBarrier(CurX,CurY-2))
							G[CurX][CurY-1]=' ',G[CurX][CurY-2]='B',CurY--,Moved=1;
						else if(isExit(CurX,CurY-2))
							G[CurX][CurY-1]=' ',CurY--,Finished++,Moved=1;
					else
						Moved=0;
					break;
				case VK_RIGHT:
					if(isBarrier(CurX,CurY+1))
						CurY++,Moved=1;
					else if(isBox(CurX,CurY+1))
						if(isBarrier(CurX,CurY+2))
							G[CurX][CurY+1]=' ',G[CurX][CurY+2]='B',CurY++,Moved=1;
						else if(isExit(CurX,CurY+2))
							G[CurX][CurY+1]=' ',CurY++,Finished++,Moved=1;
					break;
				default:
					break;
			}
			if(KeyStat){
				PrintGraph();
				Sleep(80);
			}
			Step+=Moved;
			if(isEscaped(CurX,CurY)){
				system("cls");
				printf("You Win!\n%d Steps pressed\n",Step);
				score.push_back(Step);
				Sleep(1000);
				system("pause");
				break;
			}
		}
		system("cls");
	}
	freopen("Result.txt","w+",stdout);
	rep(i,1,T)
		printf("Game %d,Step:%d\n",i,score[i-1]);
	return 0;
}

void Init(){
	Step=0;
	CurX=2;
	CurY=2;
	Boxes=0;
	Finished=0;
	scanf("%d%d",&CN,&CM);
	wipe(G,0);
	rep(i,0,CN)
		gets(G[i]+1);
	rep(i,1,CN)
		rep(j,1,CM)
			Boxes+=isBox(i,j);
	return;
}

void PrintGraph(){
	system("cls");
	rep(i,1,CN){
		rep(j,1,CM){
			if(i==CurX && j==CurY)
				putchar('*');
			else
				putchar(G[i][j]);
		}
		putchar('\n');
	}
	printf("Game %d,%d Steps pressed\n",T,Step);
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
	return G[X][Y]==' ';
}

bool isExit(int X,int Y){
	return G[X][Y]=='E';
}

bool isBox(int X,int Y){
	return G[X][Y]=='B';
}

bool isEscaped(int X,int Y){
	return Finished==Boxes;
}
