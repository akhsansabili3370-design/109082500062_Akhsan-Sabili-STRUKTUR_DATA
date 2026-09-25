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