/*
 * @Author: chenyilin
 * @Date: 2021-09-10 19:17:44
 * @LastEditTime: 2021-09-10 21:49:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\VScode_c\level1\p09(dij).cpp
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <queue>
#include <cmath>
#include <conio.h>
#include <unistd.h>

using namespace std;

int N , M ;
const int MA = 100010;

int a[200][200], tmp[200][200];
const char type[8] = {'*', ' ', '&','>', '<', '|', 'S', 'E'};
void printMAP(){
    if (a[0][1] != 2) a[0][1] = 6;
    if (a[N - 1][M - 2] != 2) a[N - 1][M - 2] = 7;

    for (int i = 0;  i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%c", type[a[i][j]]);
        }
        printf("\n");
    }
}    
void reLoad(){
	system("cls");
	int t = 0;
	srand((unsigned)time(NULL));
	while (t < 100){
		system("cls");
		cout<<"\t*                loading. "<<t<< "%"<<"              *"<<endl;
		t += rand() % (101 - t);
		sleep(1);
	}
	
	
}

void createMAP(){
    memset(a, 0, sizeof(a));

    int max_Size = N * M, tx, ty;
	
	srand((unsigned)time(NULL));
    for (int i = 0; i < max_Size; i++){
        tx = rand() % (N - 2) + 1;
        ty = rand() % (M - 2) + 1;

        a[tx][ty] = 1;
    }

    a[0][1] = 2, a[N - 1][M - 2] = 1;
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int ask_S(int x, int y){
    if (x < 0 || y < 0) return -1;
    if (x >= N || y >= M) return -1;

    return x * N + y;
}


int nxt[MA], lst[MA], to[MA], cnt = 0;

void add(int f, int t){
    nxt[++cnt] = lst[f];
    lst[f] = cnt;
    to [cnt] = t;
}
void pre_DIJ(){
    memset(lst, 0, sizeof(lst));
    cnt = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (a[i][j]){
                int xx, yy, s1 = ask_S(i, j), s2;
                for (int k = 0; k < 4; k++){
                    xx = i + dx[k], yy = j + dy[k];
                    s2 = ask_S(xx, yy);
                    if (s2 == -1 || (!a[xx][yy])) continue;
                    
                    if(i == 9 && j == 8){
						cnt =cnt;
					}
                    add(s1, s2);
                }
            }
        }
    }
}
const int INF = 1 << 30;
int d[MA], pre_d[MA];

typedef pair<int, int> P;

int check(){
    for (int i = 0; i < N * M; i++) d[i] = INF;
    d[ask_S(N - 1, M - 2)] = 0;

    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, ask_S(N - 1, M - 2)));

    while (!que.empty()){
        P now = que.top();
        que.pop();

        for (int i = lst[now.second]; i != 0; i = nxt[i]){
            int w = to[i];
            if (d[w] > d[now.second] +1){
                d[w] = d[now.second] + 1;
                que.push(P(d[w], w));
                pre_d[w] = now.second;
            }
        }
    }
    if (d[ask_S(0, 1)] == INF) return -1;
    else return d[ask_S(0, 1)];
}
int ask_char(int p, int q){
    // {'*', ' ', '&','>', '<', '|', 'S', 'E'};
    int y1 = p % N;
    int y2 = q % N;
    if (y1 == y2) return 5;
    else if (y2 - y1 == 1) return 3;
    else return 4;
}

int min_ste;
void ready(){
	system("cls");
    min_ste = -1;
    cout<<"\t*                Map is creating, please wait.              *"<<endl;
    while (min_ste == -1){
        createMAP();
        pre_DIJ();
        min_ste = check();
    }
    system("cls");
    
    int now = ask_S(0, 1);
    while (now != ask_S(N - 1, M - 2)){
        int t = pre_d[now];
        a[now / N][now % N] = ask_char(now, t);
        now = t;
    }
}
void GameStart();
void AutoGame();

void menu(){
    system("cls");
	
	cout<<"\t****************************************"<<endl;
	cout<<"\t*                                      *"<<endl;
	cout<<"\t*               1.开始游戏             *"<<endl;
	cout<<"\t*                                      *"<<endl;
	cout<<"\t*               2.自动游戏             *"<<endl;
	cout<<"\t*                                      *"<<endl;
	cout<<"\t*               3.退出游戏             *"<<endl;
	cout<<"\t*                                      *"<<endl;
	cout<<"\t****************************************"<<endl;
    switch(getch()){
        case '1':
            GameStart();
            break;
        case '2':
            AutoGame();
            break;
        case '3':
            exit(0);
            break;
        default:
            cout<<"\n\n              Waring:Not correct input!"<<endl;
			cout<<"\n\n              Press any key to continue."<<endl;
            getch();
            menu();
    }
}
void reStart(){
    cout<<"\n\n              Press any key to restart."<<endl;
    getch();
    ready();
    menu();
}
void AutoGame(){
	//reLoad();
    system("cls");
    a[0][1] = 6;
    printMAP();
    cout<<"\n\n              The minimum step is "<<min_ste<<endl;
    reStart();
}
void GameStart(){
    system("cls");
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) tmp[i][j] = a[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) a[i][j] = (a[i][j] > 0);

    int x = 0, y = 1, tx, ty, corr, vic = 0, you_stp = 0;;
    while (vic == 0){
        system("cls");
        printMAP();
        
        corr = 1;
        you_stp++;
        tx = x, ty = y;
        switch(getch()){
            case 'w':
                tx--;
                break;
            case 's':
                tx++;
                break;
            case 'a':
                ty--;
                break;
            case 'd':
                ty++;
                break;
            case 'l':
                vic = -1;
                break;
            default:
                corr = 0;
                you_stp--;
                break;
        }
        if (a[tx][ty]){
            a[x][y] = 1;
            x = tx, y = ty;
            a[x][y] = 2;
        }
        else corr = 2;

        if (tx == N - 1 && ty == M - 2) {
            vic = 1;
            break;
        }
        if (corr == 0){
            cout<<"\n\n              Waring:Not correct input!"<<endl;
			cout<<"\n\n              Press wasd to move."<<endl;
			getch();
        }
        else if (corr == 2){
            cout<<"\n\n              Waring:The road isn't accesible!"<<endl;
            cout<<"\n\n              You can press 'l' to give up, haha!"<<endl;
            getch();
        }
    }
    if (vic == 1){
        cout<<"\n\n              Congratulations:You win!"<<endl;
        cout<<"\n\n              Your step is "<<you_stp<<"  and the minimum step is "<<min_ste<<endl;
        cout<<"\n\n              You can press 'r' to restart, or press other keys to see the shortest path!"<<endl;
		
		if (getch() == 'r') reStart();
		
		else {
			for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) a[i][j] = tmp[i][j];
			AutoGame();  
		}
    }
    else{
        cout<<"\n\n              You give up!"<<endl;
        cout<<"\n\n              Press any key to print the ans."<<endl;
        getch();
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) a[i][j] = tmp[i][j];
        AutoGame();
    }
}

int main(){
	cout<<"\t*           Please input the Lenth and Width, you can't change them during this time          *"<<endl;
	scanf("%d %d", &N, &M);
    ready();
    menu();
    return 0;
}
