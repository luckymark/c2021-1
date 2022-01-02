#include <iostream>
#include <stdio.h>
using namespace std;
void move(int n,const char *a, const char *b, const char *c){
    if(n > 0){
        move(n-1, a , c , b);
        cout << a << "->" << c <<endl;
        move(n-1,b,a,c);
    }
}
int main() {
    int n = 0;
    cout << "Input number:";
    cin >> n;
    move(n, "A" , "B", "C");
    printf("Finished");
    return 0;
}

