#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


typedef int infotype;


typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;


typedef struct {
    address First;
} List;


typedef List Stack;



boolean ListEmpty(List L);


address Alokasi(infotype X);
void DeAlokasi(address P);

void PrintList(List L);
void InsertFirst(List *L, infotype X);
void DelFirst(List *L, infotype *X);
void DecimalToBinary(int n);

#endif
