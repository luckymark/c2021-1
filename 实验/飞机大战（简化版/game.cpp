
#include <iostream>

#include "game.h"
#include<string>
#include<conio.h>

using namespace std;


// 定义构造函数
// 构造函数是特殊的成员函数，只要创建类类型的新对象，都要执行构造函数。
// 构造函数的工作是保证每个对象的数据成员具有合适的初始值。
// 构造函数通常使用构造函数初始化列表来初始化其数据成员，
// 当然，像此处一样，省略初始化列表，并在构造函数的函数体内对数据成员赋值是合法的。
// 注意，构造函数的名字与类的名字相同，并且不能指定返回类型。像其他任何函数一样，
// 它们可以没有形参，也可以定义多个形参。
Game::Game()

{
	// 调用类成员函数来进行初始化
	initPlane();

	initBullet();

	initEnemy();


	// 初始化四个int型数据成员，采用赋值的方式进行初始化
	// string类型的数据成员title没有进行初始化，因为：
	// string本身就是一个标准库类类型，它的类定义中设置了默认构造函数，
	// 这些默认构造函数会将对象初始化为合理的默认状态，
	//  string的默认构造函数会产生空字符串，相当于"" 。
	score = 0;

	rank = 25;

	rankf = 0;

	flag_rank = 0;

}


// 成员函数既可以定义在类的内部，也可以定义在类的外部。
// 在类外部定义的成员函数必须指明它们是在类的作用域中，例如
//  Game::initPlane的定义使用 作用域操作符 来指明这是 Game类中initPlane函数的定义。
// 这是初始化战机位置的成员函数
void Game::initPlane()

{

	COORD centren;
	centren.X = 39;
	centren.Y = 22;

	position[0].X = position[5].X = position[7].X = position[9].X = centren.X;

	position[1].X = centren.X - 2;

	position[2].X = position[6].X = centren.X - 1;

	position[3].X = position[8].X = centren.X + 1;

	position[4].X = centren.X + 2;

	for (int i = 0; i <= 4; i++)

		position[i].Y = centren.Y;

	for (int i = 6; i <= 8; i++)

		position[i].Y = centren.Y + 1;

	position[5].Y = centren.Y - 1;

	position[9].Y = centren.Y - 2;

	// 这个函数体类的代码其实就是为了初始化战机的十个部分的位置，战机的组成如下所示：   
	//                   |
	//				     |
	//				   00000
	//				    000
	//   第一排5个0的坐标依次对应了position[1]position[2]position[0]position[3]position[4]
	//   第二排三个0的坐标依次对应了position[6]position[7]position[8]
	//   两排0上面的两|的坐标从上往下依次对应了position[5]position[9]
}



// 这是初始化战机外形的成员函数
// 战机的形状组成如下所示：
//                   |
//				     |
//				   00000
//				    000
// 在该函数中调用了SetPos()函数来设置光标的
void Game::drawPlane()
{
	for (int i = 0; i < 9; i++)
	{
		SetPos(position[i]);
		// 此处调用SetPos()函数将光标设置到了position[i]指定的位置

		if (i != 5)

			cout << "O";

		else if (i == 5)

			cout << "|";
	}
}


// 这个成员函数通过将战机的每个坐标处输出" "来代替"0"和"|"，
// 来达到将战机消除的目的。
void Game::drawPlaneToNull()
{
	for (int i = 0; i < 9; i++)
	{
		SetPos(position[i]);

		cout << " ";
	}
}



// 该成员函数用来初始化子弹，
// 即将每个子弹的Y坐标初始化为30（bullet[i].Y = 30）来表示子弹处于失效状态
void Game::initBullet()
{
	for (int i = 0; i < 10; i++)

		bullet[i].Y = 30;
}




// 该成员函数用来画出子弹
// 首先检查每颗子弹的有效性，如果子弹有效，则定位到该子弹的坐标处，输出 "^"，表示该子弹，
// 如果子弹是无效的，则不绘制
void Game::drawBullet()

{

	for (int i = 0; i < 10; i++)

	{

		if (bullet[i].Y != 30)

		{

			SetPos(bullet[i]);

			cout << "^";
		}

	}

}




void Game::drawBulletToNull()

