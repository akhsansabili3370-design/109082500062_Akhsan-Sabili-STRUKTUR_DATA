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
