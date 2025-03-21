#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

#define Nil NULL
#define nim(P)  (P)->Nim
#define nama(P)  (P)->Nama
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).first

typedef struct tElmtList *address;
typedef int infotype;
typedef char *nama;
typedef char *nim;

/* Definisi struktur Node */
typedef struct tElmtList {
    infotype info;
    nama Nama;
    nim Nim;
    address next;
} ElmtList;

/* Definisi ADT LinkedList */
typedef struct {
    address first; // Menggunakan pointer ke node pertama
} List;

boolean ListEmpty(List L);
void CreateList(List *L);
address CreateMahasiswa(infotype nilai, nim Nim, nama Nama);
void DeAlokasi(address P);
address Search(List L, nim Nim);
boolean FSearch(List L, address P);
void RemoveDuplicateNames(List *L);
int CountElements(List L);
void InsVFirst(List *L, infotype nilai, nim Nim, nama Nama);
void InsVLast(List *L, infotype nilai, nim Nim, nama Nama);
void DelVFirst(List *L);
void DelVLast(List *L);
void InsertAfter(List *L, address P, address Prec);
void DelP(List *L, nama Nama);
void DelAfter(List *L, address *Pdel, address Prec);
void PrintInfo(List L);
void DelAll(List *L);
void SortingByValue(List *L);
void SortingByName(List *L);
void ChangeListTo(List *L1, List *L2);

#endif
