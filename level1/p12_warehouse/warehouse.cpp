#include <stdio.h>
//author: Simon
 
int writeInfoToFile(char *strFile)
{
	int i;
	char name[20];
	FILE *fp;
	fp = fopen(strFile, "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	printf("Note: please input three time names,every name's length less than 20 character\n");
	for(i=0; i<3; i++)
	{
		if(i==2){
			printf("Now,Open another terminal and change the name of the document to other\n");
			printf("input the third name:\n");
                	scanf("%s", name);
                	fprintf(fp, "%s\n", name);
			break;
		}
		printf("input name:\n");
		scanf("%s", name);
		fprintf(fp, "%s\n", name);
	}

	fclose(fp);
	
}

int main()
{
	char file[20] = "data.txt";
	writeInfoToFile(file);
}

