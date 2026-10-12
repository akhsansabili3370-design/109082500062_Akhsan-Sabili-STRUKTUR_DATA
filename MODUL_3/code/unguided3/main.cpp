
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
