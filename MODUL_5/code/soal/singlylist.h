#ifndef singlylist_h
#define singlylist_h

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

struct List {
    ElmList* first;
};

void createList(List &L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* p);
void printInfo(const List &L);
void insertFirst(List &L, ElmList* p);
ElmList* findElm(const List &L, infotype x);
int totalInfo(const List &L);

#endif
