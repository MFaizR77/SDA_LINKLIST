#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *infotype;

typedef struct tOrang *addressOrang;
typedef struct tKota *addressKota;

typedef struct tOrang {
    infotype nm;
    addressOrang nextOrang;
} Orang;

typedef struct tKota {
    infotype kt;
    addressOrang listOrang;
    addressKota nextKota;
} Kota;

typedef struct {
    addressKota First;
} List;


void CreateListKota(List *L);
addressKota AlokasiKota(infotype X);
addressOrang AlokasiOrang(infotype X);
void InsertLastKota(List *L, infotype namaKota);
void InsertFirstKota(List *L, infotype namaKota);
void InsertLastOrang(addressKota kota, infotype namaOrang);
void InsertFirstOrang(addressKota kota, infotype namaOrang);
void TampilList(List L);
void DealokasiList(List *L);
void HitungTotal(List L);

#endif
