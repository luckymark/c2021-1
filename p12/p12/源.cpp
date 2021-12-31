# include<stdio.h>
# include<windows.h>
# include<string.h>
# include<conio.h>
void main()
{
    int sele;
    Re_file();    //读取货品信息 
    sele = 1;
    while (sele)
    {
        system("cls");
        printf("\n\n");
        printf("*********************************************\n");
        printf("*                                           *\n");
        printf("*       1.入库              2.出库          *\n");
        printf("*                                           *\n");
        printf("*       3.查询              4.退出          *\n");
        printf("*                                           *\n");
        printf("*********************************************\n");
        printf("请选择功能序号:");
        scanf("%d", &sele);
        switch (sele)
        {
        case 1:Stock_in(); Display(); break;
        case 2:Stock_out(); Display(); break;
        case 3:Query(); break;
        case 4:exit(0); sele = 0; break;
        }
        printf("\n\n按任意键继续...\n");
        getch();
    }
    Wr_file();
}
typedef struct
{
#define M 50
    int num;			    //货品编号
    char name[20];		  	//货品名称
    int stock;			    //原始库存
    int in;				   	//入库数目
    int out;			    //出库数目
    int amount;			   	//最终库存
    int warning_value;	   	//警戒值
    int state;			    //库存状态(是否低于警戒值)
}goods;
goods s[M];				//用于存放货品信息 
goods r[M];				//用于存放入库货品信息 
goods t[M];				//用于存放出库货品信息
void Re_file()		//读入原始库存文件
{
    FILE* fp;
    N = 0;
    fp = fopen("goods.txt", "r");
    while (fscanf(fp, "%d%s%d%d%d%d%d", &s[N].num, &s[N].name, &s[N].stock, &s[N].in, &s[N].out, &s[N].amount, &s[N].warning_value) != EOF)
        N++;
    fclose(fp);
    P = N;
}
void Stock_in()		//读入入库文件
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
void Stock_out()	//读入出库文件
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