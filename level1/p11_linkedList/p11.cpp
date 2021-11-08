#include <iostream>
#include <cstdio>
#include <malloc.h>

using namespace std;


int n;
struct node{
    int val, num;
    node* nxt;
    node(){val = 0, nxt = nullptr;}
    node(int val, int num, node* nxt): val(val),num(num),nxt(nxt){};
};

void reverse(node* x, node* las){
    node *t = x->nxt;
    x->nxt = las;
    if (t)
        reverse(t, x);
    else return ;
}

node* find_5(node *x){
    if (!x || x->val == 5)
        return x;
    return find_5(x->nxt);
}
int main() {
    scanf ("%d", &n);

    node *fst = (node *)malloc(sizeof(node) * (n + 1));
    node *top = fst;


    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d",&x);
        *top = node(x, i, top + 1);
        top++;
    }

    top--;
    top->nxt = nullptr;

    reverse(fst, nullptr);

    node *ans = find_5(top);
    while (ans){
        printf("%d\n", ans->num);
        ans = find_5(ans->nxt);
    }

    printf("-1\n");

    free(fst);
    return 0;
}