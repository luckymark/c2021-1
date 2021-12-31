# include<stdio.h>
# include<windows.h>
# include<string.h>
# include<conio.h>
void main()
{
    int sele;
    Re_file();    //��ȡ��Ʒ��Ϣ 
    sele = 1;
    while (sele)
    {
        system("cls");
        printf("\n\n");
        printf("*********************************************\n");
        printf("*                                           *\n");
        printf("*       1.���              2.����          *\n");
        printf("*                                           *\n");
        printf("*       3.��ѯ              4.�˳�          *\n");
        printf("*                                           *\n");
        printf("*********************************************\n");
        printf("��ѡ�������:");
        scanf("%d", &sele);
        switch (sele)
        {
        case 1:Stock_in(); Display(); break;
        case 2:Stock_out(); Display(); break;
        case 3:Query(); break;
        case 4:exit(0); sele = 0; break;
        }
        printf("\n\n�����������...\n");
        getch();
    }
    Wr_file();
}
typedef struct
{
#define M 50
    int num;			    //��Ʒ���
    char name[20];		  	//��Ʒ����
    int stock;			    //ԭʼ���
    int in;				   	//�����Ŀ
    int out;			    //������Ŀ
    int amount;			   	//���տ��
    int warning_value;	   	//����ֵ
    int state;			    //���״̬(�Ƿ���ھ���ֵ)
}goods;
goods s[M];				//���ڴ�Ż�Ʒ��Ϣ 
goods r[M];				//���ڴ������Ʒ��Ϣ 
goods t[M];				//���ڴ�ų����Ʒ��Ϣ
void Re_file()		//����ԭʼ����ļ�
{
    FILE* fp;
    N = 0;
    fp = fopen("goods.txt", "r");
    while (fscanf(fp, "%d%s%d%d%d%d%d", &s[N].num, &s[N].name, &s[N].stock, &s[N].in, &s[N].out, &s[N].amount, &s[N].warning_value) != EOF)
        N++;
    fclose(fp);
    P = N;
}
void Stock_in()		//��������ļ�
{
    FILE* fp;
    int i, j;
    N = 0;
    fp = fopen("stockin.txt", "r");
    while (fscanf(fp, "%d%d", &r[N].num, &r[N].in) != EOF)
        N++;
    fclose(fp);
    for (i = 0; i < P; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (r[i].num == s[j].num)
                s[j].in = r[j].in;
        }
    }
    for (i = 0; i < P; i++)
        s[i].amount = s[i].stock + s[i].in;
}
void Stock_out()	//��������ļ�
{
    FILE* fp;
    int i, j;
    N = 0;
    fp = fopen("stockout.txt", "r");
    while (fscanf(fp, "%d%d", &t[N].num, &t[N].out) != EOF)
        N++;
    fclose(fp);
    for (i = 0; i < P; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (t[i].num == s[j].num)
                s[j].out = t[j].out;
        }
    }
    for (i = 0; i < P; i++)
        s[i].amount = s[i].stock + s[i].in - s[i].out;
}
int Wr_file()
{
    FILE* fp;
    int i;
    fp = fopen("amount.txt", "w");
    for (i = 0; i < P; i++)
        fprintf(fp, "%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n", s[i].num, s[i].name, s[i].stock, s[i].in, s[i].out, s[i].amount, s[i].warning_value);
    fclose(fp);
    return 1;
}