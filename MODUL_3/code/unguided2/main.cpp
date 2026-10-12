#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "ALGORITMA PEMROGRAMAN";
    string kodepel = "ALPRO";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
