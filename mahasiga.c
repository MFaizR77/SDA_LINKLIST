#include <limits.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "mahasiswa.h"

boolean ListEmpty(List L) {
    return (First(L) == NULL);
}

void CreateList(List *L) {
    First(*L) = NULL;
}

address CreateMahasiswa(infotype nilai, nim Nim, nama Nama) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        Info(P) = nilai;
        nim(P) = strdup(Nim);
        nama(P) = strdup(Nama);
        Next(P) = NULL;
    }
    return P;
}

void DeAlokasi(address P) {
    if (P != NULL) {
        free(nim(P));
        free(nama(P));
        free(P);
    }
}

void RemoveDuplicateNames(List *L) {
    if (ListEmpty(*L)) return;

    address P = First(*L);
    while (P != NULL) {
        address Prec = P;
        address Q = Next(P);

        while (Q != NULL) {
            if (strcmp(nama(P), nama(Q)) == 0) {
                address temp = Q;
                Next(Prec) = Next(Q);
                Q = Next(Q);
                DeAlokasi(temp);
            } else {
                Prec = Q;
                Q = Next(Q);
            }
        }
        P = Next(P);
    }
}

int CountElements(List L) {
    int count = 0;
    address P = First(L);
    while (P != NULL) {
        count++;
        P = Next(P);
    }
    return count;
}

boolean FSearch(List L, address P) {
    address PSearch = First(L);
    while (PSearch != Nil) {
        if (PSearch == P) {
            return true;
        }
        PSearch = Next(PSearch);
    }
    return false;
}

address Search(List L, nim Nim) {
    address P = First(L);
    while (P != NULL && strcmp(nim(P), Nim) != 0) {
        P = Next(P);
    }
    return P;
}

void InsVFirst(List *L, infotype nilai, nim Nim, nama Nama) {
    address P = CreateMahasiswa(nilai, Nim, Nama);
    if (P != NULL) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype nilai, nim Nim, nama Nama) {
    address P = CreateMahasiswa(nilai, Nim, Nama);
    if (P != NULL) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            address temp = First(*L);
            while (Next(temp) != NULL) {
                temp = Next(temp);
            }
            Next(temp) = P;
        }
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (P != NULL && Prec != NULL) {  
        Next(P) = Next(Prec);  
        Next(Prec) = P;  
    }
}



void DelP(List *L, nama Nama) {
    address P = First(*L), Prec = NULL;

    while (P != NULL && strcmp(nama(P), Nama) != 0) {
        Prec = P;
        P = Next(P);
    }

    if (P != NULL) {
        if (Prec == NULL) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        DeAlokasi(P);
    }
}

void DelVFirst(List *L) {
    if (!ListEmpty(*L)) {
        address P = First(*L);
        First(*L) = Next(P);
        DeAlokasi(P);
    }
}

void DelVLast(List *L) {
    if (!ListEmpty(*L)) {
        address P = First(*L), Prec = Nil;
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
        DeAlokasi(P);
    }
}


void DelAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Next(Prec) != NULL) {
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        
        free(nim(*Pdel));  
        free(nama(*Pdel)); 
        free(*Pdel);       
    }
}


void DelAll(List *L) {
    address P;
    while (First(*L) != Nil) {
        P = First(*L);
        First(*L) = Next(P);
        DeAlokasi(P);
    }
}


void PrintInfo(List L) {
    address P = First(L);
    if (P == NULL) {
        printf("List kosong\n");
        return;
    }
    while (P != NULL) {
        printf("%d - %s - %s -> ", Info(P), nim(P), nama(P));
        P = Next(P);
    }
    printf("NULL\n");
}

boolean CheckValue(infotype nilai) {
    return nilai > 70;
}

void SortingByValue(List *L) {
    if (ListEmpty(*L) || Next(First(*L)) == NULL) return;

    for (address P = First(*L); P != NULL; P = Next(P)) {
        for (address Q = Next(P); Q != NULL; Q = Next(Q)) {
            if (Info(P) > Info(Q)) {
                infotype temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;

                char *tempNama = nama(P);
                nama(P) = nama(Q);
                nama(Q) = tempNama;

                char *tempNim = nim(P);
                nim(P) = nim(Q);
                nim(Q) = tempNim;
            }
        }
    }
}

void SortingByName(List *L) {
    if (ListEmpty(*L) || Next(First(*L)) == NULL) return;

    for (address P = First(*L); P != NULL; P = Next(P)) {
        for (address Q = Next(P); Q != NULL; Q = Next(Q)) {
            if (strcmp(nama(P), nama(Q)) > 0) {
                infotype temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;

                char *tempNama = nama(P);
                nama(P) = nama(Q);
                nama(Q) = tempNama;

                char *tempNim = nim(P);
                nim(P) = nim(Q);
                nim(Q) = tempNim;
            }
        }
    }
}

void ChangeListTo(List *L1, List *L2) {
    address P = First(*L1), Prec = NULL;
    while (P != NULL) {
        if (CheckValue(Info(P))) {
            address temp = P;
            if (Prec == NULL) {
                First(*L1) = Next(P);
            } else {
                Next(Prec) = Next(P);
            }
            P = Next(P);
            
            Next(temp) = First(*L2);
            First(*L2) = temp;
        } else {
            Prec = P;
            P = Next(P);
        }
    }
}
