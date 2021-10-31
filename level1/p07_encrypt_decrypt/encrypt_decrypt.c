#include <stdio.h>
#define LENTH 100

int encrypt(const char * input,int * results);
int decrypt(const int * input,char * results);

int main()
{
    char input[LENTH];
    int encryptResults[LENTH];
    char decryptResults[LENTH];

    printf("Please input a English sentence.\n");
    gets_s(input,LENTH-1);

    encrypt(input,encryptResults);

    decrypt(encryptResults,decryptResults);

    printf("The result of the deciphering is : \n%s ",decryptResults);

    return 0;


}

int encrypt(const char * input,int * results)
{
    for (int i = 0; i < LENTH-1 && input[i-1] != '\0'; ++i)
    {
        int  loo;
        if(i > 0)
             loo = (int)input[i-1];
        else
             loo = 1;
        results[i] = loo * input[i];
    }
    return 0;
}

int decrypt(const int * input,char * results)
{
    for (int i = 0; i < LENTH-1; ++i)
    {
        int loo;
        if(i > 0)
            loo = (int)results[i-1];
        else
            loo = 1;
        if(loo != 0)
            results[i] = (char)(input[i]/loo);
        else
            break;
    }
    return 0;
}