#include "singlylist.h"

int main() {
    List L;
    ElmList *P1, *P2, *P3, *P4, *P5;

    createList(L);

    P1 = alokasi(2); insertFirst(L, P1);
    P2 = alokasi(0); insertFirst(L, P2);
    P3 = alokasi(8); insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9); insertFirst(L, P5);

    printInfo(L);

    ElmList* found = findElm(L, 8);
    if (found != nullptr) {
        cout << found->info << " ditemukan dalam list" << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    cout << "Total info dari elemen adalah " << totalInfo(L) << endl;

    return 0;
}
