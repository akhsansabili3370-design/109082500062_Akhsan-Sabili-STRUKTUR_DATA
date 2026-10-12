# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">AKHSAN SABILI - 109082500062</p>

## Dasar Teori

Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematika untuk tipe data yang didefinisikan oleh perilaku dari sudut pandang pengguna, terlepas dari bagaimana data tersebut diimplementasikan secara internal [1]. Dalam bahasa pemrograman C++, ADT umumnya diimplementasikan menggunakan struktur (struct) yang membungkus berbagai variabel ke dalam satu kesatuan logis [2]. Pemecahan program menjadi file header (.h) dan file implementasi (.cpp) merupakan bagian dari modularisasi untuk memisahkan antarmuka dan logika kode [3]. Selain itu, pemanfaatan pointer [4], array dua dimensi [2], serta mekanisme pass by reference [5] sangat esensial dalam manipulasi memori dan pengelolaan struktur data yang kompleks.

### A. ADT dan modularisasi program<br/>

#### 1. Konsep dan Karakteristik ADT
        Abstract Data Type (ADT) merupakan model matematika yang memisahkan definisi dan perilaku data dari detail implementasi internalnya [1].

#### 2. Penggunaan struct pada C++
        Struct digunakan dalam C++ untuk mengelompokkan berbagai variabel bertipe data berbeda menjadi satu kesatuan objek [2].

#### 3. Pemisah Header dan Implementasi
        Pemisahan file header (.h) dan file implementasi (.cpp) bertujuan untuk memisahkan deklarasi antarmuka dari logika kode program [3].

### B. Pointer, Array, dan mekanisme Pass by Reference<br/>

#### 1. Konsep Dasar Pointer
        Pointer adalah variabel khusus yang menyimpan alamat memori dari suatu variabel lain [4].

#### 2. Array Dua Dimensi dan Akses Elemen
        Array dua dimensi merupakan struktur data homogen berbentuk baris dan kolom yang diakses menggunakan dua indeks [baris][kolom] [2].

#### 3. Mekanisme Pass by Reference dan Penukaran Nilai
        Mekanisme pass by reference memungkinkan fungsi mengubah langsung nilai variabel asli di alamat memorinya tanpa perlu menduplikasi data [5].


## Guided

### 1. DATA MAHASISWA DENGAN ADT

### mahasiswa.h
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif 
```

### mahasiswa.cpp

```C++
#include"mahasiswa.h"
void inputMhs(mahasiswa &m){
    cout <<"input nama =";
    cin >> (m).nim;
    cout <<"input nilai =";
    cin >> (m).nilai1;
    cout <<"input nilai2 =";
    cin >> (m).nilai2;
}
float rata2(mahasiswa m){
    return float(m.nilai1+m.nilai2)/2;
}
```

### main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;
int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
Program ini terdiri dari header, implementasi, dan code utama. Pada header dibuat struktur data mahasiswa yang menyimpan nim serta dua nilai ujian, lalu dideklarasikan fungsi untuk input dan menghitung rata-rata. Berikutnya ada implementasi yang berisi fungsi inputMhs yang meminta pengguna memasukkan nim, nilai pertama, dan nilai kedua, kemudian menyimpannya ke dalam variabel mahasiswa. Fungsi rata2 digunakan untuk menghitung rata-rata dari dua nilai tersebut. Program utama berfungsi menjalankan program, membuat variabel mahasiswa, memanggil fungsi inputMhs untuk mengisi data, lalu menampilkan hasil rata-rata dengan memanggil fungsi rata2.

## Unguided

### 1. (Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 uts+0.4 uas+0.3 tugas.)

### mahasigma.h
```C++
#ifndef MAHASIGMA_H_INCLUDED
#define MAHASIGMA_H_INCLUDED

struct mahasigma {
    char nama[50];
    char nim[15];
    float uts, uas, tugas;
    float nilaiAkhir;
};

void inputMhs(mahasigma &m);
float hitungNilaiAkhir(mahasigma m);
void tampilMhs(mahasigma m);

#endif

```

### mahasigma.cpp
```C++
#include <iostream>
#include "mahasigma.h"
using namespace std;

void inputMhs(mahasigma &m){
    cout << "Nama   : ";
    cin >> m.nama;
    cout << "NIM    : ";
    cin >> m.nim;
    cout << "UTS    : ";
    cin >> m.uts;
    cout << "UAS    : ";
    cin >> m.uas;
    cout << "Tugas  : ";
    cin >> m.tugas;

    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasigma m) {
    return (0.3 * m.uts) + (0.4 * m.uas) + (0.3 * m.tugas);
}

void tampilMhs(mahasigma m) {
    cout << "\nData mahasigma\n";
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}

```

### main.cpp
```C++
#include <iostream>
#include "mahasigma.h"
using namespace std;

