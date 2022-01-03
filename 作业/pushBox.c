#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h>


//宏定义 
#define WIDTH 13 
#define HEIGHT 13 
int map[HEIGHT][WIDTH] = { 
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},    
{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},    
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1},    
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},    
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1},    
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},    
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1}, 
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1},
{1, 1, 0, 3, 0, 3, 0, 0, 3, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 
int x, y; 
int boxs;
int gCount=0;
int gFlag=0;


void initData()
{
	int i, j; 
    int a=2, b=6;
	printf("游戏加载中，请稍后........."); 
	if(!gFlag){
    	map[1][1]=2;
    	map[10][3]=map[10][5]=map[10][8]=map[4][10]=map[6][10]=map[8][10]=3;
		map[10][9]=map[2][10]=3;
        b=2;
    }

	for(i = 0; i < HEIGHT; i++)
	{ for(j = 0; j < WIDTH; j++){ 
		if(map[i][j] == a ||map[i][j] == b){ x = i; y = j; } 
		else if(map[i][j] == 3){ boxs++; } 
	}
	}
    gFlag=0;
}
void drawMap()
{
	int i,j;
	printf("-----------第%02d关---------------\n",gCount);
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<HEIGHT;j++)
		{
			if(map[i][j]==0)
				printf("  ");
			else if(map[i][j]==1)
				printf("\033[36m■\033[0m");
			if(map[i][j]==2)
				printf("♀");
			if(map[i][j]==3)
				printf("◆");
			if(map[i][j]==4||map[i][j]==6)
				printf("\033[31m●\033[0m"); 
			else if(map[i][j]==5)
				printf("\033[33m★\033[0m");
		}
		printf("\n");
	}
}
void moveUp()
{
	switch(map[x][y])
	{
	case 2:
		if(map[x-1][y]==3)
		{
			if(map[x-2][y]==0)
			{
				map[x-2][y]=3;
				map[x-1][y]=2;
				map[x][y]=0;
			}
			else if(map[x-2][y]==4)
			{
				map[x-2][y]=5;
				map[x-1][y]=2;
				map[x][y]=0;				
				boxs--;
			}
			else
			{
				x=x+1;
			}
		}
		else if(map[x-1][y]==1 || map[x-1][y]==5)
		{
			x=x+1;
		}
		else if(map[x-1][y]==4)
		{
			map[x-1][y]=6;
			map[x][y]=0;
		}
		else if(map[x-1][y]==0)
		{
			map[x-1][y]=2;
			map[x][y]=0;
		}
		break;
	case 6:
		if(map[x-1][y]==3)
		{
			if(map[x-2][y]==0)
			{
				map[x-2][y]=3;
				map[x-1][y]=2;
				map[x][y]=4;
			}
			else if(map[x-2][y]==4)
			{
				map[x-2][y]=5;
				map[x-1][y]=2;
				map[x][y]=4;				
				boxs--;
			}
			else
			{
				x=x+1;
			}
		}
		else if(map[x-1][y]==1 || map[x-1][y]==5)
		{
			x=x+1;
		}		
		else if(map[x-1][y]==0)
		{
			map[x-1][y]=2;
			map[x][y]=4;
		}
		break;
	}
	x=x-1;	
}
void moveDown()
{
	switch(map[x][y])
	{
	case 2:
		if(map[x+1][y]==3)
		{
			if(map[x+2][y]==0)
			{
				map[x+2][y]=3;
				map[x+1][y]=2;
				map[x][y]=0;
			}
			else if(map[x+2][y]==4)
			{
				map[x+2][y]=5;
				map[x+1][y]=2;
				map[x][y]=0;				
				boxs--;
			}
			else
			{
				x=x-1;
			}
		}
		else if(map[x+1][y]==1 || map[x+1][y]==5)
		{
			x=x-1;
		}
		else if(map[x+1][y]==4)
		{
			map[x+1][y]=6;
			map[x][y]=0;
		}
		else if(map[x+1][y]==0)
		{
			map[x+1][y]=2;
			map[x][y]=0;
		}
		break;
	case 6:
		if(map[x+1][y]==3)
		{
			if(map[x+2][y]==0)
			{
				map[x+2][y]=3;
				map[x+1][y]=2;
				map[x][y]=0;
			}
			else if(map[x+2][y]==4)
			{
				map[x+2][y]=5;
				map[x+1][y]=2;
				map[x][y]=0;				
				boxs--;
			}
			else
			{
				x=x-1;
			}
		}
		else if(map[x+1][y]==1 || map[x+1][y]==5)
		{		
			x=x-1;
		}		
		else if(map[x+1][y]==0)
		{
			map[x+1][y]=2;
			map[x][y]=4;
		}
		break;
	}
	x=x+1;	
}
void moveLeft()
{
	switch(map[x][y])
	{
	case 2:
		if(map[x][y-1]==3)
		{
			if(map[x][y-2]==0)
			{
				map[x][y-2]=3;
				map[x][y-1]=2;
				map[x][y]=0;
			}
			else if(map[x][y-2]==4)
			{
				map[x][y-2]=5;
				map[x][y-1]=2;
				map[x][y]=0;
				boxs--;
			}
			else
			{
				y=y+1;
			}
		}
		else if(map[x][y-1]==1 || map[x][y-1]==5)
		{
			y=y+1;
		}
		else if(map[x][y-1]==4)
		{
			map[x][y-1]=6;
			map[x][y]=0;
		}
		else if(map[x][y-1]==0)
		{
			map[x][y-1]=2;
			map[x][y]=0;
		}
		break;
	case 6:
		if(map[x][y-1]==3)
		{
			if(map[x][y-2]==0)
			{
				map[x][y-2]=3;
				map[x][y-1]=2;
				map[x][y]=4;
			}
			else if(map[x][y-2]==4)
			{
				map[x][y-2]=5;
				map[x][y-1]=2;
				map[x][y]=4;				
				boxs--;
			}
			else
			{
				y=y+1;
			}
		}
		else if(map[x][y-1]==1 || map[x][y-1]==5)
		{
			y=y+1;
		}		
		else if(map[x][y-1]==0)
		{
			map[x][y-1]=2;
			map[x][y]=4;
		}
		break;
	}
	y=y-1;	
}

