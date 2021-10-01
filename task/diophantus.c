//
// Created by Durant on 2021/9/14.
//
#include <stdio.h>
int main(void){
    int son;
    int year;//儿子死时丢番图多少岁
    for (int father=9;father<150;father++){//婚后五年得子，儿子先死四年可知至少9岁
        if (father%2==0 &&father%12==0 &&father%28==0){//因为可整除6，必为偶数;青年过了1/12；结婚前过了11/28
            son=father*17/28-9;//父亲年龄*婚后的寿命占比-（生子时间+儿子先死多少年）
            if(2*son==father){//儿子寿命为父亲一半
                year=father-4;
                printf("儿子死时丢番图%d岁。\n",year);
            }

        }

    }
    return 0;
}
