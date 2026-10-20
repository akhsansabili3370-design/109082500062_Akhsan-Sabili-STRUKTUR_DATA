
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(20);
    insertFirst(L, P2);

    P3 = alokasi(4);
    insertFirst(L, P3);

    P4 = alokasi(15);
    insertFirst(L, P4);

    P5 = alokasi(6);
    insertFirst(L, P5);

    printInfo(L);

    while (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }

    return 0;
}
