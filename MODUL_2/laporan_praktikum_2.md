
Template-Laprak-Strukdat.md
100%
# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Dua)</h1>

<p align="center">Akhsan Sabili - 109082500062</p>

## Dasar Teori

Pemrograman dasar dalam bahasa C++ mencakup pemahaman array, pointer, reference, fungsi, serta operasi matriks [1].

### A. Array dan Matriks <br/>

#### 1. Array adalah struktur data yang menyimpan elemen bertipe sama dalam satu variabel. Array satu dimensi digunakan untuk data linear, sedangkan array dua dimensi digunakan untuk data berbentuk tabel atau matriks. Operasi matriks seperti penjumlahan, pengurangan, dan perkalian dilakukan dengan memanfaatkan array dua dimensi [1].

### B. Pointer dan Reference <br/>

#### 1. Pointer adalah variabel yang menyimpan alamat memori dari variabel lain, sedangkan reference adalah alias dari variabel asli. Keduanya memungkinkan manipulasi langsung terhadap data sehingga lebih efisien dalam pengelolaan memori [2].

### C. Fungsi <br/>

### 2. FFungsi adalah blok kode yang dapat dipanggil berulang kali untuk menyelesaikan tugas tertentu. Dalam C++ parameter dapat dikirim dengan call by value, call by pointer, atau call by reference. Call by value hanya mengirim salinan nilai, sedangkan pointer dan reference dapat mengubah nilai asli [3].

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

### 1. (Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.)

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

![Screenshot Output Unguided 1_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_2/screenshot/ss_soal1_1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_2/screenshot/ss_soal1_2.png)

Program diatas membaca dua buah matriks berukuran tiga kali tiga kemudian melakukan tiga operasi yaitu penjumlahan pengurangan dan perkalian matriks hasil dari setiap operasi disimpan dalam matriks baru lalu ditampilkan ke layar proses penjumlahan dan pengurangan dilakukan dengan cara menambahkan atau mengurangi elemen yang posisinya sama sedangkan perkalian dilakukan dengan menjumlahkan hasil kali baris dari matriks pertama dengan kolom dari matriks kedua hasil akhirnya berupa tiga matriks yang menunjukkan hasil tambah hasil kurang dan hasil kali dari matriks yang dimasukkan

### 2. (Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.)

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

![Screenshot Output Unguided 2_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_2/screenshot/ss_soal2_1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_2/screenshot/ss_soal2_2.png)

Program diatas berfungsi untuk menukar nilai tiga variabel dengan dua cara yaitu menggunakan pointer dan menggunakan reference pada C++ pertama nilai awal x y dan z ditampilkan kemudian fungsi tukarPointer dipanggil dengan mengirim alamat variabel sehingga isi variabel benar benar berubah sesuai urutan yang ditentukan setelah itu fungsi tukarReference dipanggil dengan cara langsung bekerja pada variabel asli melalui referensi hasil akhirnya menunjukkan bahwa baik pointer maupun reference dapat digunakan untuk memodifikasi nilai variabel secara langsung tanpa membuat salinan sehingga nilai x y dan z berubah sesuai logika penukaran yang ada di dalam fungsi

### 3. (Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Kerjakan soal dengan ketentuan :)

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

![Screenshot Output Unguided 3_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_2/screenshot/sssoal3_1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_2/screenshot/ss_soal3_2.png)

Program tersebut menggunakan array berisi sepuluh angka lalu menyediakan menu untuk melakukan beberapa operasi yaitu menampilkan isi array mencari nilai maksimum mencari nilai minimum dan menghitung nilai rata rata fungsi maksimum dan minimum bekerja dengan cara membandingkan setiap elemen untuk menemukan nilai terbesar atau terkecil sedangkan fungsi ratarata menjumlahkan semua elemen lalu membaginya dengan jumlah data hasil dari setiap pilihan ditampilkan ke layar dan program akan terus berjalan sampai pengguna memilih keluar

## Kesimpulan

Praktikum ini memperkenalkan konsep dasar array, pointer, reference, fungsi, dan operasi matriks dalam C++. Array digunakan untuk menyimpan data, pointer dan reference memungkinkan manipulasi langsung, fungsi membantu modularisasi program, dan matriks digunakan untuk perhitungan matematis. Pemahaman konsep ini menjadi dasar penting untuk membangun program yang efisien dan terstruktur.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Schildt, H. (2014). C++: The Complete Reference. McGraw-Hill.