#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define LEN 10000

void input(char** p);//��������С��10000���ȵ��ַ�������


int rand0(int a);//α�����

void encrypt(char *p1);//���ܺ���

void decrypt(int *p2);//���ܺ���

int main(void){
    char *pst;
    int ar3[LEN];
    encrypt(pst);
    decrypt(ar3);
    

    return 0;
}

int rand0(int a){
    int b=a*1103515245+12345;
    return (unsigned int) (b/65536)%32768;
}

void encrypt(char *p1){
    printf("������Ҫ���ܵ����ݣ������ִ�Сд��ĸ�����԰������֡���ĸ��Ӣ������״̬�ķ��ţ��ո񡢻س����⣩\n");
    
    input(&p1);
    int length=strlen(p1);
    int *ar2;
    ar2= (int *) malloc ((length+1) * sizeof(int));//�ַ�תASCII�����м��ܼ���

    printf("�����벢��ס���루11��999���������֣���\n");
    scanf("%d",&ar2[0]);//���������

    int ss=rand0(ar2[0]);//�������������һ����

    for(int i=0;i<length;i++){
        ar2[i+1]=p1[i]*ss+ss;//����
    }

    printf("���ܽ����\n");
    int count=0;
    for(int i=1;i<length+1;i++){
        printf("%d",ar2[i]);
        if(count<length-1){
            printf(" ");//�ո�ָ�����Ԫ��
        }
        count++;
    }
    printf("\n");

    free(ar2);
}

void decrypt(int ar3[]){
    printf("��������ֶΣ��Ա��ո�ֿ�Ϊһ�Σ�����������ݣ���һ��Ϊ���롣�������-1���س���ʾ������\n");
    int count=-1;//�����ж������ֶ�,���˿�ͷ�������-1

    for (int i=0;i<LEN;i++){
        scanf("%d",&ar3[i]);
        if (ar3[i]==-1){
            break;
        }
        count++;
    }
    int ss=rand0(ar3[0]);//��������Զ�����

    char *ar4;
    ar4=(char *) malloc(count * sizeof (char));//������ܽ��

    for(int i=0;i<count;i++){
        ar4[i]=(ar3[i+1]-ss)/ss;
    }

    printf("���Ľ��ܽ���ǣ�\n");
    for (int i=0;i<count;i++){
    	printf("%c",ar4[i]);
	}

    free(ar4);
}


void input(char** p) {
    char temp[LEN];
    scanf("%s", temp);
    *p = (char*)malloc(strlen(temp) + 1);
    strcpy(*p,temp);

}

