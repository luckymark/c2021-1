#pragma once

#include<windows.h>
#include<iostream>

using namespace std;


typedef struct Frame

{

	COORD position[2];
	//  COORD ��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ
	// �䶨��Ϊ��
	// typedef struct _COORD {
	//         SHORT X; 
	//         SHORT Y;
	//       } COORD;

	int flag;

}Frame;




class Game

{

public:

	COORD position[10];

	COORD bullet[10];

	Frame enemy[8];

	int score;

	int rank;

	int rankf;

	string title;

	int flag_rank;


	// ���캯��
	Game();



	//��ʼ������

	void initPlane();

	void initBullet();

	void initEnemy();



	//��ʼ������һ��

	//void initThisBullet( COORD );

	//void initThisEnemy( Frame );



	void planeMove(char);

	void bulletMove();

	void enemyMove();



	//�������

	void drawPlane();

	void drawPlaneToNull();

	void drawBullet();

	void drawBulletToNull();

	void drawEnemy();

	void drawEnemyToNull();



	//�������һ��

	void drawThisBulletToNull(COORD);

	void drawThisEnemyToNull(Frame);


	void Pause();

	void Playing();

	void judgePlane();

	void judgeEnemy();

	void Shoot();

	void GameOver();

	void printScore();

};




void SetPos(COORD a);
void SetPos(int i, int j);
void HideCursor();
void drawRow(int y, int x1, int x2, char ch);
void drawRow(COORD a, COORD b, char ch);
void drawCol(int x, int y1, int y2, char ch);
void drawCol(COORD a, COORD b, char ch);
void drawFrame(COORD a, COORD  b, char row, char col);
void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
void drawFrame(Frame frame, char row, char col);
void drawPlaying();
int random(int a, int b);
COORD random(COORD a, COORD b);
bool  judgeCoordInFrame(Frame frame, COORD spot);
void printCoord(COORD a);
void printFrameCoord(Frame a);
int drawMenu();

