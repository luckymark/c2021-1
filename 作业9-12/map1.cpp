#include<stdio.h>
int g_map[10][12] = 
{
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },

	{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0 },

	{ 1, 0, 4, 0, 1, 0, 1, 1, 1, 1, 1, 1 },

	{ 1, 0, 4, 6, 1, 0, 1, 0, 0, 0, 3, 1 },

	{ 1, 1, 1, 4, 1, 1, 1, 0, 0, 0, 3, 1 },

	{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 1 },

	{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },

	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 }
};
int	main(){
 for(int i=0;i<10;i++){
  for(int k=0;k<12;k++){
   switch(g_map[i][k]){
    case 0:
     printf("  ");
     break;
    case 1:
     printf("��");
     break;
    case 3:
     printf("��");
     break;
    case 4:
     printf("��");
     break;
    case 6://��
     printf("��");
     break;
    case 7:
     printf("��");
     break;
    case 9:
     printf("��");
     break;
   }
  }
  printf("\n");
 }
}
