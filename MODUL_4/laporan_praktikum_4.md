# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">AKHSAN SABILI - 109082500062</p>

## Dasar Teori

### A. Struktur data linked list<br/>

Singly linked list adalah struktur data linear yang terdiri dari beberapa node. Setiap node menyimpan data dan pointer yang menunjuk ke node berikutnya [1].

#### 1. Pointer dan node

Node merupakan bagian dari linked list yang berisi data dan pointer next. Pointer First digunakan untuk menunjukkan node pertama dalam list.

#### 2. Operasi Linked List

Operasi dasar linked list meliputi pembuatan list, penambahan node, penampilan data, dan penghapusan node. Fungsi insertFirst() digunakan untuk menambahkan node di awal list.

### B. Manajemen memori<br/>


#### 1. Alokasi memori

 proses menyediakan ruang untuk node baru. Dalam C++, operator new digunakan untuk membuat node secara dinamis.

#### 2. Dealokasi memori

Dealokasi adalah proses membebaskan memori yang sudah tidak digunakan. Dalam C++, operator delete digunakan untuk menghapus node yang telah dialokasikan [2].

#### 3. Penelusuran node

Penelusuran node dilakukan dengan mengikuti pointer next dari node pertama hingga mencapai Nil.

## Guided

### list.h

```C++
#ifndef list_h
#define list_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};
struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string name, string nim, int umur);
void dealokasi (address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist Glist, address nodeBaru, address prev);
void insertLast(linkedlist Glist, address nodeBaru);
void delPirst(linkedlist Glist);
void dellast (linkedlist Glist);
void delAfter (linkedlist list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void delist (linkedlist Glist);

#endif
```

### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist list)
{
    if (list.first = Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList (linkedlist &list)
{
    list.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru;
    nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    delete node;
}

void insertFirst(linkedlist &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedlist &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(linkedlist &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &list)
{
    address nodeHapus;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first;
         list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong" << endl;
    }
}
void delLast(linkedlist &list)
{
    address nodeHapus, nodePrev;
    if (!isEmpty(list)==false)
    {
        nodeHapus = list.first;
        if (nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedlist &list, address nodeHapus, address nodePrev)
{
    if (isEmpty(list) == true)
    {
        cout << "list kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    } 
}
void printlist(linkedlist list)
{
    if (isEmpty(list))
    {
        cout << "list kosong" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nblist(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```

### main.cpp

```C++
#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    linkedlist list;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(list);

    nodeA = alokasi("Dhimas", "001", 20);
    nodeB = alokasi("Budi", "002", 21);
    nodeC = alokasi("Andi", "003", 22);
    nodeD = alokasi("Caca", "004", 23);
    nodeE = alokasi("Dewi", "005", 24);
}
```

Program diatas berfungsi untuk mengelola linked list, mulai dari membuat list kosong, menambahkan node di berbagai posisi, menghapus node, menampilkan isi list, menghitung jumlah elemen, hingga menghapus seluruh list. Pada fungsi main, program membuat list kosong lalu mengalokasikan beberapa node mahasiswa (Dhimas, Budi, Andi, Caca, Dewi) yang siap dimasukkan ke dalam list, sehingga program ini dapat digunakan untuk menyimpan dan memanipulasi data mahasiswa secara dinamis.

## Unguided

### 1. (Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”:)

### singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

```

### singlylist.cpp

```C++
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

```

### main.cpp

```C++

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

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_4/screenshot/ss_1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_4/screenshot/ss_2.png)

Program ini adalah singly linked list dengan tipe data integer. Struktur ElmList menyimpan nilai info dan pointer ke node berikutnya, sedangkan List menyimpan pointer ke node pertama. Fungsi createList membuat list kosong, alokasi membuat node baru, dealokasi menghapus node dari memori, insertFirst menambahkan node di awal list, dan printInfo menampilkan isi list. Pada fungsi main, program membuat list kosong lalu menambahkan beberapa node dengan nilai 2, 20, 4, 15, dan 6 ke depan list sehingga urutannya menjadi 6 15 4 20 2, kemudian mencetak isi list dan menghapus semua node agar memori tidak bocor.

## Kesimpulan

Praktikum ini memberikan pemahaman tentang penerapan singly linked list menggunakan C++. Operasi yang dilakukan meliputi pembuatan list, alokasi node, penyisipan data di awal list, penampilan data, dan dealokasi memori. Penyisipan di awal menyebabkan urutan data yang ditampilkan menjadi kebalikan dari urutan penyisipannya.

## Referensi
[1] M. A. Weiss, Data Structures and Algorithm Analysis in C++, 4th ed. Pearson, 2014.
<br> [2] P. J. Deitel and H. M. Deitel, C++ How to Program, 10th ed. Pearson, 2017.