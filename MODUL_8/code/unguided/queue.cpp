
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q, int mode) {
    Q.head = -1;
    Q.tail = -1;
    Q.jumlah = 0;
    Q.alternatif = mode;
}

bool isEmptyQueue(Queue Q) {
    return Q.jumlah == 0;
}

bool isFullQueue(Queue Q) {
    if (Q.alternatif == 3) {
        return Q.jumlah == 5;
    }

    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype input) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (Q.alternatif == 1) {
            if (isEmptyQueue(Q)) {
                Q.head = 0;
            }
            Q.tail++;
        }
        else if (Q.alternatif == 2) {
            if (isEmptyQueue(Q)) {
                Q.head = 0;
                Q.tail = 0;
            } else {
                Q.tail++;
            }
        }
        else if (Q.alternatif == 3) {
            if (isEmptyQueue(Q)) {
                Q.head = 0;
                Q.tail = 0;
            } else {
                Q.tail = (Q.tail + 1) % 5;
            }
        }

        Q.info[Q.tail] = input;
        Q.jumlah++;
    }
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        if (Q.alternatif == 1) {
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }

            Q.tail--;
        }
        else if (Q.alternatif == 2) {
            if (Q.head == Q.tail) {
                Q.head = -1;
                Q.tail = -1;
            } else {
                Q.head++;
            }
        }
        else if (Q.alternatif == 3) {
            if (Q.head == Q.tail) {
                Q.head = -1;
                Q.tail = -1;
            } else {
                Q.head = (Q.head + 1) % 5;
            }
        }

        Q.jumlah--;

        if (Q.jumlah == 0) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
}


void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    }
    else {
        if (Q.alternatif == 1) {
            for (int i = 0; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
        else if (Q.alternatif == 2) {
            for (int i = Q.head; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
        else if (Q.alternatif == 3) {
            int i = Q.head;

            for (int j = 0; j < Q.jumlah; j++) {
                cout << Q.info[i] << " ";
                i = (i + 1) % 5;
            }
        }
    }

    cout << endl;
}

