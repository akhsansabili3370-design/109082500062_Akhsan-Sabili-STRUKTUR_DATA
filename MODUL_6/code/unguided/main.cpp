
#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P, Prec, Hapus;

    CreateList(L);

    while (true) {
        cout << "\nMasukkan nomor polisi (0 untuk selesai): ";
        cin >> x.nopol;

        if (x.nopol == "0") {
            break;
        }

        if (findElm(L, x) != NULL) {
            cout << "Nomor polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        P = alokasi(x);
        insertLast(L, P);
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    cout << "\nMasukkan nomor polisi yang dicari: ";
    cin >> x.nopol;

    P = findElm(L, x);

    if (P != NULL) {
        cout << "\nNomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    cin >> x.nopol;

    P = findElm(L, x);

    if (P != NULL) {
        if (P == L.First) {
            deleteFirst(L, Hapus);
        } else if (P == L.Last) {
            deleteLast(L, Hapus);
        } else {
            Prec = P->prev;
            deleteAfter(Prec, Hapus);
        }

        dealokasi(Hapus);

        cout << "Data dengan nomor polisi "
             << x.nopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    cout << "\nDATA LIST 1 SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    return 0;
}
