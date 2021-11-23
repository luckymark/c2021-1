#include <cstdio>
#include <windows.h>
#include <conio.h>
using namespace std;

const int maxL = 1e3;

int N, M, num_box = 0;
int nx, ny;
int tx, ty, px, py;
int C, w = 0, ans = 0;
char a[maxL][maxL];


FILE *fp = fopen("map.in", "r+");
FILE *fq = fopen("res.out", "r+");

void init(){
    memset(a, 0 ,sizeof(a));
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            a[i][j] = fgetc(fp);
            if (a[i][j] == 'I')
                nx = i, ny = j;
            else if(a[i][j] == 'B')
                num_box++;
        }
        fgetc(fp);
    }
}

void printMap(){
	system("cls");
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) printf("%c", a[i][j]);
        printf("\n");
    }
}

void prePrint(){
    printf("Level %d", w);
    getch();
    system("cls");
}

void moveH(){
    if (a[tx][ty] == '#' || a[tx][ty] == 'T'){
        printf("Input illegal\n");
        return ;
    }

    a[nx][ny] = ' ', a[tx][ty] = 'I';
    nx = tx, ny = ty;
}

void pushBox(){
    if (a[px][py] == '#'){
        printf("Input illegal\n");
        return ;
    }
    else if (a[px][py] == 'T'){
        num_box--;
    }
    else{
		a[px][py] = 'B';
	}
    moveH();
}

int main(){
    //freopen("map.in", "r+", stdin);
    //freopen("res.out", "w+", stdout);

    
    fscanf(fp, "%d", &C);

    while (w < C){
        ans = 0, num_box = 0;
        fscanf(fp, "%d %d\n", &N, &M);

        init();

        prePrint();

        while (num_box){
        	printMap();
			
			
            switch(getch()){
                case 'w':
                    tx = nx - 1, ty = ny;
                    px = tx - 1, py = ty;
                    break;
                case 's':
                    tx = nx + 1, ty = ny;
                    px = tx + 1, py = ty;
                    break;
                case 'a':
                    tx = nx, ty = ny - 1;
                    px = tx, py = ty - 1;
                    break;
                case 'd':
                    tx = nx, ty = ny + 1;
                    px = tx, py = ty + 1;
                    break;
                default:
                    break;
            }

            if (a[tx][ty] == 'B')
                pushBox();
            else
                moveH();
                
            ans++;    
        }
		printMap();
        printf("You took %d steps in Level %d", ans, w);
        fprintf(fq, "Level %d, Steps %d\n", w, ans);
        w++;
        getch();
        system("cls");
    }
    return 0;
}
