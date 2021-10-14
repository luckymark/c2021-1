#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define INF 0x7f7f7f7f

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) {int T=x; x=y; y=T;}
#define wipe(x,y) memset(x,y,sizeof(x))
#define rep(x,y,z) for(int x=y,I=z;x<=I;++x)

#define dbgIn(x) freopen(x".in","r+",stdin)
#define dbgOut(x) freopen(x".out","w+",stdout)

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

inline void Read(int &x){
	x=0; char ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct Item{
	int cnt;
	char model[60];
};

vector<Item>v;

int op;
int size;

void PrintMenu(){
	printf("----------Menu----------\n");
	printf("1.Get warehouse list\n");
	printf("2.In-warehouse\n");
	printf("3.Ex-warehouse\n");
	printf("Other.Exit\n");
	printf("------------------------\n");
	return;
}

void ReadfromFile(){
	FILE *fp=0;
	Item tmp;
	v.push_back(tmp);
	fp=fopen("res.txt","r+");
	//freopen("res.txt","r",stdin);
	fscanf(fp,"%d",&size);
	rep(i,1,size){
		fscanf(fp,"%s %d",&tmp.model,&tmp.cnt);
		v[i]=tmp;
	}
	fclose(fp);
	//freopen("CON","r",stdin);
	return;
}

void StoretoFile(){
	//freopen("res.txt","w+",stdout);
	FILE *FP=0;
	FP=fopen("res.txt","w+");
	fprintf(FP,"%d\n",size);
	rep(i,1,size)
		fprintf(FP,"%s %d\n",v[i].model,v[i].cnt);
	fclose(FP);
	return;
}

void PrintList(bool mode){
	system("cls");
	printf("Total %d Item(s)\n",size);
	rep(i,1,size)
		printf("Id:%d,Name:%s,Count:%d\n",i,v[i].model,v[i].cnt);
	if(mode){
		system("pause");
		system("cls");
	}
	return;
}

void In_warehouse(){
	bool exist=0;
	Item tmp;
	system("cls");
	printf("Name:");
	scanf("%s",&tmp.model);
	printf("Count:");
	scanf("%d",&tmp.cnt);
	if(tmp.cnt<0){
		printf("Error!\n");
		system("pause");
		return;
	}
	rep(i,1,size){
		if(!strcmp(tmp.model,v[i].model)){
			exist=1;
			v[i].cnt+=tmp.cnt;
			break;
		}
	}
	if(!exist)
		v[++size]=tmp;
	system("pause");
	return;
}

void Ex_warehouse(){
	int od,ct;
	PrintList(0);
	printf("Please input the item ID:");
	scanf("%d",&od);
	if(od<=0 || od>size){
		printf("Error!\n");
		system("pause");
		return;
	}
	printf("Please input amount:");
	scanf("%d",&ct);
	if(od<0){
		printf("Error!\n");
		system("pause");
		return;
	}
	if(ct>v[od].cnt){
		printf("Item not enough!\n");
		system("pause");
		return;
	}
	v[od].cnt-=ct;
	printf("Succeeded!\n");
	system("pause");
	return;
}

int main(){
	ReadfromFile();
	while(1){
		PrintMenu();
		scanf("%d",&op);
		if(op==1)
			PrintList(1); 
		else if(op==2)
			In_warehouse();
		else if(op==3)
			Ex_warehouse();
		else{
			StoretoFile();
			return 0;
		}
		system("cls");
	}
	return 0;
}
