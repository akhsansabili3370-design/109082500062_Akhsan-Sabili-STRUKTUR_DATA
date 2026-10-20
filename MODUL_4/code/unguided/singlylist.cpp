#include <iostream>
#include "Singlylist.h"

using namespace std;

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;

    P->info = x;
    P->next = Nil;

    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info;

        if (P->next != Nil) {
            cout << " ";
        }

        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
