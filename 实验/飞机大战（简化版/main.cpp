#include "game.h"

#include<time.h>

#include<string>


using namespace std;


/*================== the main function ==================*/

int main()

{

	//游戏准备

	srand((int)time(0));
	// 设置随机种子
	// 计算机的随机数都是由伪随机数，即是由小M多项式序列生成的，其中产生每个小序列都有一个初始值，即随机种子。
	// rand()函数可以用来产生随机数，但是这不是真正意义上的随机数，是一个伪随机数，
	// 是根据一个数（我们可以称它为种子）为基准以某个递推公式推算出来的一系列数，
	// 当这系列数很大的时候，就符合正态公布，从而相当于产生了随机数，但这不是真正的随机数，
	// 当计算机正常开机后，这个种子的值是定了的，除非你破坏了系统。
	//  void srand(unsigned int seed)
	// srand()用来设置rand()产生随机数时的随机数种子。参数seed必须是个整数，
	// 如果每次seed都设相同值，rand()所产生的随机数值每次就会一样。
	// rand()产生的随机数在每次运行的时候都是与上一次相同的。若要不同,用函数srand()初始化它。
	// 可以利用srand((unsigned int)(time(NULL))的方法，产生不同的随机数种子，因为每一次运行程序的时间是不同的。
	// NULL的值为0。规定0可以赋值给任意指针，除0以外的任何数值都不能赋值给指针。

	HideCursor();	//隐藏光标



	Game game;

	int a = drawMenu();

	if (a == 2)

		game.rank = 20;

	system("cls");

	drawPlaying();

	game.Playing();

}