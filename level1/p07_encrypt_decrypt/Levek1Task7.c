#include<bits\stdc++.h>
char Decryption_password[10],Encryption_password[10];
int length;
void encrypt(char s[]){
    printf("Please enter your encryption password(no more than 10 digits):\n");
    scanf("%s",&Encryption_password);
    char temp[100];
    strcpy(temp,s);
    for(int i=0;i<length/strlen(Encryption_password)+1;i++)
        for(int j=0;j<strlen(Encryption_password)&&i*strlen(Encryption_password)+j<length;j++)
            temp[i*strlen(Encryption_password)+j]^=Encryption_password[j];
    strcpy(s,temp);
    printf("Encrypted successfully!\nNow the string becomes:%s\n",s);
    return;
}()
void decrypt(char s[]){
    printf("Please enter your decryption password(no more than 10 digits):\n");
    while(scanf("%s",&Decryption_password)){
        if(strcmp(Encryption_password,Decryption_password)){
            printf("Wrong password!Please enter right password!\n");
            continue;
        }
        else break;
    }
    char temp[100];
    strcpy(temp,s);
    for(int i=0;i<length/strlen(Decryption_password)+1;i++)
        for(int j=0;j<strlen(Decryption_password)&&i*strlen(Decryption_password)+j<length;j++)
            temp[i*strlen(Decryption_password)+j]^=Decryption_password[j];
    strcpy(s,temp);
    printf("Decrypted successfully!\nThe string you needed is:\n%s\n",s);
    return;
}
int main(){
    char s[100];
    printf("Please enter a string you want to encrypt(no more than 100 digits):\n");
    scanf("%s",&s);
    length=strlen(s);
    encrypt(s);
    decrypt(s);
    system("pause");
    return 0;
}