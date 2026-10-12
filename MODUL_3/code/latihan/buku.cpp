#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku){
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanIsiBuku(buku buku)
{
    cout << "judul buku : "<< buku.judul << endl;
    cout << "halaman buku : " << buku.halaman << endl;
    cout << "penulis buku : " << buku.penulis << endl;
}

bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}
