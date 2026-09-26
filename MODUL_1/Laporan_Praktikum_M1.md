# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Akhsan Sabili - 109082500062</p>

## Dasar Teori

Pemrograman dasar dalam bahasa C++ melibatkan pemahaman mendalam mengenai tipe data, operasi input/output, struktur kontrol keputusan, array, serta perulangan bersarang (nested loop) [1].

### A. Tipe Data, Operasi Input/Output<br/>

#### 1. Bahasa C++ menggunakan pustaka untuk menangani alur data standar. Stream cin berfungsi mengambil masukan dari pengguna melalui keyboard, sedangkan cout berfungsi menampilkan keluaran ke layar konsol [1].

#### 2. Tipe data adalah pengklasifikasian nilai yang menentukan batasan memori yang dialokasikan serta jenis operasi aritmatika maupun logika yang dapat diterapkan pada data tersebut di dalam program [2].

#### 3. Perulangan adalah teknik pemrograman yang mengeksekusi sebuah blok instruksi secara terus-menerus selama kondisi batas yang dievaluasi masih terpenuhi, sehingga penulisan algoritma menjadi lebih efisien [3].

### B. Struktur kontrol dan Array<br/>

#### 1. Percabangan (if-else if): Struktur kontrol keputusan memfasilitasi jalurnya eksekusi program berdasarkan kondisi rasional tertentu. Sintaks if dan else if mengevaluasi ekspresi boolean secara berurutan hingga ditemukan kondisi yang bernilai benar (true) [4].

#### 2. Array adalah struktur data statis yang menyimpan sekumpulan elemen dengan tipe data sejenis pada lokasi memori yang berdekatan, di mana setiap nilainya dapat diakses secara langsung menggunakan nomor indeks [5].

## Guided

### 1. ...

```C++
#include<iostream>
using namespace std;
int main(){
    int w, x, y; float z;
    x = 7; y = 3; w = 1;
    z = (x + y)/(y + w);
    cout << "nilai z = "<< z << endl;
    return 0;
}
```

Kode tersebut mendeklarasikan tiga variabel bertipe int (w, x, y) dan satu variabel bertipe float (z). Nilai awalnya adalah x = 7, y = 3, dan w = 1. Lalu dilakukan perhitungan z = (x + y)/(y + w), yaitu (7 + 3)/(3 + 1) = 10/4. Karena pembagian dilakukan dengan tipe int, hasilnya adalah 2 bukan 2.5, kemudian dikonversi ke float sehingga z = 2.0. Program akhirnya menampilkan output nilai z = 2. Jika ingin hasil pecahan yang benar, salah satu operand harus diubah ke float.


### 2. ...

```C++
#include <iostream>
using namespace std;
int main(){
    int r = 10;
    int s;
    s=10 + ++r;
    cout<< "Nilai r= "<<r<<endl;
    cout<< "Nilai s= "<<s<<endl;
    return 0;
}
```

Program tersebut mendeklarasikan variabel r dengan nilai awal 10 dan variabel s. Pada baris s = 10 + ++r;, operator ++r adalah pre-increment, artinya nilai r akan ditambah 1 terlebih dahulu sebelum digunakan dalam operasi. Jadi r berubah dari 10 menjadi 11, lalu dihitung s = 10 + 11 = 21. Setelah itu program mencetak nilai r = 11 dan s = 21.  


### 3. ...

```C++
#include <iostream>
using namespace std;
int main(){
    double tot_pembelian, diskon;
    cout << " total pembelian : Rp";
    cin >> tot_pembelian;
    diskon = 0;
    if (tot_pembelian >= 100000)
        diskon = 0.05 * tot_pembelian;
    else
        diskon = 0;
    cout << "besar diskon = Rp"<<diskon;
}
```

Program tersebut meminta input berupa total pembelian dari pengguna, lalu menghitung diskon berdasarkan nilai tersebut. Variabel tot_pembelian bertipe double digunakan untuk menampung jumlah pembelian, sedangkan diskon untuk menampung hasil perhitungan diskon. Jika total pembelian lebih besar atau sama dengan Rp100.000, maka diskon dihitung sebesar 5% dari total pembelian. Jika kurang dari Rp100.000, diskon bernilai nol. Setelah itu, program menampilkan hasil diskon yang diperoleh. Jadi, logika utamanya adalah memberikan potongan harga 5% hanya untuk pembelian minimal Rp100.000.

### 4. ...

```C++
#include <iostream>
using namespace std;
int main(){
    int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=senin 3=rabu 5=jumat 7=minggu ");
    puts("2=selasa 4=kamis 6=sabtu ");
    cin >> kode_hari;
    switch (kode_hari){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << ("Hari kerja");
            break;
        case 6:
        case 7:
            cout << ("Hari libur");
            break;
        default :
            cout << ("code masukan salah") << endl;
    }
    return 0;
}
```