{

	for (int i = 0; i < 10; i++)

		if (bullet[i].Y != 30)

		{

			COORD pos = { bullet[i].X, bullet[i].Y + 1 };

			SetPos(pos);

			cout << " ";

		}

}



// 这个函数用来初始敌机的位置，
// 屏幕当中只能同时存在八架敌机，
// 且每架敌机用如下结构体Frame来表示，如下所示：
//     typedef struct Frame
//        {
//	      COORD position[2];
//      	int flag;
//        }Frame;
void Game::initEnemy()

{

	COORD a = { 1, 1 };
	COORD b = { 45, 15 };
	// 

	for (int i = 0; i < 8; i++)

	{

		enemy[i].position[0] = random(a, b);
		//  random(a, b)是调用了一个重载的函数，它表示在坐标a、b之间的矩形框
		//  内随机生成一个坐标值，并将该坐标值作为敌机的左上角的坐标。
		// enemy[i].position[0]中是一个Frame结构体类型的变量，
		// 存放了敌机i的左上角的坐标。

		enemy[i].position[1].X = enemy[i].position[0].X + 3;
		enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
		// enemy[i].position[1]也中是一个Frame结构体类型的变量，
		// 存放了敌机i的右下角的坐标。


	}

}


// 接下来要根据敌机的左上角坐标和右下角坐标画出敌机，
// 显然，敌机的外形如下所示：
//   --
//  |  |
//   --
void Game::drawEnemy()

{

	for (int i = 0; i < 8; i++)

		drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');

}


// 将敌机消除，通过输出空白的方式
void Game::drawEnemyToNull()

{

	for (int i = 0; i < 8; i++)

	{

		drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');

	}

}


// 该成员函数用来使得游戏暂停
void Game::Pause()

{

	SetPos(61, 2);

	cout << "         ";

	SetPos(61, 2);

	cout << "暂停中...";

	// 当出现"暂停中..."的提示以后，程序不停的接收按下的按键，
	// 当按下'p'键以后，说明要退出暂停状态，此时需要清除"暂停中..."的提示
	// 通过输出空白 "         "来将其覆盖，达到效果
	char c = _getch();

	while (c != 'p')

		c = _getch();

	SetPos(61, 2);

	cout << "         ";

}


// 该成员函数用过响应战机的一个动作
// a,s,w,d,来控制战机的移动
void Game::planeMove(char x)

{

	if (x == 'a')

		if (position[1].X != 1)

			for (int i = 0; i <= 9; i++)

				position[i].X -= 2;
	// 如果玩家按下 'a' 键，说明玩家想让战机往左移动一个距离（2个单位），
	// 首先检测，战机的最左侧的位置坐标（即position[1].X）有没有达到左边界，
	// 如果到达了边界，那就不做出移动；如果没有达到边界，则将战机10个部分的X值减小2。


	if (x == 's')

		if (position[7].Y != 23)

			for (int i = 0; i <= 9; i++)

				position[i].Y += 1;
	// 如果玩家按下 's' 键，说明玩家想让战机往下移动一个距离（1个单位），
	// 首先检测，战机的最底部的位置坐标（即position[6].Y或者position[7].Y或者position[8].Y）有没有达到下边界，
	//  如果到达了边界，那就不做出移动；如果没有达到边界，则将战机10个部分的Y值增加1。


	if (x == 'd')

		if (position[4].X != 47)

			for (int i = 0; i <= 9; i++)

				position[i].X += 2;
	// 如果玩家按下 'd' 键，说明玩家想让战机往右移动一个距离（2个单位），
	// 首先检测，战机的最右侧的位置坐标（即position[4].X）有没有达到右边界，
	//  如果到达了边界，那就不做出移动；如果没有达到边界，则将战机10个部分的X值增加2。



	if (x == 'w')

		if (position[5].Y != 3)

			for (int i = 0; i <= 9; i++)

				position[i].Y -= 1;
	// 如果玩家按下'w'键，说明玩家想让战机往上移动一个距离（1个单位），
	// 首先检测，战机的最顶部的位置坐标（即position[5].Y）有没有达到上边界，
	//  如果到达了边界，那就不做出移动；如果没有达到边界，则将战机10个部分的Y值减少1。

}


