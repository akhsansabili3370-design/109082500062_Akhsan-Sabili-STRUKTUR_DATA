
Template-Laprak-Strukdat.md
100%
# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Dua)</h1>

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

## Guided

### 1. ...

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX]=
    { {0,2,2,0,0},
    {0,1,1,1,0},
    {0,3,3,3,0},
    {4,4,0,0,4},
    {5,0,0,0,5}
    };

    for (i=0; i<MAX; i++){
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";

    for (i=0; i<MAX; i++)
        cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
    cout<<"\n nilai tahunan : \n";

    for(i=0; i<MAX; i++){
         for(j=0; j<MAX; j++)
            cout<<nilai_tahun[i][j];
        cout<<"\n";
        }
    return 0;
}
```

Program diatas meminta inputan 5 nilai ke dalam array, lalu menampilkan kembali nilai yang dimasukkan. Selain itu, program juga memiliki array dua dimensi berisi data nilai tahunan yang sudah ditentukan sebelumnya, dan ditampilkan dalam bentuk tabel. Array dua dimensi juga untuk menyimpan serta menampilkan data yang sudah ada.

### 2. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x = "<< &x << endl;
    cout << "Isi px = "<< px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;
    return 0;
}
```

Program diatas adalah program dengan pointer. Pertama variabel x dikasih nilai 87, lalu pointer px diisi dengan alamat dari x. Karena px menunjuk ke x, kalau kita ambil nilai dengan *px hasilnya sama dengan isi x. Nilai itu kemudian disalin ke variabel y. Di bagian output, program akan nmenampilkan alamat memori x, isi pointer px (alamat x), nilai x langsung, nilai yang ditunjuk px, dan nilai y. 

### 3. ...

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main(){
    int x,y,z;
    cout<<"masukkan nilai bilangan ke-1 = ";
    cin>>x;
    cout<<"masukkan nilai bilangan ke-2 = ";
    cin>>y;
    cout<<"masukkan nilai bilangan ke-3 = ";
    cin>>z;
    cout<<"nilai maksimumnya adalah = "<<maks3(x,y,z);
    return 0;
}

int maks3(int a, int b, int c){
    int temp_max =a;
    if(b>temp_max)
        temp_max=b;
    if(c>temp_max)
        temp_max=c;
return (temp_max);
}
```

Program datas berfungsi mencari nilai terbesar dari tiga bilangan. Di bagian main, program meminta inputan tiga angka, lalu program memanggil fungsi maks3 untuk menentukan mana yang paling besar. Di dalam fungsi maks3, nilai awal dianggap sama dengan a, kemudian dibandingkan dengan b dan c. Kalau b lebih besar dari nilai sementara, maka diganti dengan b, begitu juga dengan c. Lalu program akan menampilkan angka terbesar dari ketiga bilangan

### 4. ...

```C++
#include <iostream>
using namespace std;

void tulis(int x);

int main(){
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}
void tulis(int x){
    for (int i=0;i<x;i++)
    cout<<"baris ke-" <<i+1<<endl;
}
```

Program diatas berfungsi untuk menampilkan baris tulisan sesuai jumlah yang dimasukkan pengguna. Di bagian main, pengguna diminta memasukkan angka berapa banyak baris yang mau ditulis. Lalu angka akan dikirim ke fungsi tulis. Di dalam fungsi tulis ada perulangan for yang berjalan dari nol sampai kurang dari jumlah baris, lalu setiap kali perulangan akan mencetak teks baris ke- dengan nomor urutnya.

### 5. ...

```C++
#include <iostream>
using namespace std;

void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer( int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 4, b = 6;

    tukarValue(a, b);
    cout << "Setelah Call by Value  -> a = " << a << ", b = "<< b << " (Tetap)" << endl;

    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer    -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    tukarReference(a, b);
    cout << "Setelah Call by Reference  -> a = " << a <<", b = " << b << "(Berubah lagi!)" << endl;
return 0;
}
```

Program diatas menjelaskan tiga cara pertukaran nilai. Pada call by value, fungsi tukarValue hanya menerima salinan nilai dari a dan b sehingga perubahan yang dilakukan di dalam fungsi tidak memengaruhi nilai asli dan hasilnya tetap a = 4 dan b = 6. Pada call by pointer, fungsi tukarPointer menerima alamat dari a dan b sehingga nilai asli dapat ditukar dan hasilnya menjadi a = 6 dan b = 4. Kemudian pada call by reference, fungsi tukarReference menggunakan referensi yang langsung mengacu pada variabel asli sehingga nilai a dan b kembali ditukar menjadi a = 4 dan b = 6. 

## Unguided

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];
    int tambah[3][3], kurang[3][3], kali[3][3];

    cout << "matrix 1:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "matrix 2:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tambah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];

            kali[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                kali[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nHasil Tambah:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tambah[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Kurang:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << kurang[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Kali:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << kali[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *z;
    *z = *y;
    *y = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = z;
    z = y;
    y = temp;
}

int main() {
    int x = 20, y = 15, z = 5;

    cout << "Nilai awal:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    tukarPointer(&x, &y, &z);

    cout << "\nSetelah menggunakan Pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    tukarReference(x, y, z);

    cout << "\nSetelah menggunakan Reference:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int maksimum(int arr[], int n) {
    int maks = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }

    return maks;
}

int minimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void ratarata(int arr[], int n, float &rataRata) {
    int jumlah = 0;

    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }

    rataRata = (float) jumlah / n;
}

int main() {
    int arrA[] = {56, 13, 20, 6, 9, 28, 39, 51, 1, 8};
    int n = 10;
    int pilihan;
    float rataRata;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nIsi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "\nNilai maksimum = "
                     << maksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "\nNilai minimum = "
                     << minimum(arrA, n) << endl;
                break;

            case 4:
                ratarata(arrA, n, rataRata);
                cout << "\nNilai rata-rata = " << rataRata << endl;
                break;

            case 5:
                cout << "\nProgram selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak tersedia." << endl;
        }

    } while (pilihan != 5);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
Menampilkan Template-Laprak-Strukdat.md.