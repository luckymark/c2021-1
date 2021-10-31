#include<cstdio>
#include<cstdlib>
int main() {
	int a;
	//scanf_s("%d", &a);
	cin>>a;
		for (int i = 2;i <= a;i++) {
			if (a%i == 0 && i != a) cout<<"no"; //printf ("no");
			if (i == a) cout<<"yes"; //printf("yes");
		}
	return  0;

}