int main() {
    mahasigma daftar[10];
    int n;

    cout << "Masukkan jumlah mahasigma : ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah melebihi batas maksimal!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nInput data mahasigma ke-" << i+1 << endl;
        inputMhs(daftar[i]);
    }

    cout << "\n=== Daftar mahasigma ===\n";
    for (int i = 0; i < n; i++) {
        tampilMhs(daftar[i]);
    }

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_3/screenshot/ss-soal1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_3/screenshot/ss-saol1-2.png)

Program ini dibuat dengan tiga bagian utama yaitu header, implementasi, dan main. Pada header menjelaskan struktur mahasiswa yang menyimpan nim dan dua nilai ujian serta deklarasi fungsi input dan rata rata. LAlu implementasi berisi fungsi inputMhs yang meminta pengguna memasukkan nim, nilai pertama, dan nilai kedua lalu menyimpannya ke dalam variabel mahasigma. Fungsi rata2 digunakan untuk menghitung rata rata dari dua nilai tersebut. File utama berfungsi menjalankan program dengan membuat variabel mahasigma, memanggil fungsi input untuk mengisi data, lalu menampilkan hasil rata rata menggunakan fungsi rata2. 

### 2. (Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:)

### pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(Pelajaran pel);

#endif

```

### pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}

```

### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_3/screenshot/ss-soal2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_3/screenshot/ss-soal2-2.png)

Pada progam diatas file header didefinisikan struktur pelajaran dengan dua variabel yaitu nama mata pelajaran dan kode mata pelajaran serta fungsi untuk menampilkan data. Lalu implementasi berisi fungsi create_pelajaran yang menerima input nama dan kode lalu mengembalikan pelajaran, serta prosedur tampil_pelajaran yang menampilkan output. File utama menjalankan program dengan membuat variabel string untuk nama dan kode, kemudian memanggil fungsi create_pelajaran untuk menghasilkan objek pelajaran dan menampilkan hasilnya menggunakan prosedur tampil_pelajaran.

### 3. (isi dengan soal unguided 3)

### array.h
```C++

#ifndef ARRAY_H
#define ARRAY_H

void tampilArray(int arr[3][3]);

void tukarArray(int arrA[3][3], int arrB[3][3],
                int baris, int kolom);

void tukarPointer(int *a, int *b);

#endif

```

### array.cpp
```C++

#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arrA[3][3], int arrB[3][3],
                int baris, int kolom) {
    int temp = arrA[baris][kolom];

    arrA[baris][kolom] = arrB[baris][kolom];
    arrB[baris][kolom] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

```

### main.cpp
```C++

#include <iostream>
#include "array.h"
using namespace std;

int main() {
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arrB[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int x = 20;
    int y = 30;

    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum ditukar:" << endl;
    tampilArray(arrA);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampilArray(arrB);

    tukarArray(arrA, arrB, 1, 1);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(arrA);

    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(arrB);

    cout << "\nNilai sebelum tukar pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "\nNilai setelah tukar pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}

```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_3/screenshot/ss-soal3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_3/screenshot/ss-soal3-2.png)

Pada program diatas terdapat header yang berisi deklarasi fungsi dan prosedur, implementasi yang berisi kode untuk menampilkan isi array 2D dan menukarkan nilai array serta pointer, dan main yang berisi deklarasi dua array integer berukuran 3×3 serta dua variabel integer yang diakses menggunakan pointer. Fungsi tampilArray digunakan untuk menampilkan seluruh elemen array dengan perulangan, sedangkan prosedur tukarArray digunakan untuk menukarkan elemen dari kedua array pada posisi yang telah ditentukan, yaitu indeks [1][1], yang menunjukkan baris kedua dan kolom kedua. Selanjutnya, prosedur tukarPointer digunakan untuk menukarkan nilai variabel x dan y melalui pointer dengan bantuan variabel sementara bernama temp. 

## Kesimpulan

Kesimpulan dari praktikum Modul 3 mengenai ADT adalah bahwa penggunaan struct yang dikombinasikan dengan modularisasi program dengan pemisahan file header dan implementasi sangat efektif untuk merancang kode yang terstruktur, bersih, dan mudah dipelihara. Selain itu, pengolahan data kolektif menggunakan array of struct pada pengelolaan data mahasiswa serta pemanfaatan array dua dimensi, pointer, dan mekanisme pass by reference terbukti dalam melakukan manipulasi elemen data maupun pengelolaan memori secara efisien tanpa menduplikasi data asli.

## Referensi
[1] B. Stroustrup, The C++ Programming Language, 4th ed. Addison-Wesley, 2013.

<br>[2] A. M. Tenenbaum, Y. Langsam, and M. J. Augenstein, Data Structures Using C and C++, Prentice Hall, 2019.

<br>[3] R. Lafore, Object-Oriented Programming in C++, 4th ed. Sams Publishing, 2022.

<br>[4] E. Horowitz, S. Sahni, and D. Mehta, Fundamentals of Data Structures in C++, Silicon Press, 2017.

<br>[5] D. S. Malik, C++ Programming: From Problem Analysis to Program Design, 8th ed. Cengage Learning, 2018.
