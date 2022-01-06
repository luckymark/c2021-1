#pragma once
class board {
private:
	int pre[16][16];
	long long value;
public:
	void initboard();//初始化棋盘数据
	void draw(int x, int y, int color);//画出棋子
	int readboard(int x, int y);//返回当前格子的状态
	void readplayer();//读取并翻译鼠标信息
	void mango();
	void aigo();//电脑走棋
	bool close(int x, int y);//判定当前格子是否离棋局很近
	long long cal_line(int line, int color);
	long long cal_colume(int colume, int color);
	long long cal_diagonal(int dis,int color);
	long long cal_backdiagonal(int dis,int color);
	long long  calculate();//启发式搜索の估值函数     ps.估值函数也可用于判定游戏是否结束
	long long max_min_dfs(int depth, long long alpha, long long beta);//极大值-极小值搜索 + alpha-beta剪枝
	int Checkover();//0-> 未结束；1->AI胜利；2->玩家胜利
	
	
};	