void moveRight()
{
	switch(map[x][y])
	{
	case 2:
		if(map[x][y+1]==3)
		{
			if(map[x][y+2]==0)
			{
				map[x][y+2]=3;
				map[x][y+1]=2;
				map[x][y]=0;
			}
			else if(map[x][y+2]==4)
			{
				map[x][y+2]=5;
				map[x][y+1]=2;
				map[x][y]=0;				
				boxs--;
			}
			else
			{
				y=y-1;
			}
		}
		else if(map[x][y+1]==1 || map[x][y+1]==5)
		{
			y=y-1;
		}
		else if(map[x][y+1]==4)
		{
			map[x][y+1]=6;
			map[x][y]=0;
		}
		else if(map[x][y+1]==0)
		{
			map[x][y+1]=2;
			map[x][y]=0;
		}
		break;
	case 6:
		if(map[x][y+1]==3)
		{
			if(map[x][y+2]==0)
			{
				map[x][y+2]=3;
				map[x][y+1]=2;
				map[x][y]=4;
			}
			else if(map[x][y+2]==4)
			{
				map[x][y+2]=5;
				map[x][y+1]=2;
				map[x][y]=4;				
				boxs--;
			}
			else
			{
				y=y-1;
			}
		}
		else if(map[x][y+1]==1 || map[x][y+1]==5)
		{
			y=y-1;
		}		
		else if(map[x][y+1]==0)
		{
			map[x][y+1]=2;
			map[x][y]=4;
		}
		break;
	}
	y=y+1;	
}
int gLoad=1;
char gLine[120]={0};

