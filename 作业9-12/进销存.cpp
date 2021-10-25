#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
typedef	struct	goods{
	char *name;
	int	number;
}goods;
typedef	struct	Node{
	goods	good;
	struct	Node*pre,*next;
}Node;
Node*head,*tail;
void	newNode(){
	Node*	pretail=tail;
	if(tail==NULL){
		tail=head=(Node*)malloc(sizeof(Node));
	}
	else	{
		(*tail).next=(Node*)malloc(sizeof(Node)); 
		tail=(*tail).next;
	}
	if(pretail!=NULL){
		(*pretail).next=tail;
	}
	(*tail).pre=pretail;
	(*tail).next=NULL;
}
int	main(){
	char	name_of_good[101];
	int	number_of_good;
	printf("菜单\n");
	printf("1.显示存货列表\n");
	printf("2.入库\n");
	printf("3.出库\n");
	printf("4.退出程序\n");
	FILE	*fp=fopen("WAREHOUSE.txt","r");
	while(fscanf(fp,"%s%d",name_of_good,&number_of_good)!=EOF){
		newNode();
		int	len=strlen(name_of_good);
		(*tail).good.name=(char*)malloc(sizeof(char)*(len+1));
		strcpy((*tail).good.name,name_of_good);
		(*tail).good.number=number_of_good;
	}
	fclose(fp);
	int	op;
	while(1){
		scanf("%d",&op);
		if(op==1){
			for(Node* p=head;p!=NULL;p=(*p).next){
				printf("%s	%d\n",(*p).good.name,(*p).good.number);
			}
		}
		else	if(op==2){
			printf("入库	型号	数量\n");
			scanf("%s%d",name_of_good,&number_of_good);
			int	isFind=0;
			for(Node* p=head;p!=NULL;p=(*p).next){
				if(strcmp((*p).good.name,name_of_good)==0){
					(*p).good.number+=number_of_good;
					isFind=1;
					break;
				}
			}
			if(!isFind){
				newNode();					
				int	len=strlen(name_of_good);
				(*tail).good.name=(char*)malloc(sizeof(char)*(len+1));
				strcpy((*tail).good.name,name_of_good);
				(*tail).good.number=number_of_good;
			}
		}
		else	if(op==3){
			int	Find=0;
			printf("出库	型号	数量\n");
			scanf("%s%d",name_of_good,&number_of_good);
			for(Node*p=head;p!=NULL;p=(*p).next){
				if(strcmp((*p).good.name,name_of_good)==0){
					(*p).good.number-=number_of_good;
					Find++;
					break;
					}
				}
			if(Find==0){
				printf("无此商品！");
			}
		}
		else	if(op==4){
			exit(0);
			break;
		}
		else{
			exit(0);
			break;
		}
}
	fp=fopen("WAREHOUSE.txt","w");
	for(Node*p=head;p!=NULL;p=(*p).next){
	fprintf(fp,"%s	%d\n",(*p).good.name,(*p).good.number);
	}
	fclose(fp);
	return	0;
}
