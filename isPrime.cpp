#include <iostream>
using namespace std;
int main() {
    bool tag=true;
    int num,test;
    cout << "Input number:" << endl;
    cin >> num;
    for(int a = 2; a < sqrt(num)+1; a++) {
        if (num % a == 0 && num!=2) {
            cout << "no";
            tag = false;
            break;
        }
    }
    if(tag == true){
        cout << "yes";
    }
    return 0;
}
