#include <graphics.h>
#include <stdio.h>
#include<windows.h>

IMAGE bgp;
int num = 1;
int piece[15][15]={0};
int aipoint[2] = {0};
int mark[24][3] = {0};  //三个数分别依次是：这一点的分数，这一点的横坐标，纵坐标


void putbackground()
{
	putimage(0, 0, 240, 240, &bgp, 60, 60);
	putimage(240, 0, 240, 240, &bgp, 60, 60);
	putimage(0, 240, 240, 240, &bgp, 60, 60);
	putimage(240, 240, 240, 240, &bgp, 60, 60);

}

void drawline()
{
	setlinecolor(BLACK);
	for (int x = 15; x < 465; x += 30)
	{
		line(x, 15,x,435);
	}
	for (int y = 15; y < 465; y += 30)
	{
		line(15, y, 435, y);
	}
}
void drawpoint()
{
	setfillcolor(BLACK);
	fillcircle(105, 105, 3);
	fillcircle(105, 12 * 30 - 15, 3);
	fillcircle(8*30-15, 8 * 30 - 15, 3);
	fillcircle(12*30-15, 4 * 30 - 15, 3);
	fillcircle(12*30-15, 12 * 30 - 15, 3);

}

int changepiece(int x, int y)
{
	if (piece[x][y] != 0)
	{
		return 0;
	}
	piece[x][y] = num;
	return 1;
}

void drawpiece(int m, int n)
{
	if (num == 1)
	{
		setfillcolor(WHITE);
	}
	else if(num==-1)
	{
		setfillcolor(BLACK);
    }
	int x,y;
	x = m / 30 ;
	y = n / 30 ;
	if(changepiece(x,y)==0)
	{
		return;
	}
	fillcircle(m - (m % 30) + 15, n - (n % 30) + 15, 13);
	num = -1 * num;
	
}

int checkfivepieces(int x, int y)
{
	if (x < 2 || y < 2 || x>12 || y>12)
		return 0;
	if (piece[x][y] == piece[x - 1][y] && piece[x][y] == piece[x - 2][y] && piece[x][y] == piece[x + 1][y] && piece[x][y] == piece[x + 2][y])
		return 1;
	if (piece[x][y] == piece[x][y - 1] && piece[x][y] == piece[x][y - 2] && piece[x][y] == piece[x][y + 2] && piece[x][y] == piece[x][y + 1])
		return 1;
	if (piece[x][y] == piece[x + 1][y + 1] && piece[x][y] == piece[x + 2][y + 2] && piece[x][y] == piece[x - 1][y - 1] && piece[x][y] == piece[x - 2][y - 2])
		return 1;
	if (piece[x][y] == piece[x - 1][y + 1] && piece[x][y] == piece[x - 2][y + 2] && piece[x][y] == piece[x + 1][y - 1] && piece[x][y] == piece[x + 2][y - 2])
        return 1;
	return 0;
}       
int checkover()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{   
			if (piece[i][j] == 0)
			{
				continue;
			}
			if (i < 2 || j < 2 || i>12 || j>12);

			else {
				if (checkfivepieces(i, j) == 1)
				{
					return 1;
				}
			}
		}
	}
}

int fiveconditions(int* pailie)  //通过典型棋型计算在某个方向上的分数
{   
	int mark1=0;
	for (int j = 0; j <= 8; j++)
	{
		if (pailie[j] == 1)
		{
			continue;
		}
		if (j <= 4 && pailie[j] == -1 && pailie[j + 1] == -1 && pailie[j + 2] == -1 && pailie[j + 3] == -1 && pailie[j + 4] == -1)
		{
			return 10000;//五连
		}
		if (j <= 3 && pailie[j] == 0 && pailie[j + 1] == -1 && pailie[j + 2] == -1 && pailie[j + 3] == -1 && pailie[j + 4] == -1 && pailie[j + 5] == 0)
		{
			return 1000;//活四
		}
		if (j <= 4 && pailie[j] + pailie[j + 1] + pailie[j + 2] + pailie[j + 3] + pailie[j + 4] == -4)
		{
			mark1 += 100; continue;//冲四
		}
		if (j <= 4 && pailie[j] == 0 && pailie[j + 1] == -1 && pailie[j + 2] == -1 && pailie[j + 3] == -1 && pailie[j + 4] == 0)
		{
			mark1 += 100; continue;//活三
		}
		if (j <= 5 && pailie[j] + pailie[j + 1] + pailie[j + 2] + pailie[j + 3] + pailie[j + 4] == -3)
		{
			mark1 += 10; continue;//冲三
		}
		if (pailie[j] == 0 && pailie[j + 1] == -1 && pailie[j + 2] == -1 && pailie[j + 3] == 0)
		{
			mark1 += 10; continue;//活二
		}
		
	}
	return mark1;
}

