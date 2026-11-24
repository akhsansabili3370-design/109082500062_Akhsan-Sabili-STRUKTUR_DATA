
#include <iostream>
#include "queue.h"
using namespace std;

void jalankanQueue(int mode) {
    Queue Q;
    createQueue(Q, mode);

    cout << "\nSOAL " << mode << endl;

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);
}

int main() {
    jalankanQueue(1);
    jalankanQueue(2);
    jalankanQueue(3);

    return 0;
}
