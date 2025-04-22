#ifndef header_h
#define header_h
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nil NULL
#define max_kt 10
#define max_string 50

typedef char infotype[max_string];
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype nm;
	 address q;
} ElmtList;


typedef struct {
	  address First;
} List;

typedef struct {
	infotype kt;
	List p;
} Kota;

extern Kota kota[max_kt];

void CreateList(List *L);
address Alokasi(infotype X);
void Dealokasi(address P);
void InsertLast(List *L, infotype X);
void DeleteNmandKt(List *L, int *Totkota);
void TampilList(List L);
void initKota();
int cariIndexKota(char *nama_kota);
int HitungNama(List L);

#endif