// 此成员函数用来响应一次子弹的运动
// 每次子弹运动，屏幕子弹的坐标都会出现变化，即
// 先判断子弹是否有效（即判断语句if (bullet[i].Y != 30)），
// 若子弹有效，将该子弹的Y坐标减少1，X坐标不变，
// 检测子弹坐标更改之后是否达到上边界，如果达到上边界，则将该子弹从屏幕上擦除，
// 同时，将该子弹置为失效状态，即 bullet[i].Y = 30。
void Game::bulletMove()

{

	for (int i = 0; i < 10; i++)

	{

		if (bullet[i].Y != 30)

		{

			bullet[i].Y -= 1;

			if (bullet[i].Y == 1)

			{

				COORD pos = { bullet[i].X, bullet[i].Y + 1 };

				drawThisBulletToNull(pos);

				bullet[i].Y = 30;

			}



		}

	}

}


// 该成员函数用来响应一次敌机的移动
// 界面上必须同时出现八架敌机，因此，
// 如果有某架敌机运动到下边界处，则重置该敌机的坐标
void Game::enemyMove()

{

	for (int i = 0; i < 8; i++)

	{

		for (int j = 0; j < 2; j++)

			enemy[i].position[j].Y++;
		// 我们将每架敌机的左上角和右下角坐标的Y值增加1，
		// 表示该敌机向下走了一个距离

		// 检测向下走一个距离后的敌机的右下角坐标的Y值是否达到24，
		// 如果达到，代表敌机已经运动到下边界了，
		// 此时需要随机重置该敌机的坐标
		if (24 == enemy[i].position[1].Y)

		{

			COORD a = { 1, 1 };

			COORD b = { 45, 3 };

			enemy[i].position[0] = random(a, b);

			enemy[i].position[1].X = enemy[i].position[0].X + 3;

			enemy[i].position[1].Y = enemy[i].position[0].Y + 2;

		}

	}

}


// 该成员函数用来判断战机是否坠毁，
// 依次判断每架敌机与战机的每个部分是否有接触，
// 如果有接触，则表示战机坠毁
void Game::judgePlane()

{

	for (int i = 0; i < 8; i++)

		for (int j = 0; j < 9; j++)

			// 此处的实参position[j]是指战机的10个部分的COORD坐标，
			// 类中的成员函数可以访问数据成员变量。
			// 此处也可以写成this-> position[j]，因为
			// 成员函数具有一个附加的隐含形参，即指向该类对象的一个指针，
			// 这个隐含形参命名为this，与调用成员函数的对象绑定在一起。
			// 成员函数不能定义this形参，而是由编译器隐含地定义。
			// 成员函数的函数体可以显式使用this指针，但不是必须这么做。
			if (judgeCoordInFrame(enemy[i], position[j]))

			{

				SetPos(62, 1);

				cout << "坠毁";

				drawFrame(enemy[i], '+', '+');
				// 将与战机相撞的敌机的形状绘制为:
				//    ++
				//   +  +
				//    ++


				Sleep(1000);

				GameOver();

				break;

			}

}



void Game::drawThisBulletToNull(COORD c)

{

	SetPos(c);

	cout << " ";

}



void Game::drawThisEnemyToNull(Frame f)

{

	drawFrame(f, ' ', ' ');

}


// 该成员函数依次遍历每一架敌机，
// 将每一架敌机依次与每一颗子弹进行检测，
// 判断敌机是否与子弹有接触，如果有接触，则表示击中敌机，
// 此时将敌机和子弹擦除，然后在界面顶部的位置处随机生成一架敌机
void Game::judgeEnemy()

{

	for (int i = 0; i < 8; i++)

		for (int j = 0; j < 10; j++)

			if (judgeCoordInFrame(enemy[i], bullet[j]))

			{

				score += 5;

				drawThisEnemyToNull(enemy[i]);

				COORD a = { 1, 1 };

				COORD b = { 45, 3 };

				enemy[i].position[0] = random(a, b);

				enemy[i].position[1].X = enemy[i].position[0].X + 3;

				enemy[i].position[1].Y = enemy[i].position[0].Y + 2;

				drawThisBulletToNull(bullet[j]);

				bullet[j].Y = 30;

			}

}


