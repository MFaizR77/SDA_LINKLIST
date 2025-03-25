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


void CreateNode(address *p, infotype data);

void DeAlokasi(address *p);

boolean isEmpty(List L);

boolean IsFull(List L);

void PrintList(List L);

void InsVLast(List *L, infotype X);
void InsertLast(List *L, address P);

int CountElement(List L);

void DelVFirst(List *L, infotype *X);
void DelFirst(List *L, address *P);

#endif