Program tersebut berfungsi untuk menentukan apakah sebuah kode hari termasuk hari kerja atau hari libur. Pertama, pengguna diminta memasukkan angka 1–7 yang mewakili hari Senin sampai Minggu. Kemudian, melalui struktur switch-case, program mengelompokkan kode 1–5 sebagai hari kerja (Senin–Jumat) dan kode 6–7 sebagai hari libur (Sabtu–Minggu). Jika input tidak sesuai dengan rentang tersebut, program akan menampilkan pesan “code masukan salah”. Dengan cara ini, program secara sederhana mengklasifikasikan hari berdasarkan kode angka yang dimasukkan.

### 5. ...

```C++
#include <iostream>
using namespace std;
int main(){
    int i = 1;
    int jum;
    cout<<"masukan banyak baris: ";
    cin>>jum;
    do{
        cout << "baris ke-"<< (i+1)<<endl;
        i++;
    } while (i < jum);
    return 0;
}
```

Program tersebut meminta pengguna memasukkan jumlah baris, lalu menggunakan perulangan do  while untuk mencetak teks “baris ke-...” sesuai nilai yang dimasukkan. Perulangan ini selalu dijalankan minimal sekali karena pengecekan kondisi dilakukan di akhir, sehingga meskipun syarat tidak terpenuhi, blok do tetap dieksekusi sekali sebelum berhenti. Dengan demikian, do...while cocok digunakan ketika kita ingin memastikan sebuah proses dijalankan setidaknya satu kali terlebih dahulu, baru kemudian dikontrol oleh kondisi.

### 6. ...

```C++
#include <iostream>
using namespace std;
int main(){
    int i = 1;
    int jum;
    cout<<"masukan banyak baris: ";
    cin>>jum;
    while(i <= jum){
        cout << "baris ke-"<< i << endl;
        i++;
    }
    return 0;
}
```

Program tersebut meminta pengguna memasukkan jumlah baris, lalu menggunakan perulangan while untuk mencetak teks “baris ke-...” dari 1 hingga jumlah yang dimasukkan. Variabel i dimulai dari 1, kemudian selama kondisi i <= jum bernilai benar, program akan menampilkan baris ke-i dan menaikkan nilai i dengan i++. Perulangan berhenti ketika i lebih besar dari jum. Berbeda dengan do...while yang selalu dijalankan minimal sekali, perulangan while ini hanya berjalan jika syarat awal sudah terpenuhi.


### 7. ...

```C++
#include <iostream>
using namespace std;
int main(){
    int jum;
    cout << "jumlah perulangan: ";
    cin >> jum;
    for(int i = 0; i < jum; i++){
        cout << "saya pintar\n";
    }
    return 0;
}
```

Kode ini menggunakan perulangan for untuk mencetak teks saya pintar secara berulang sesuai dengan angka yang dimasukkan oleh pengguna. Program awalnya meminta input angka dari pengguna untuk disimpan ke dalam variabel jum. Setelah itu, instruksi for akan mengeksekusi perintah pencetakan teks tersebut secara terus-menerus hingga jumlah perulangannya persis mencapai batas nilai jum yang telah ditentukan.

### 8. ...

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
    int i;
    struct data{
        char nama[40];
        int nilai;
    };
    data siswa[MAX];
    for (i = 0; i < MAX; i++){
        cout << "masukkan data ke-"<<i+1<<endl;
        cout << "nama = ";
        cin >> siswa[i].nama;
        cout << "nilai = ";
        cin >> siswa[i].nilai;
    }
    cout << "\ndata siswa\n";
    cout << "=======";
    for (i = 0; i < MAX; i++){
        cout << "\n \ndata ke-"<<i+1;
        cout << "\n \nnama = "<<siswa[i].nama;
        cout << "\n \nnilai = "<<siswa[i].nilai;
    }
    return 0;
}
```

Program tersebut mendefinisikan sebuah struct data  yang berisi dua atribut, yaitu nama (string karakter dengan panjang maksimal 40) dan nilai int. Lalu dibuat array siswa dengan ukuran tetap MAX = 5, sehingga dapat menampung data lima siswa. Dalam perulangan for, program meminta pengguna memasukkan nama dan nilai untuk setiap siswa, kemudian menyimpannya ke dalam array. Setelah semua data dimasukkan, program mencetak kembali daftar siswa dengan menampilkan nama dan nilai masing-masing. Intinya, program ini adalah contoh sederhana penggunaan struct dan array untuk menyimpan serta menampilkan data beberapa siswa secara terstruktur.

### 9. ...

```C++
#include <iostream>
using namespace std;

