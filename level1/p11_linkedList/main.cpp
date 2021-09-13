#include <cstdio>
using namespace std;

template<class type>
struct linkedlist{
    struct node{
        type val;
        node *nxt;
        node(const type &val, node *nxt){
            this -> val = val;
            this -> nxt = nxt;
        }
    }*head;
    linkedlist(){
        head = 0;
    }
    void push_front(const type &val){
        head = new node(val, head);
    }
    struct iterator{
        node *mem;
        iterator(node *mem){
            this -> mem = mem;
        }
        type &operator*() const{
            return mem -> val;
        }
        iterator operator++(){
            mem = mem -> nxt;
            return *this;
        }
        iterator operator++(int){
            iterator ret = *this;
            mem = mem -> nxt;
            return ret;
        }
        bool operator!=(const iterator &b) const{
            return mem != b.mem;
        }
    };
    iterator begin(){
        return iterator(head);
    }
    static iterator end(){
        return iterator(0);
    }
    node *reverse(node *now, node *last){
        node *ret;
        if(now -> nxt) ret = reverse(now -> nxt, now);
        else ret = now;
        now -> nxt = last;
        return ret;
    }
    void reverse(){
        head = reverse(head, 0);
    }
    iterator find(const type &val, iterator it){
        while(it != end() && *it != val) it++;
        return it;
    }
    iterator find(const type &val){
        return find(val, begin());
    }
};

template<class type>
int find(const type &val, linkedlist<int>::iterator it, int idx = 0){
    while(it != linkedlist<type>::end() && *it != val){
        it++; idx++;
    }
    return it != linkedlist<type>::end() ? idx : -1;
}

linkedlist<int> lst;
int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

int main(){
    for(int i = sizeof(arr) / sizeof(int) - 1; ~i; i--)
        lst.push_front(arr[i]);
    for(int x : lst)
        printf("%d ", x);
    putchar('\n');
    lst.reverse();
    for(int x : lst)
        printf("%d ", x);
    putchar('\n');
    int res = find(5, lst.begin());
    printf("%d\n", res);
    if(res != -1) printf("%d\n", find(5, ++lst.find(5), res + 1));
    return 0;
}
