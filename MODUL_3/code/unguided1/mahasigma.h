#ifndef MAHASIGMA_H_INCLUDED
#define MAHASIGMA_H_INCLUDED

struct mahasigma {
    char nama[50];
    char nim[15];
    float uts, uas, tugas;
    float nilaiAkhir;
};

void inputMhs(mahasigma &m);
float hitungNilaiAkhir(mahasigma m);
void tampilMhs(mahasigma m);

#endif
