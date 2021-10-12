//
// Created by Durant on 2021/9/21.
//
#include <stdio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define x 19
#define y 12

void rule();//输出规则

int main(){
    rule();

    char map[x][y]={
            " *********",//L1
            "\n*    *   *",//L2
            "\n *** * * *",//L3
            "\n   * * * *",//L4
            "\n *** * * *",//L5
            "\n *   * ***",//L6
            "\n * *** *  ",//L7
            "\n *     *  ",//L8
            "\n ** ** *  ",//L9
            "\n*** ** *  ",//L10
            "\n* *  * ***",//L11
            "\n* ** * * F",//L12
            "\n*    * * *",//L13
            "\n**** * * *",//L14
            "\n   * * * *",//L15
            "\n   *   * *",//L16
            "\n**** * * *",//L17
            "\n*    *   *",//L18
            "\n**********",//L19
    };//地图，*为边界

    int r=1,c=2;//玩家位置坐标
    int R,C;//玩家上一次位置坐标
    char player='P';
    map[r][c]=player;//开始位置
    int flag=0;//离开游戏

    //开始游戏
    for(int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf("%c",map[i][j]);
        }
    }

    while(1){//保持游戏进行
        char a;
        if(scanf("%c",&a)){
            system("cls");
            R=r,C=c;//保存玩家上一个位置，用以清空上一次位置
            switch (a) {
                case 'w':r--;break;
                case 's':r++;break;
                case 'a':c--;break;
                case 'd':c++;break;
                case 'q':flag=1;break;

            }
            //撞墙，不作出反应
            if(map[r][c]=='*'){
                rule();
                for(int i=0;i<x;i++){
                    for (int j=0;j<y;j++){
                        printf("%c",map[i][j]);
                    }
                }
                r=R,c=C;//坐标复位
                continue;
            }else if (map[r][c]=='F'){
                printf("\n恭喜你到达了终点！\n");
                break;
            }
            //离开游戏
            if(flag){
                break;
            }
            //清空玩家上一次位置
            map[R][C]=' ';
            //改变玩家位置
            map[r][c]=player;
            //刷新地图
            rule();
            for (int i=0;i<x;i++){
                for (int j=0;j<y;j++){
                    printf("%c",map[i][j]);
                }
            }

        }else{ printf("\n错误指令\n");}
    }

    return 0;


}

void rule(){
    printf("迷宫\n");
    printf("P表示你的位置，F表示终点，*表示墙壁。每次输入wsad（回车输入）分别控制P上下左右移动\n");
    printf("输入q离开游戏\n\n");

}

