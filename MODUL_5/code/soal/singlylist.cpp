#include "singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

ElmList* alokasi(infotype x) {
    ElmList* p = new ElmList;
    if (p != nullptr) {
        p->info = x;
        p->next = nullptr;
    }
    return p;
}

void dealokasi(ElmList* p) {
    delete p;
}

void printInfo(const List &L) {
    ElmList* p = L.first;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(List &L, ElmList* p) {
    if (p != nullptr) {
        p->next = L.first;
        L.first = p;
    }
}

ElmList* findElm(const List &L, infotype x) {
    ElmList* p = L.first;
    while (p != nullptr) {
        if (p->info == x) {
            return p; 
        }
        p = p->next;
    }
    return nullptr; 
}

int totalInfo(const List &L) {
    int total = 0;
    ElmList* p = L.first;
    while (p != nullptr) {
        total += p->info;
        p = p->next;
    }
    return total;
}
