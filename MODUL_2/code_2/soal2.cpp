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