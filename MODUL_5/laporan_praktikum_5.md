# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>

<p align="center">AKHSAN SABILI - 109082500062</p>

## Dasar Teori

Linked list atau senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas [1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Setiap node biasanya memiliki dua bagian utama yaitu data dan alamat menuju node berikutnya. Struktur data ini banyak digunakan karena lebih fleksibel dibandingkan array dalam hal penambahan dan penghapusan elemen [2].

### A. Konsep linked list<br/>

#### 1. Komponen

Komponen utama linked list terdiri dari node yang berisi data dan pointer ke node berikutnya. Selain itu terdapat pointer khusus yang menunjuk ke node pertama yang disebut head atau first [2].

#### 2. Jenis linked list

Linked list terbagi menjadi beberapa jenis yaitu singly linked list, doubly linked list, dan circular linked list. Singly linked list hanya memiliki pointer ke node berikutnya, sedangkan doubly linked list memiliki pointer ke node sebelumnya dan berikutnya, dan circular linked list membentuk lingkaran dengan node terakhir menunjuk kembali ke node pertama [3].

### B. Operasi linked list<br/>

#### 1. Pembuatan list

Operasi ini dilakukan dengan menginisialisasi pointer first menjadi null sehingga terbentuk list kosong yang siap digunakan [1].

#### 2. Penyisipan node

Node baru dapat disisipkan di awal list, di akhir list, atau setelah node tertentu. Proses ini dilakukan dengan mengatur pointer next dari node baru agar menunjuk ke node yang sesuai [2].

#### 3. Penghapusan dan pencarian

Node dapat dihapus dari awal, akhir, atau setelah node tertentu dengan cara mengubah pointer next dari node sebelumnya. Selain itu, pencarian elemen dilakukan dengan menelusuri list dari node pertama hingga node terakhir untuk menemukan data yang sesuai [3].

## Guided

### 1. list.h

```C++
#ifndef List_h
#define List_h
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

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list, address &prev);
void updateByNim(linkedlist &list, string nim);

void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir);
address findNodeByData(linkedlist List, string data);
#endif
```

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
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
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
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

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list))
    {
        cout << "List kosong" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
           nodeBantu = nodeBantu->next;
        }

    nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist list, address &prev)
{
    if (isEmpty(list))
    {
        cout << "list kosong "<< endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        prev->next->isidata = newData;
    }
}

void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = findNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

address findNodeByData(linkedlist List, string data)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
       posisi++;
        if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
        {
            found = true;
            return nodeBantu;
        }
            nodeBantu = nodeBantu->next;
        }
        if ( found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;

}

void FindNodeByAddress(linkedlist List, address node)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
       address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if ( umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " <<  nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
	linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    updateFirst(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    printList(List);
    
    updateLast(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    printList(List);

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER NODE C---" << endl;
    printList(List);

    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM---" << endl;
    printList(List);
    return 0;
}
```

program diatas dirancang untuk mengelola data mahasiswa mencakup nama, nomor induk mahasiswa, dan umur. Pada code tersebut header berfungsi mendefinisikan struktur data dan daftar fungsi yang tersedia, sedangkan implementasi berisi penjabaran fungsi secara rinci seperti manajemen memori alokasi dan dealokasi, operasi penyisipan dan penghapusan elemen di berbagai posisi, pencarian node, serta prosedur pembaruan data. Lalu main berperan sebagai program utama yang mendemonstrasikan penggunaan seluruh fungsi tersebut dengan membuat list kosong, memasukkan beberapa data mahasiswa, mencetak isinya, serta menguji berbagai fitur pembaruan data mahasiswa secara langsung.

## Unguided

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”:

#### singlylist.h

```C++
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

```

#### singlylist.cpp

```C++
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

```

#### main.cpp

```C++
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

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_5/screenshot/ss_1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_5/screenshot/ss_2.png)

Program diatas berfungsi untuk membuat list menggunakan konsep singly linked list di mana setiap elemen dialokasikan dengan fungsi alokasi lalu dimasukkan ke depan list menggunakan insertFirst sehingga urutan akhirnya menjadi 9 12 8 0 2 kemudian isi list ditampilkan dengan printInfo setelah itu dilakukan pencarian elemen bernilai 8 dengan findElm yang akan mengembalikan alamat node jika ditemukan dan menampilkan pesan bahwa nilai tersebut ada dalam list serta dilakukan perhitungan jumlah seluruh nilai elemen dengan totalInfo yang menjumlahkan isi node satu per satu sehingga hasil akhirnya adalah 31.

## Kesimpulan

Dari praktikum ini dapat disimpulkan bahwa singly linked list merupakan struktur data yang efektif untuk menyimpan dan mengelola data secara dinamis. Dengan menggunakan pointer, setiap node dapat dihubungkan sehingga memungkinkan operasi penambahan, penghapusan, pencarian, dan perhitungan data dilakukan dengan lebih fleksibel dibandingkan array. Implementasi dalam C++ menunjukkan bagaimana konsep linked list dapat diwujudkan melalui ADT.

## Referensi

[1] Horowitz, E., & Sahni, S. (1983). Fundamentals of Data Structures in C. Computer Science Press.
<br> [2] Weiss, M. A. (1997). Data Structures and Algorithm Analysis in C++. Addison-Wesley.
<br> [3] Wirth, N. (1986). Algorithms and Data Structures. Prentice Hall.