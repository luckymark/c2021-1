#ifndef P12_WAREHOUSE_LINKEDLIST_H
#define P12_WAREHOUSE_LINKEDLIST_H
#include <type_traits>
template<class type>
struct linkedlist{
    int sz;
    struct node{
        type val;
        node *nxt, *lst;
        node(const type &_val, node *_nxt, node *_lst)
        : val(_val), nxt(_nxt), lst(_lst){}
    }*head, *tail;
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
        iterator operator--(){
            mem = mem -> lst;
            return *this;
        }
        iterator operator--(int){
            iterator ret = *this;
            mem = mem -> lst;
            return ret;
        }
        bool operator!=(const iterator &b) const{
            return mem != b.mem;
        }
    };
    int size() const{
        return sz;
    }
    iterator begin() const{
        return iterator(head);
    }
    iterator end() const{
        return iterator(tail);
    }
    iterator insert(iterator it, const type &val){
        sz++;
        iterator pos = it--;
        pos.mem -> lst = new node(val, pos.mem, it.mem);
        if(it.mem) it.mem -> nxt = pos.mem -> lst;
        else head = pos.mem -> lst;
        return --pos;
    }
    iterator erase(iterator it){
        sz--;
        it.mem -> nxt -> lst = it.mem -> lst;
        iterator ret = iterator(it.mem -> nxt);
        if(it.mem -> lst) it.mem -> lst -> nxt = it.mem -> nxt;
        else head = it.mem -> nxt;
        delete it.mem;
        return ret;
    }
    void push_front(const type &val){
        insert(begin(), val);
    }
    void push_back(const type &val){
        insert(end(), val);
    }
    void pop_front(){
        erase(begin());
    }
    void pop_back(){
        erase(--end());
    }
    void clear(){
        while(head != tail) pop_front();
    }
    linkedlist(){
        sz = 0;
        head = tail = new node(type(), 0, 0);
    }
    ~linkedlist(){
        clear();
        delete head;
    }
    linkedlist<type> &operator=(const linkedlist<type> &b){
        if(this != &b){
            clear();
            for(const type &val : b)
                push_back(val);
        }
        return *this;
    }
    linkedlist(const linkedlist &b){
        sz = 0;
        head = tail = new node(type(), 0, 0);
        *this = b;
    }
};
#endif //P12_WAREHOUSE_LINKEDLIST_H