// 这个成员函数用来响应一次射击操作，
// 也就是，当游戏中的时候，玩家按下"k"键，就执行该函数。
// 由于子弹是由COORD bullet[10]定义的，因此同一时刻，界面内只能有10颗子弹同时出现。
// 如果界面内不够10颗子弹，按下"k"键后战机应该发射出一颗子弹，
// 于是，依次遍历10颗子弹，当遇到第一颗失效的子弹后，
// 立即将该子弹赋予新的坐标（战机的炮口，也就是（position[5].X，position[5].Y - 1）），
// 让其激活。然后退出for循环，函数执行完毕。
void Game::Shoot()

{

	for (int i = 0; i < 10; i++)

		if (bullet[i].Y == 30)

		{

			bullet[i].X = position[5].X;

			bullet[i].Y = position[5].Y - 1;

			break;

		}

}



void Game::printScore()

{

	if (score == 120 && flag_rank == 0)

	{

		rank -= 3;

		flag_rank = 1;

	}



	else if (score == 360 && flag_rank == 1)

	{

		rank -= 5;

		flag_rank = 2;

	}

	else if (score == 480 && flag_rank == 2)

	{

		rank -= 5;

		flag_rank = 3;

	}

	int x = rank / 5;

	SetPos(60, 6);

	cout << score;



	if (rank != rankf)

	{

		SetPos(60, 7);

		if (x == 5)

			title = "初级飞行员";

		else if (x == 4)

			title = "中级飞行员";

		else if (x == 3)

			title = "高级飞行员";

		else if (x == 2)

			title = "王牌飞行员";

		cout << title;

	}

	rankf = rank;

}


// 这个成员函数是游戏的主循环函数，
// 定义了整个游戏过程。
void Game::Playing()

{

	//HANDLE MFUN;

	//MFUN= CreateThread(NULL, 0, MusicFun, NULL, 0, NULL); 



	drawEnemy();

	drawPlane();


	int flag_bullet = 0;

	int flag_enemy = 0;



	while (1)

	{

		Sleep(20);

		// 函数名：kbhit()（VC++6.0下为_kbhit()）
		// 功能及返回值： 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
		// 用法：int kbhit(void);
		// 包含头文件： include <conio.h>
		// kbhit()在执行时,检测是否有按键按下,有按下返回非0值，没有按下则返回0，是非阻塞函数；
		// 不同于getch()的在执行时, 检测按下什么键, 如果不按键该函数不返回，也就不进行下一步操作，是阻塞函数。
		if (_kbhit())

		{

			char x = _getch();
			// getch()是编程中所用的函数，这个函数是一个不回显函数，
			// 当用户按下某个字符时，函数自动读取，无需按回车
			// getch()并非标准C中的函数，不存在C语言中。
			// 所在头文件是conio.h，而不是stdio.h。
			// 用ch = getch(); 会等待你按下任意键之后，把该键字符所对应的ASCII码赋给ch, 再执行下面的语句。

			if ('a' == x || 's' == x || 'd' == x || 'w' == x)

			{

				drawPlaneToNull();     // 将战机先擦除

				planeMove(x);          // 根据所输入的操作符，对战机的坐标进行更改

				drawPlane();           // 访问类中的数据成员——战机的坐标，在新的坐标处重新绘制战机

				judgePlane();          // 判断战机是否有坠毁

			}

			//  在某一循环当中，如果检测到有'p'键按下，
			// 首先在右侧游戏界面输出"暂停中..."，然后陷入while()循环一直等待'p'键再次按下，
			// 如果'p'键没有按下，就一直处在while()循环内，因此不能执行后面的程序，起到暂停的效果。
			else if ('p' == x)

				Pause();

			// 如果是检测到'k'键按下，则运行Shoot()函数，
			else if ('k' == x)

				Shoot();

			// 如果是检测到'k'键按下，则运行GameOver()函数，
			// GameOver()函数执行完毕后，执行break;语句跳出while循环（注意不是if (_kbhit())）。
			// break语句用于结束最近的while、do while、for或switch语句，并将程序的执行权传递给紧接在
			// 被终止语句之后的语句。
			else if ('e' == x)

			{

				//CloseHandle(MFUN);

				GameOver();

				break;

			}

		}


		// 接下来处理子弹
		if (0 == flag_bullet)

		{

			bulletMove();           // 更新界面上有效子弹的坐标

			drawBulletToNull();     // 将处于旧坐标的子弹擦除

			drawBullet();           // 绘制出新坐标上的子弹

			judgeEnemy();          // 判断敌机是否被子弹击中

		}

		flag_bullet++;

		if (5 == flag_bullet)

			flag_bullet = 0;



		//  接下来处理敌机
		if (0 == flag_enemy)

		{

			drawEnemyToNull();     // 将所有的敌机都擦除

			enemyMove();           //  更新敌机的坐标

			drawEnemy();           // 绘制出处于新坐标上的敌机

			judgePlane();          // 判断敌机是否与战机接触

		}

		flag_enemy++;

		if (flag_enemy >= rank)

			flag_enemy = 0;



		/* 输出得分 */

		printScore();

	}

}



