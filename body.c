#include "header.h"

void CreateListKota(List *L) {
    L->First = NULL;
}

addressKota AlokasiKota(infotype X) {
    addressKota P = (addressKota)malloc(sizeof(Kota));
    if (P != NULL) {
        P->kt = (infotype)malloc(strlen(X) + 1);
        strcpy(P->kt, X);
        P->listOrang = NULL;
        P->nextKota = NULL;
    }
    return P;
}

addressOrang AlokasiOrang(infotype X) {
    addressOrang P = (addressOrang)malloc(sizeof(Orang));
    if (P != NULL) {
        P->nm = (infotype)malloc(strlen(X) + 1);
        strcpy(P->nm, X);
        P->nextOrang = NULL;
    }
    return P;
}

void InsertLastKota(List *L, infotype namaKota) {
    addressKota P = AlokasiKota(namaKota);
    if (P != NULL) {
        if (L->First == NULL) {
            L->First = P;
        } else {
            addressKota last = L->First;
            while (last->nextKota != NULL) {
                last = last->nextKota;
            }
            last->nextKota = P;
        }
    }
}

void InsertFirstKota(List *L, infotype namaKota) {
    addressKota P = AlokasiKota(namaKota);
    if (P != NULL) {
        P->nextKota = L->First;
        L->First = P;
    }
}

void InsertLastOrang(addressKota kota, infotype namaOrang) {
    addressOrang P = AlokasiOrang(namaOrang);
    if (P != NULL) {
        if (kota->listOrang == NULL) {
            kota->listOrang = P;
        } else {
            addressOrang last = kota->listOrang;
            while (last->nextOrang != NULL) {
                last = last->nextOrang;
            }
            last->nextOrang = P;
        }
    }
}

void InsertFirstOrang(addressKota kota, infotype namaOrang) {
    addressOrang P = AlokasiOrang(namaOrang);
    if (P != NULL) {
        P->nextOrang = kota->listOrang;
        kota->listOrang = P;
    }
}

void TampilList(List L) {
    addressKota K = L.First;
    while (K != NULL) {
        printf("Kota: %s\n", K->kt);
        addressOrang O = K->listOrang;
        while (O != NULL) {
            printf("  - %s\n", O->nm);
            O = O->nextOrang;
        }
        K = K->nextKota;
    }
}

void DealokasiList(List *L) {
    addressKota K = L->First;
    while (K != NULL) {
        addressKota tempK = K;
        addressOrang O = K->listOrang;
        while (O != NULL) {
            addressOrang tempO = O;
            O = O->nextOrang;
            free(tempO->nm);
            free(tempO);
        }
        K = K->nextKota;
        free(tempK->kt);
        free(tempK);
    }
    L->First = NULL;
}

void HitungTotal(List L) {
    addressKota P = L.First;
    int totalKota = 0;
    int totalNama = 0;

    while (P != NULL) {
        totalKota++;

        int jumlahOrang = 0;
        addressOrang O = P->listOrang;
        while (O != NULL) {
            jumlahOrang++;
            totalNama++;
            O = O->nextOrang;
        }

        printf("Jumlah nama di kota '%s' = %d\n", P->kt, jumlahOrang);
        P = P->nextKota;
    }

    printf("\nTotal Kota : %d\n", totalKota);
    printf("Total Nama : %d\n", totalNama);
}