#include <stdio.h>


int equal(float,float);
int main()
{
    for(int age=10;age <= 200 ;age++)
    {
        if(equal(age/6.0+age/12.0+age/7.0+5+age/2+4,age))
            printf("Diophantus may be %d years old when his son died. ",age-4);
    }
    return 0;
}

int equal(float a ,float b)
{
    if(a>=b)
    {
        if(a-b<1.0e-6)
            return 1;
        else
            return 0;
    }
    else
    {
        if(b-a<1.0e-6)
            return 1;
        else
            return 0;
    }
}