int playerconditions(int* pailie)
{
	int mark1=0;
	for (int j = 0; j <= 8; j++)
	{
		if (pailie[j] == -1)
		{
			continue;
		}
		if (j <= 4 && pailie[j] == 1 && pailie[j + 1] == 1 && pailie[j + 2] == 1 && pailie[j + 3] == 1 && pailie[j + 4] == 1)
		{
			return 10000;//五连
		}
		if (j <= 3 && pailie[j] == 0 && pailie[j + 1] == 1 && pailie[j + 2] == 1 && pailie[j + 3] == 1 && pailie[j + 4] == 1 && pailie[j + 5] == 0)
		{
			return 1000;//活四
		}
		if (j <= 4 && pailie[j] + pailie[j + 1] + pailie[j + 2] + pailie[j + 3] + pailie[j + 4] == 4)
		{
			mark1 += 90; continue;//冲四
		}
		if (j <= 4 && pailie[j] == 0 && pailie[j + 1] == 1 && pailie[j + 2] == 1 && pailie[j + 3] == 1 && pailie[j + 4] == 0)
		{
			mark1 += 90; continue;//活三
		}
		
	}
	return mark1;
}


int calculate(int x,int y)   //传入将下点的坐标
{
	int n = 0;
	int mark1 = 0;
	int pailie[9] = { 0 };pailie[4] = -1;
	
	


	for (int i = 1; i <= 4; i++)          //横向赋值
	{
		if (x <= (15 - i))
		{
			pailie[4 + i] = piece[x + i][y];
		}
		else { pailie[4 + i] = 1; }
		if (x >= i)
		{
			pailie[4 - i] = piece[x - i][y];
		}
		else { pailie[4 - i] = 1; }
	}
	if (fiveconditions(pailie) >= 10000)
		return fiveconditions(pailie);
	mark1 += fiveconditions(pailie);
	
	  
	for (int i = 1; i <= 4; i++)          //纵向赋值
	{
		if (y <= (15 - i))
		{
			pailie[4 + i] = piece[x][y + i];

		}
		else { pailie[4 + i] = 1; }
		if (y >= i)
		{
			pailie[4 - i] = piece[x][y - i];
		}
		else { pailie[4 - i] = 1; }
	}
	if (fiveconditions(pailie) >= 10000)
		return fiveconditions(pailie);
	mark1 += fiveconditions(pailie);

	
	for (int i = 1; i <= 4; i++)          //撇向赋值
	{
		if (x >= i && y <= (15 - i))
		{
			pailie[4 + i] = piece[x - i][y + i];

		}
		else { pailie[4 + i] = 1; }
		if (x <= (15 - i) && y >= i)
		{
			pailie[4 - i] = piece[x + i][y - i];
		}
		else { pailie[4 - i] = 1; }
	}
	if (fiveconditions(pailie) >= 10000)
		return fiveconditions(pailie);
	mark1 += fiveconditions(pailie);

	
	for (int i = 1; i <= 4; i++)          //捺向赋值
	{
		if (x <= (15 - i) && y <= (15 - i))
		{
			pailie[4 + i] = piece[x + i][y + i];

		}
		else { pailie[4 + i] = 1; }
		if (x >= i && y >= i)
		{
			pailie[4 - i] = piece[x - i][y - i];
		}
		else { pailie[4 - i] = 1; }
	}
	if (fiveconditions(pailie) >= 10000)
		return fiveconditions(pailie);
    mark1 += fiveconditions(pailie);

	pailie[4] = 1;

	for (int i = 1; i <= 4; i++)          //player横向赋值
	{
		if (x <=(15-i))
		{
			pailie[4 + i] = piece[x + i][y];
			
		}
		else { pailie[4 + i] = -1; }
		if (x >= i)
		{
			pailie[4 - i] = piece[x - i][y];
		}
		else { pailie[4 - i] = -1; }
	}
	if (playerconditions(pailie) >= 10000)
		return playerconditions(pailie);
	mark1 += playerconditions(pailie);


	for (int i = 1; i <= 4; i++)          //player纵向赋值
	{  
		if (y <= (15-i))
		{
			pailie[4 + i] = piece[x][y+ i];

		}
		else { pailie[4 + i] = -1; }
		if (y >= i)
		{
			pailie[4 - i] = piece[x][y- i];
		}
		else { pailie[4 - i] = -1; }
	}
	if (playerconditions(pailie) >= 10000)
		return playerconditions(pailie);
	mark1 += playerconditions(pailie);



	for (int i = 1; i <= 4; i++)          //player撇向赋值
	{
		if (x>=i&&y <= (15 - i))
		{
			pailie[4 + i] = piece[x-i][y + i];

		}
		else { pailie[4 + i] = -1; }
		if (x<=(15-i)&&y >= i)
		{
			pailie[4 - i] = piece[x+i][y - i];
		}
		else { pailie[4 - i] = -1; }
	}
	if (playerconditions(pailie) >= 10000)
		return playerconditions(pailie);
	mark1 += playerconditions(pailie);



	for (int i = 1; i <= 4; i++)          //player捺向赋值
	{   
		if (x<=(15-i) && y <= (15 - i))
		{
			pailie[4 + i] = piece[x + i][y + i];

		}
		else { pailie[4 + i] = -1; }
		if (x >=i && y >= i)
		{
			pailie[4 - i] = piece[x - i][y - i];
		}
		else { pailie[4 - i] = -1; }
	}
	if (playerconditions(pailie) >= 10000)
		return playerconditions(pailie);
	mark1 += playerconditions(pailie);

	
	return  mark1;
		
}
void determination(int x, int y)                       //参数是人的落子坐标
{
    int r = 0;
	for(int i = -2; i <=2 ; i++)
	{
			for (int j = -2; j <=2; j++)       //检索敌方落子点周围两环空点
			{
				if (piece[x + i][y + j]==0)           //求该点分数，存入mark[][]
				{
				    mark[r][0]=calculate(x+i,y+j);       
					mark[r][1] = x + i;
					mark[r][2] = y + j;
					r++;
				}
				
			}	
	}
	
	int max = 0;
	for (int i = 0; i <= 23; i++)           //检索最大值点，传出其坐标
	{
		if (mark[i][0] >= max)
		{
			max = mark[i][0];
			aipoint[0] = mark[i][1];
			aipoint[1] = mark[i][2];            
		}
	}
	

}


int main() 
{   
	initgraph(480,480);
	loadimage(&bgp, _T("background.jpg"));
	putbackground();
	drawline();
	drawpoint();
	MOUSEMSG m;
	settextcolor(RED);
	settextstyle(42, 20, _T("隶书"));
	setbkmode(TRANSPARENT);
	while (1) {
		m = GetMouseMsg();
	    
		if (num == 1) 
		{
			if (m.uMsg == WM_LBUTTONDOWN)//如果鼠标左键按下
			{
				drawpiece(m.x, m.y);
				
			}
		}

		if (checkover() == 1)
		{

			outtextxy(180, 180, _T("游戏结束"));
			system("pause");
			return 0;

		}

		if (num == -1)
		{
			determination(m.x/30,m.y/30);
			drawpiece(30*aipoint[0], 30*aipoint[1]);
			
		}
		
		if (checkover() == 1)
		{   
			
			outtextxy(180, 180, _T("游戏结束"));
			system("pause");
            return 0;

		}

	}

	return 0;
}