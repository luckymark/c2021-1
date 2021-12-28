#include <stdio.h>
#include <conio.h>
int main(){
	char ch;
	int i,j;
	int m=1;
	int n=1;
char map[6][7]={"######\n",
                "#o #  \n",
				"# ## #\n", 
				"#  # #\n",
				"##   #\n",
				"######\n"};
printf("%s",map);
while((ch = getch())!= 0x1B){
	if(map[1][5]=='o'){system("cls");
printf("YOU WIN");
exit(1);}
switch(ch = getch()){
case 72:system("cls") ;
for(i=0;i<=6;i++)
{for(j=0;j<=6;j++)
{if(map[i][j]=='#'){map[i][j]='#';
}else if(map[i][j]==' '){map[i][j]==' ';
}else if(map[i][j]=='o'){if(map[i-1][j]==' ')	
{map[i][j]=' ';
map[i-1][j]='o';
}}else if(map[i][j]=='\n'){map[i][j]=='\n';
}
}
}printf("%s",map);
break;
case 80:system("cls") ;
m=1;
for(i=0;i<=6;i++)
{for(j=0;j<=6;j++)
{if(map[i][j]=='#'){map[i][j]=='#';
}else if(map[i][j]==' '){map[i][j]==' ';
}else if(map[i][j]=='o'&&m==1){if(map[i+1][j]==' ')	
{map[i][j]=' ';
map[i+1][j]='o';
m=0;
}}else if(map[i][j]=='\n'){map[i][j]=='\n';
}
}
}printf("%s",map);break;
case 75:system("cls") ;
for(i=0;i<=6;i++)
{for(j=0;j<=6;j++)
{if(map[i][j]=='#'){map[i][j]=='#';
}else if(map[i][j]==' '){map[i][j]==' ';
}else if(map[i][j]=='o'){if(map[i][j-1]==' ')	
{map[i][j]=' ';
map[i][j-1]='o';
}}else if(map[i][j]=='\n'){map[i][j]=='\n';
}
}
}printf("%s",map);break;
case 77:system("cls") ;
n=1;
for(i=0;i<=7;i++)
{ for(j=0;j<=7;j++)
{if(map[i][j]=='#'){map[i][j]=='#';
}
else if(map[i][j]==' '){map[i][j]==' ';
}else if(map[i][j]=='o'&&n==1){if(map[i][j+1]==' ')	
{map[i][j]=' ';
map[i][j+1]='o';
n=0;
}}else if(map[i][j]=='\n'){map[i][j]=='\n';
}
}
}printf("%s",map);break;
default : break;
}
}return 0;
}
