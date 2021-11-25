#include <iostream>
using namespace std;
struct data {
    string name;
    int ye;
    string sex;
};
struct stake {
    stake *last;
    stake *next;
    data *info;
};

stake *create (int length);

void ouput (stake *p);

void oupu (stake *p);

int main () {
    int n;
    cin >> n;
    stake *head;
    head = create(n);
    ouput(head);
    delete (head->info);
    delete (head);
    return 0;
}

stake *create (int length) {
    stake *head1,*end;
    head1 = new(stake);
    head1->info = new(data);
    end = head1;
    for (int i = 1; i <= length; i++) {
        stake *p;
        p = new(stake);
        p->info = new(data);
        cout << "please enter your name:";
        cin >> p->info->name;
        cout << "please enter your sex :";
        cin >> p->info->sex;
        cout << "please enter your age :";
        cin >> p->info->ye;
        cout << "----------------------------------" << endl;
        end->next = p;
        p->last = end;
        end = p;
    }
    end->next = nullptr;
    head1->last = nullptr;
    return head1;
}
void ouput (stake *point) {
    stake *p;
    p = point;
    while ((p = p->next) != nullptr) {
        oupu(p);
    }
}

void oupu (stake *point) {
    stake *p;
    p = point;
    cout << "your name is:" << p->info->name << endl;
    cout << "your sex is :" << p->info->sex << endl;
    cout << "your age is :" << p->info->ye << endl;
    cout << "----------------------------------" << endl;
}