void loadProcessCnt()
{
	FILE *fpt=fopen("process.txt","r");
	if(!fpt)                                        
    {
        strcpy(gLine,"");
        return ;
    }
	if(fgets(gLine,120,fpt)==NULL)                  
	{
		printf("FGets error!\n");
		return ;
	}
	if(!strncmp(gLine,"gCount",strlen("gCount")))
	{
		strtok(gLine,":");
		gLoad=atoi(strtok(NULL,":"));
	}

	if(fgets(gLine,120,fpt)==NULL)
	{
		printf("FGets error!\n");
        strcpy(gLine,"");
		return ;
	}
    gFlag=1;
	fclose(fpt);
}
char *strtok_w(char *str, const char *delim, char**save)
{	
	const char *indelim=delim;                    
    int flag=1,index=0;                                
                                                  
    char *temp=NULL;                              
 
    if(str==NULL)
    {
       str=(*save);                                   
    }
    for(;*str;str++)
    {
       delim=indelim;
       for(;*delim;delim++)
       {
           if(*str==*delim)
           {
               *str='\0';                  
               index=1;                    
               break;
           }
       }
       if(*str != '\0' && flag==1)
       {
          temp=str;                         
          flag=0;  
       }
      if(*str != '\0' && flag==0 && index==1)
	  {
         (*save)=str;                                   
         return temp;
	  }
    }
    (*save)=str;                              
                                                    
    return temp;
}
void loadProcessMap()
{
	int i;
	char *str1,*str2,*str3,*token,*subt,*subtt;
	char *savept1,*savept2,*savept3;
    int x,y;
    static int cnt=0;

    if(cnt==0)
    {
    	for(i=2,str1=gLine;;i++,str1=NULL)
    	{
    		token=strtok_w(str1,":",&savept1);
    		if(token==NULL)
    			break;
    		
    		for(str2=token;;str2=NULL)
    		{
    			subt=strtok_w(str2,"/",&savept2);
    			if(subt==NULL)
    				break;

    			for(str3=subt;;str3=NULL)
    			{
    				subtt=strtok_w(str3,",",&savept3);
    				if(subtt==NULL)
    					break;
                    x=atoi(subtt);
                    y=atoi(strtok_w(NULL,",",&savept3));
                    if(x!=0&&y!=0)
    				    map[x][y]=i;
    			}
    		}
    	}
        cnt++;
    }

}
/*1,2:3,4/4,3:4,4/8,8:5,5/7,6*/
void saveProcess()
{
	FILE *fpt=fopen("process.txt","w");
	int i,j;
	int person[2]={-1,-1};
	int box[16],b=0;
	int dest_p[2]={-1,-1},dp=0;
	int box_dest[16],bd=0;
	if(!fpt)return ;
	fprintf(fpt,"gCount:%d\n",gCount);
	fflush(fpt);

	for(i=1;i<HEIGHT-1;i++)
	{
		for(j=1;j<WIDTH-1;j++)
		{
			switch(map[i][j])
			{
			case 2:
				person[0]=i;
				person[1]=j;
				break;
			case 3:
				box[2*b]=i;
				box[2*b+1]=j;
				b++;
				break;
			case 4:

				break;
			case 5:
				box_dest[2*bd]=i;
				box_dest[2*bd+1]=j;
				bd++;
				break;
            case 6:
                dest_p[0]=i;
                dest_p[1]=j;
                dp++;
                break;
			}
		}
	}
    if(!dp)
	    fprintf(fpt,"%d,%d:",person[0],person[1]);
    else
        fprintf(fpt,"0,0:");
	for(i=0;i<b;i++)
	fprintf(fpt,"%d,%d/",box[2*i],box[2*i+1]);
	fprintf(fpt,":");

	fprintf(fpt,"0,0:");
	if(bd==0)
        fprintf(fpt,"0,0:");
	else{
		for(i=0;i<bd-1;i++)
		fprintf(fpt,"%d,%d/",box_dest[2*i],box_dest[2*i+1]);
		fprintf(fpt,"%d,%d:",box_dest[2*i],box_dest[2*i+1]);
    }
    if(dp)
	    fprintf(fpt,"%d,%d",dest_p[0],dest_p[1]);    
    else
        fprintf(fpt,"0,0");
    fprintf(fpt,"\n");

	fflush(fpt);
	fclose(fpt);
}

void play()
{ 
   int direction;	
   
   initData();
   while(1){
   system("cls");
   drawMap();
   if(!boxs)
   { map[x][y]=0;break; } 
   direction = getch(); 
   if(direction=='q')
   {
	   saveProcess();
	   exit(1) ;
   }
   switch(direction){
   case 72:  moveUp(); break;
   case 75:   moveLeft(); break; 
   case 80:   moveDown(); break; 
   case 77: moveRight(); break;
	  } 
   } 
   printf("恭喜你完成游戏！\n");

   return;
}
int gPlace[WIDTH]={0};

int isValid(int r,int cl)
{
    int row,col;
	
    for(row=2;row<r;row++)
    {
		col=gPlace[row];
        
        if(col==cl)
            return 0;
        else if(r-row==cl-col)
            return 0;
        else if(r-row==col-cl)
            return 0;
    }
    return 1;
}


void queen(int index)
{
    int i,k;
    for(i=2;i<10;i++)
    {
        if(isValid(index+2,i))
        {
            gPlace[index+2]=i;
			
            if(index==7)
            {      
				gPlace[index+2]=i;
				gCount++;
				if(gCount==gLoad)
				{
					for(k=1;k<HEIGHT-1;k++)
						memset(&map[k][1],0,4*(WIDTH-2));
					for(k=2;k<=9;k++)
						map[k][gPlace[k]]=4;	
					
					loadProcessMap();
					play();					
					for(k=2;k<=9;k++)
						map[k][gPlace[k]]=0;	
					gLoad++;
				}
				gPlace[index+2]=0;
                return;
            }
            queen(index+1);
			gPlace[index+2]=0;            
        }
    }
}



int main(int argc, char *argv[])
{
	loadProcessCnt();
	queen(0);
	return 0;
}
