#pragma once
class board {
private:
	int pre[16][16];
	long long value;
public:
	void initboard();//��ʼ����������
	void draw(int x, int y, int color);//��������
	int readboard(int x, int y);//���ص�ǰ���ӵ�״̬
	void readplayer();//��ȡ�����������Ϣ
	void mango();
	void aigo();//��������
	bool close(int x, int y);//�ж���ǰ�����Ƿ�����ֺܽ�
	long long cal_line(int line, int color);
	long long cal_colume(int colume, int color);
	long long cal_diagonal(int dis,int color);
	long long cal_backdiagonal(int dis,int color);
	long long  calculate();//����ʽ�����ι�ֵ����     ps.��ֵ����Ҳ�������ж���Ϸ�Ƿ����
	long long max_min_dfs(int depth, long long alpha, long long beta);//����ֵ-��Сֵ���� + alpha-beta��֦
	int Checkover();//0-> δ������1->AIʤ����2->���ʤ��
	
	
};	