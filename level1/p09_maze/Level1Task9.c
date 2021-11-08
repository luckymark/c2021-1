#include<bits\stdc++.h>
#include<windows.h>
#include<conio.h>
#define ML 24
int Rank=0,npos[2],aim[2];
int **Maze=(int**)malloc(ML*sizeof(int*));
char direct;
void CreateMaze(int **maze,int x,int y);
void PrintMaze(int **maze);
void goto_xy(int x,int y);
bool judge(int x,int y);
void HideCursor();
void control();
int main(){
    srand((unsigned)time(NULL));
    for(int i=0;i<ML;i++){
        Maze[i]=(int*)calloc(ML,sizeof(int));
    }
    for(int i=0;i<ML;i++){
        Maze[i][ML-1]=1;
		Maze[ML-1][i]=1;
		Maze[i][0]=1;
		Maze[0][i]=1;
    }
    CreateMaze(Maze,2,2);
    Maze[2][1]=1;
    for (int i=ML-3;i>=0;i--){
		if (Maze[i][ML-3]==1){
			Maze[i][ML-2]=1;
            aim[0]=i;
            aim[1]=ML-2;
			break;
		}
	}
    Maze[1][1]=0;
    PrintMaze(Maze);
    goto_xy(2,1);
    printf("s");
    goto_xy(2,1);
    HideCursor();
    control();
    system("pause");
    return 0;
}
void CreateMaze(int **maze,int x,int y){
    maze[x][y] = 1;
	int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	for(int i = 0; i < 4; i++){
		int r=rand()%4;
		std::swap(direction[i][0],direction[r][0]);
        std::swap(direction[i][1],direction[r][1]);
	}
	for(int i=0;i<4;i++){
		int dx=x;
		int dy=y;
		int range=1+(Rank == 0 ? 0 : rand()%Rank);
		while(range>0){
			dx+=direction[i][0];
			dy+=direction[i][1];
			if(maze[dx][dy]==1){
				break;
			}
			int count=0;
			for(int j=dx-1;j<dx+2;j++){
				for(int k=dy-1;k<dy+2;k++){
					if(abs(j-dx)+abs(k-dy)==1&&maze[j][k]==1){
						count++;
					}
				}
			}
			if(count>1){
				break;
			}
			--range;
			maze[dx][dy]=1;
		}
		if(range<=0){
			CreateMaze(maze,dx,dy);
		}
	}
}
void PrintMaze(int **maze){
	for (int i=0;i<ML;++i){
		for (int j=0;j<ML;++j){
			goto_xy(i,j);
            if(maze[i][j]==1){
				std::cout<<" ";
			}
			else{
				std::cout<<"O";
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
void goto_xy(int x,int y){
    npos[0]=x;
    npos[1]=y;
    handle_t hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={(short int)x,(short int)y};
    SetConsoleCursorPosition(hOut,pos);
}
void HideCursor() 
{
	handle_t hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);
}
bool judge(int x,int y){
    if(x==aim[0]&&y==aim[1]){
        system("CLS");
        printf("Congratulations to your successful completion!\n");
        return true;
    }
    else{
        return false;
    }
}
void control(){
    while(1){
	    if (_kbhit)
	    {
	    	fflush(stdin);
	    	direct = _getch();
	    }
        int xx,yy;
        handle_t hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hOut,&csbi);
	    xx=csbi.dwCursorPosition.X;
	    yy=csbi.dwCursorPosition.Y;
	    goto_xy(xx,yy);
	    printf(" ");
        goto_xy(xx,yy);
	    switch(direct)
	    {
	    case 'W':
	    case 'w':
	    	if(yy>1&&Maze[xx][yy-1]) yy--;
            break;
	    case 'S':
	    case 's':
	    	if(yy<ML-1&&Maze[xx][yy+1]) yy++;
            break;
	    case 'A':
	    case 'a':
	    	if(xx>1&&Maze[xx-1][yy]) xx--;
            break;
	    case 'D':
	    case 'd':
	    	if(xx<ML-1&&Maze[xx+1][yy]) xx++;
            break;
        default:
            break;
	    }
	    goto_xy(xx,yy);
	    printf("s");
        goto_xy(xx,yy);
        if(judge(xx,yy)){
            break;
        }
    }
}