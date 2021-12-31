#include <stdio.h>

#include <stdlib.h>

int main(int argc, const char* argv[])
{
	char map[8][8] = {
	{0,0,1,1,1,1,0,0},
	{0,0,1,4,4,1,0,0},
	{0,1,1,0,4,1,1,0},
	{0,1,0,0,3,4,1,0},
	{1,1,0,3,0,0,1,1},
	{1,0,0,1,3,3,0,1},
	{1,0,0,2,0,0,0,1},
	{1,1,1,1,1,1,1,1}
	};

	char m_x = 6, m_y = 3;

	int step = 0;

	for (;;)
	{
		int cnt = 0;
		system("clear");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				switch (map[i][j])
				{
				case 0:	printf("  "); break;
				case 1: printf("# "); break;
				case 2: printf("@ "); break;
				case 3: printf("$ "); break;
				case 4: printf("O "); break;
				case 6: printf("@ "); break;
				case 7: printf("$ ");
					cnt++;
					break;
				}
			}
			printf("\n");
		}

		if (4 == cnt)
		{
			printf("游戏结束,共走了%d步\n", step);
			return 0;
		}

		int ox = 0, oy = 0;		
		switch (getchar())		
		{
		case 183:	ox--; break;
		case 184:	ox++; break;
		case 185:	oy++; break;
		case 186:	oy--; break;
		}
		if (0 == map[m_x + ox][m_y + oy] ||
			4 == map[m_x + ox][m_y + oy])
		{
			map[m_x + ox][m_y + oy] += 2;
			map[m_x][m_y] -= 2;
			m_x += ox;
			m_y += oy;
			step++;
		}
		else if (3 == map[m_x + ox][m_y + oy] ||
			7 == map[m_x + ox][m_y + oy])
		{
			if (0 == map[m_x + ox * 2][m_y + oy * 2] ||
				4 == map[m_x + ox * 2][m_y + oy * 2])
			{
				map[m_x + ox * 2][m_y + oy * 2] += 3;
				map[m_x + ox][m_y + oy] -= 1;
				map[m_x][m_y] -= 2;
				m_x += ox;
				m_y += oy;
				step++;
			}
		}
	}
}