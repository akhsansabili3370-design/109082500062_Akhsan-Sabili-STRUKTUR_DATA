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
