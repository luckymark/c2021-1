#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <string.h>
#define N 100
using namespace std;
//加密公式 f(a)=(a+3) mod 26
//解密公式 f(a)=(a+23) mod 26
void Encry(char *strI,int numB,int model);
void Decry(char *strI,int numB,int model);
int FileOut(char *strI);
int main()
{
    char str[N];
    int model;
    int numB;
    while(1)
    {
        cout<<"select model\n";
        cout<<"1.Encry\n";
        cout<<"2.Decry \n";
        cout<<"3.quit\n";
        cin>>model;
        cout<<endl;
        switch(model)
        {
            case 1:
                cout<<"code";
                cin>>str;
                cout<<"how long you want";
                cin>>numB;
                Encry(str,numB,model);
                cout<<endl;
                break;
            case 2:
                cout<<"code";
                cin>>str;
                cout<<"how long it is";
                cin>>numB;
                Decry(str,numB,model);
                cout<<endl;
                break;
            case 3:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
void Encry(char *strI,int numB,int model)
{
    if(model==1)
    {
        for(int i=0; i<strlen(strI); i++)
        {
            if(strI[i] >= 'A' && strI[i] <= 'Z')
            {
                strI[i] = ((strI[i]-'A')+numB)%26+'A';
            }
            else if(strI[i] >= 'a' && strI[i] <= 'z')
            {
                strI[i] = ((strI[i]-'a')+numB)%26+'a';
            }
        }
        cout<<"finished"<<strI<<endl;
        FileOut(strI);
        cout<<"output already"<<endl;
    }
    else
    {
        cout<<"do not have this model"<<endl;
    }
}
void Decry(char *strI,int numB,int model)
{
    if(model==2)
    {
        int num;
        num=26-numB;
        for(int i=0; i<strlen(strI); i++)
        {
            if(strI[i] >= 'A' && strI[i] <= 'Z')
            {
                strI[i] = ((strI[i]-'A')+num)%26+'A';
            }
            else if(strI[i] >= 'a' && strI[i] <= 'z')
            {
                strI[i] = ((strI[i]-'a')+num)%26+'a';
            }
        }
        cout<<"output already"<<strI<<endl;
    }
    else
    {
        cout<<"do not have this model"<<endl;
    }
}
int FileOut(char *strI)
{
    FILE *fp = NULL;
    int iWrite=0;
    int len=strlen(strI);
    if( strI == NULL || len ==0 )
        return false;
    if( (fp = fopen( "edit.txt","w" )) == NULL )
        return false;
    iWrite = fwrite(strI, 1, len, fp );
    fclose(fp);
    if( iWrite>0 )
        return true;
    else
        return false;
}
