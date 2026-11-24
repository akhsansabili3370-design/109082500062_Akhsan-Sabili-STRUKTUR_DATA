# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Akhsan Sabili - 109082500062</p>

## Dasar Teori

isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

### B. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

## Guided 1

### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;
struct Node
{
    string nama;
    Node* next;
};

struct queue
{
    Node* head, *tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue& Q, const string &nama);
void deQueue(queue& Q);
void viewQueue(queue Q);
void clearQueue(queue& Q);
#endif
```

### queue.cpp

```C++
#include "queue.h"

void CreateQueue(queue &Q)
{
    Q.head = Q.tail = nullptr;
}
bool isEmpty(queue Q)
{
    return Q.head == nullptr && Q.tail == nullptr;
}

bool isfull(queue Q)
{
    int counter = 0;
    int maxQueue = 20;
    Node* nodeBantu = Q.head;
    
    while (nodeBantu != Q.tail)
    {
        counter++;
        nodeBantu->next;
    }
    return counter >= maxQueue;
}

void enQueue(queue& Q, const string &nama)
{
    if (isEmpty(Q))
    {
        Node* nodeBaru = new Node(nama, nullptr);
        Q.head = Q.tail = nodeBaru;
    }
    else
    {
        Node* nodeBaru = new Node(nama, nullptr);
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
}

void deQueue(queue& Q)
{
    if (isEmpty(Q)){
        cout << "Queue kosong!" << endl;
        return;
    }else{
        Node* nodeHapus = Q.head;
        Q.head = Q.head->next;
        delete nodeHapus;
    }
}
void viewQueue(queue Q)
{
    if (isEmpty(Q)){
        cout << "Queue kosong!" << endl;
        return;
    }else{
        Node* nodeBantu = Q.head;

        while (nodeBantu != nullptr)
        {
            cout << "Nama :"<< nodeBantu->nama;
            nodeBantu = nodeBantu->next;
        }
    }
}
void clearQueue(queue& Q)
{
    if (isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    }
    else{
        Node* nodeHapus = Q.head;

        while (nodeHapus != nullptr)
        {
            nodeHapus = nodeHapus->next;
            deQueue(Q);
        }
    }
}
```

### main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "Gilar");
    enQueue(Q, "Aflah");
    enQueue(Q, "Aedil");
    enQueue(Q, "Fathir");
    enQueue(Q, "Kevin");
    enQueue(Q, "Zulfa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

Program diatas merupakan queue menggunakan linked list. File header mendefinisikan struktur Node untuk menyimpan nama dan pointer ke node berikutnya serta struktur queue yang memiliki head dan tail. Pada program utama dibuat sebuah queue, lalu beberapa nama dimasukkan menggunakan fungsi enQueue(), kemudian isi antrian ditampilkan dengan viewQueue(), dan akhirnya seluruh data dihapus menggunakan clearQueue(). Selain itu tersedia fungsi isEmpty() untuk mengecek apakah antrian kosong dan deQueue() untuk menghapus elemen yang berada di depan antrian sesuai prinsip FIFO.

## Guided 2

### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikeluarin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

//dequeue implementasi 2
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        Q.head++;
        if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }
    }
    cout << endl;
}
```

### main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

Program diatas merupakan queue menggunakan array dengan kapasitas maksimal 5 elemen. Struktur queue menyimpan data nama dalam array serta indeks head dan tail untuk menandai posisi depan dan belakang antrian. Pada fungsi utama dibuat sebuah queue, kemudian beberapa nama dimasukkan menggunakan enQueue(), ditampilkan dengan viewQueue(), lalu dilakukan deQueue() berkali-kali untuk menghapus data dari depan antrian sesuai prinsip FIFO. Jika seluruh data sudah terhapus, program akan menampilkan bahwa queue kosong ketika dilakukan penghapusan atau penampilan data lagi.

## Unguided

### 1. (Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:)

#### queue.h

```C++

#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
    int jumlah;
    int alternatif;
};

void createQueue(Queue &Q, int mode);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype input);
void dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

#### queue.cpp

```C++

#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q, int mode) {
    Q.head = -1;
    Q.tail = -1;
    Q.jumlah = 0;
    Q.alternatif = mode;
}

bool isEmptyQueue(Queue Q) {
    return Q.jumlah == 0;
}

bool isFullQueue(Queue Q) {
    if (Q.alternatif == 3) {
        return Q.jumlah == 5;
    }

    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype input) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (Q.alternatif == 1) {
            if (isEmptyQueue(Q)) {
                Q.head = 0;
            }
            Q.tail++;
        }
        else if (Q.alternatif == 2) {
            if (isEmptyQueue(Q)) {
                Q.head = 0;
                Q.tail = 0;
            } else {
                Q.tail++;
            }
        }
        else if (Q.alternatif == 3) {
            if (isEmptyQueue(Q)) {
                Q.head = 0;
                Q.tail = 0;
            } else {
                Q.tail = (Q.tail + 1) % 5;
            }
        }

        Q.info[Q.tail] = input;
        Q.jumlah++;
    }
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        if (Q.alternatif == 1) {
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }

            Q.tail--;
        }
        else if (Q.alternatif == 2) {
            if (Q.head == Q.tail) {
                Q.head = -1;
                Q.tail = -1;
            } else {
                Q.head++;
            }
        }
        else if (Q.alternatif == 3) {
            if (Q.head == Q.tail) {
                Q.head = -1;
                Q.tail = -1;
            } else {
                Q.head = (Q.head + 1) % 5;
            }
        }

        Q.jumlah--;

        if (Q.jumlah == 0) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
}


void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    }
    else {
        if (Q.alternatif == 1) {
            for (int i = 0; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
        else if (Q.alternatif == 2) {
            for (int i = Q.head; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
        else if (Q.alternatif == 3) {
            int i = Q.head;

            for (int j = 0; j < Q.jumlah; j++) {
                cout << Q.info[i] << " ";
                i = (i + 1) % 5;
            }
        }
    }

    cout << endl;
}


```

#### main.cpp

```C++

#include <iostream>
#include "queue.h"
using namespace std;

void jalankanQueue(int mode) {
    Queue Q;
    createQueue(Q, mode);

    cout << "\nSOAL " << mode << endl;

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);
}

int main() {
    jalankanQueue(1);
    jalankanQueue(2);
    jalankanQueue(3);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 3

![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 

## Kesimpulan

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...