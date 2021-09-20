#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
	{	
		int son;
		int age=10; 
		for(;age<=100;age=age+2)
			{	
				son=age/2;
				int real=age-4;
				if( age*11%28==0)
					if	(age*11/28+5+son+4==age)
						cout<<real<<endl;
		    }
		system("pause");
		return 0;
	}
