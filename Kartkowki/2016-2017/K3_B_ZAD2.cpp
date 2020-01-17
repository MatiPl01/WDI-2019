#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

int split(node *a, node *&b) {
    while (a != nullptr) {
        node *bTmp = b;
        node *bTmpPrev = nullptr;

        while (bTmp != nullptr) {
            if (bTmp == a) {
                int added = 0;
                while (a != nullptr) {
                    if (bTmpPrev == nullptr) {
                        bTmpPrev = new node;
                        //przypadek w ktorym modyfikujemy b to taki, gdy oba zbiory zawieraja sie w sobie
                        //wtedy b jest w calosci nowa lista, wiec musimy zmienic wskaznik poczatkowy
                        b = bTmpPrev;
                        bTmpPrev->val = a->val;
                    }
                    else {
                        bTmpPrev->next = new node;
                        bTmpPrev->next->val = a->val;
                        bTmpPrev = bTmpPrev->next;
                    }
                    a = a->next;
                    added++;
                }
                bTmpPrev->next = nullptr;
                return added;
            }
            bTmpPrev = bTmp;
            bTmp = bTmp->next;
        }
        a = a->next;
    }
    return 0;
}

void wypisz(node *list) {
    if (list == nullptr) {
        return;
    }
    cout << list->val << '(' << list << ')';
    list = list->next;
    while (list != nullptr) {
        cout << "->" << list->val << '(' << list << ')';
        list = list->next;
    }
    cout << endl;
}

int main() {
    node *a = new node;
    a->next = nullptr;
    a->val = 3;
    node *x = a;
    wypisz(a);
    wypisz(x);
    cout << split(a, x) << endl;
    wypisz(a);
    wypisz(x);
    node *b = new node;
    b->next = a;
    b->val = 2;
    node *y = b;
    wypisz(b);
    wypisz(y);
    cout << split(b, y) << endl;
    wypisz(b);
    wypisz(y);
    node *c = new node;
    c->next = b;
    c->val = 1;
    node *d = new node;
    d->next = b;
    d->val = 10;
    wypisz(c);
    wypisz(d);
    cout << split(c, d) << endl;
    wypisz(c);
    wypisz(d);

}