void Game::GameOver()

{

	system("cls");

	COORD p1 = { 28,9 };

	COORD p2 = { 53,15 };

	drawFrame(p1, p2, '=', '|');

	SetPos(36, 12);

	string str = "Game Over!";

	for (int i = 0; i < str.size(); i++)

	{

		Sleep(80);

		cout << str[i];

	}

	Sleep(1000);

	system("cls");

	drawFrame(p1, p2, '=', '|');

	SetPos(31, 11);

	cout << "击落敌机：" << score / 5 << " 架";

	SetPos(31, 12);

	cout << "得　　分：" << score;

	SetPos(31, 13);

	cout << "获得称号：" << title;

	SetPos(30, 18);

	Sleep(1000);

	cout << "继续？ 是（y）| 否（n）";

as:

	char x = _getch();

	if (x == 'n')

		exit(0);

	else if (x == 'y')

	{

		system("cls");

		Game game;

		int a = drawMenu();       // 绘制游戏开始界面主菜单

		if (a == 2)

			game.rank = 20;

		system("cls");

		drawPlaying();           // 绘制游戏界面框架

		game.Playing();

	}

	else goto as;

}









// 

void SetPos(COORD a)    // set cursor 

{

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(out, a);

}



void SetPos(int i, int j)// set cursor

{

	COORD pos = { i, j };

	SetPos(pos);

}



void HideCursor()

{

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}



//把第y行，[x1, x2) 之间的坐标填充为 ch

void drawRow(int y, int x1, int x2, char ch)

{

	SetPos(x1, y);

	for (int i = 0; i <= (x2 - x1); i++)

		cout << ch;


}



//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch

void drawRow(COORD a, COORD b, char ch)

{

	if (a.Y == b.Y)

		drawRow(a.Y, a.X, b.X, ch);

	else

	{

		SetPos(0, 25);

		cout << "error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";

		system("pause");

	}

}



//把第x列，[y1, y2] 之间的坐标填充为 ch

void drawCol(int x, int y1, int y2, char ch)

{

	int y = y1;

	while (y != y2 + 1)

	{

		SetPos(x, y);

		cout << ch;

		y++;

	}

}



//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch

void drawCol(COORD a, COORD b, char ch)

{

	if (a.X == b.X)

		drawCol(a.X, a.Y, b.Y, ch);

	else

	{

		SetPos(0, 25);

		cout << "error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";

		system("pause");

	}

}



//左上角坐标、右下角坐标、用row填充行、用col填充列

void drawFrame(COORD a, COORD  b, char row, char col)

{

	drawRow(a.Y, a.X + 1, b.X - 1, row);

	drawRow(b.Y, a.X + 1, b.X - 1, row);

	drawCol(a.X, a.Y + 1, b.Y - 1, col);

	drawCol(b.X, a.Y + 1, b.Y - 1, col);

}



void drawFrame(int x1, int y1, int x2, int y2, char row, char col)

{

	COORD a = { x1, y1 };

	COORD b = { x2, y2 };

	drawFrame(a, b, row, col);

}



void drawFrame(Frame frame, char row, char col)

{

	COORD a = frame.position[0];

	COORD b = frame.position[1];

	drawFrame(a, b, row, col);

}





// 绘制游戏界面
void drawPlaying()