float ctof(float celcius);
int main() {
    float celcius, fahrenheit;
    cout <<"nilai Celcius? ";
    cin >> celcius;
    fahrenheit = ctof(celcius);
    cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
    return 0;
}

float ctof(float celcius){
    return (celcius * 1.8) + 32;
}
```

Kode ini berfungsi untuk mengonversi suhu dari Celcius ke Fahrenheit dengan menggunakan sebuah fungsi terpisah bernama ctof. Program awalnya meminta kita memasukkan angka suhu Celcius yang kemudian dikirim ke dalam fungsi ctof tersebut. Di dalam fungsi itu, angka suhu dihitung menggunakan rumus perkalian 1.8 ditambah 32. Hasil perhitungannya kemudian dikembalikan lagi ke program utama untuk langsung dicetak ke layar.


## Unguided

### 1. (Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.)

```C++
#include <iostream>
using namespace std;
int main(){
    float a, b;
    cin >> a;
    cin >> b;
    cout << "penjumlahan : " << a + b << endl;
    cout << "pengurangan : " << a - b << endl;
    cout << "perkalian : " << a * b << endl;
    cout << "pembagian : " << a / b << endl;
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_1/screenshot/ss_soal_1.png)

Code diatas berfungsi untuk menjadi kalkulator sederhana yang akan menampilkan penjumlahan, pengurangan, perkalian, dan pembagian yang dapat melakukan operasi dengan angka desimal atau float. Pertama program akan meminta dua inputan yaitu a dan b. Setelah dua angka diinput maka program akan menjalankan empat operasi matematika yang berurutan dimulai dari tambah kurang kali lalu bagi

### 2. (Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100)

```C++
#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    string angka[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    if (a == 0) {
        cout << a << " : nol";
    } 
    else if (a < 10) {
        cout << a << ":" << angka[a];
    } 
    else if (a == 10) {
        cout << a << " : sepuluh";
    } 
    else if (a == 11) {
        cout << a << " : sebelas";
    } 
    else if (a < 20) {
        cout << a << ":" << angka[a % 10] << " belas";
    } 
    else if (a < 100) {
        cout << a << ":" << angka[a / 10] << " puluh";
        if (a % 10 != 0) {
            cout << " " << angka[a % 10];
        }
    } 
    else if (a == 100) {
        cout << a << " : seratus";
    }
    cout << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_1/screenshot/ss_soal_2.png)

Program tersebut membaca sebuah bilangan bulat a dari input, lalu menuliskan angka tersebut dalam bentuk kata sesuai aturan bahasa Indonesia. Untuk angka 0–9, program menggunakan array string angka[] yang berisi kata nol hingga sembilan. Jika a bernilai 10 atau 11, program menampilkan sepuluh atau sebelas. Untuk angka 12–19, program menuliskan kata satuan ditambah belas, misalnya 13 menjadi tiga belas. Jika a antara 20–99, program menuliskan kata puluhan dengan format x puluh y, misalnya 25 menjadi dua puluh lima. Terakhir, jika a = 100, program menampilkan seratus. Dengan demikian, logika if-else digunakan untuk mengubah angka ke dalam bentuk kata sesuai rentang nilainya.

### 3. (Buatlah program yang dapat memberikan input dan output sbb.)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; i--) {
        
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }

        for (int k = i; k >= 1; k--) {
            cout << k << " ";
        }

        cout << "*";

        for (int k = 1; k <= i; k++) {
            cout << " " << k;
        }

        cout << endl;
    }

    return 0;
}

```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/akhsansabili3370-design/109082500062_Akhsan-Sabili-STRUKTUR_DATA/blob/main/MODUL_1/screenshot/ss_soal_3.png)

Program tersebut membaca sebuah bilangan n lalu menggunakan perulangan bersarang untuk mencetak pola angka simetris dengan tanda * di tengah. Perulangan luar for (int i = n; i >= 0; i--) mengatur jumlah baris dari n turun ke 0. Di setiap baris, pertama dicetak spasi sebanyak 2*(n-i) agar pola bergeser ke kanan. Kemudian dicetak angka menurun dari i ke 1, diikuti tanda * sebagai pusat pola, lalu angka naik dari 1 hingga i. Hasil akhirnya adalah bentuk piramida terbalik dengan susunan angka yang simetris di kiri dan kanan tanda bintang. Struktur ini menunjukkan penggunaan loop kosong untuk mengatur spasi, angka menurun, dan angka naik sehingga tercipta pola yang rapi.

## Kesimpulan

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...