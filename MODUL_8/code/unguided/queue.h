
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
    int jumlah;
    int alternatif;
};

void createQueue(Queue &Q, int mode);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype input);
void dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