{

	drawFrame(0, 0, 48, 24, '=', '|');//	draw map frame;

	drawFrame(49, 0, 79, 4, '-', '|');//		draw output frame

	drawFrame(49, 4, 79, 9, '-', '|');//		draw score frame

	drawFrame(49, 9, 79, 20, '-', '|');//	draw operate frame

	drawFrame(49, 20, 79, 24, '-', '|');//	draw other message frame

	SetPos(52, 6);

	cout << "得分：";

	SetPos(52, 7);

	cout << "称号：";

	SetPos(52, 11);

	cout << "操作方式：";

	SetPos(52, 13);

	cout << "  a,s,d,w：控制战机移动。";

	SetPos(52, 15);

	cout << "  p：暂停游戏。";

	SetPos(52, 17);

	cout << "  e：退出游戏。";

	SetPos(52, 22);

	cout << " 游戏虽好玩，不要贪多哦 ";


}



// 在[a, b)之间产生一个随机整数，注意不包括b,
// C语言/C++里没有自带的random(int number)函数。
// （1）如果你只要产生随机数而不需要设定范围的话，你只要用rand()就可以了： 
// rand()会返回一随机数值,范围在0至RAND_MAX间。RAND_MAX定义在stdlib.h, 其值为2147483647。
// （2）如果你要随机生成一个在一定范围的数，例如，如果要产生1-100，则是这样：int num = rand() % 100 + 1;  
//  一般性：rand() % (b - a + 1) + a 就表示 [a,b]之间的一个随机整数。
//  一般性：rand() % (b - a ) + a 就表示 [a,b) 之间的一个随机整数。
int random(int a, int b)

{

	int c = (rand() % (a - b)) + a;

	return c;

}



//在两个坐标包括的矩形框内随机产生一个坐标
COORD random(COORD a, COORD b)

{

	int x = random(a.X, b.X);

	int y = random(a.Y, b.Y);

	COORD c = { x, y };

	return c;

}





// 该函数用来判断战机的某一部分是否与敌机有接触
// 如果与敌机有接触在判断为坠毁
bool  judgeCoordInFrame(Frame frame, COORD spot)

{

	if (spot.X >= frame.position[0].X)

		if (spot.X <= frame.position[1].X)

			if (spot.Y >= frame.position[0].Y)

				if (spot.Y <= frame.position[1].Y)

					return true;

	return false;

}



void printCoord(COORD a)

{

	cout << "( " << a.X << " , " << a.Y << " )";

}



void printFrameCoord(Frame a)

{

	printCoord(a.position[0]);

	cout << " - ";

	printCoord(a.position[1]);

}



// 绘制游戏主菜单界面
int drawMenu()

{

	SetPos(30, 1);

	cout << "飞 机 大 战";

	drawRow(3, 0, 79, '-');

	drawRow(5, 0, 79, '-');

	SetPos(28, 4);

	cout << "w 和 s 选择， k 确定";

	SetPos(15, 11);

	cout << "1. 简单的敌人";

	SetPos(15, 13);

	cout << "2. 冷酷的敌人";

	drawRow(20, 0, 79, '-');

	drawRow(22, 0, 79, '-');

	SetPos(47, 11);

	cout << "简单的敌人：";

	SetPos(51, 13);

	cout << "简单敌人有着较慢的移动速度。";

	SetPos(30, 21);

	cout << "copy right@";

	int j = 11;

	SetPos(12, j);

	cout << ">>";



	//drawFrame(45, 9, 79, 17, '=', '|');



	while (1)

	{
		if (_kbhit())

		{

			char x = _getch();

			switch (x)

			{

			case 'w':

			{

				if (j == 13)

				{

					SetPos(12, j);

					cout << "  ";

					j = 11;

					SetPos(12, j);

					cout << ">>";

					SetPos(51, 13);

					cout << "　　　　　　　　　　　　";

					SetPos(47, 11);

					cout << "简单的敌人：";

					SetPos(51, 13);

					cout << "简单敌人有着较慢的移动速度，比较容易对付";

				}

				break;

			}

			case 's':

			{

				if (j == 11)

				{

					SetPos(12, j);

					cout << "　";

					j = 13;

					SetPos(12, j);

					cout << ">>";

					SetPos(51, 13);

					cout << "　　　　　　　　　　　　　　";

					SetPos(47, 11);

					cout << "冷酷的敌人：";

					SetPos(51, 13);

					cout << "冷酷的敌人移动速度较快，难对付哟。";

				}

				break;

			}

			case 'k':

			{

				if (j == 8)
					return 1;

				else
					return 2;

			}

			}

		}

	}

}