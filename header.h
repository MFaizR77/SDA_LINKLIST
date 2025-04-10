#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include <ctype.h>


typedef char infotype;


typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;


typedef struct {
    address First;
} List;

typedef List Stack;
typedef List Queue;

void CreateNode(address *p, infotype data);

address Alokasi(infotype data);

void DeAlokasi(address *p);

boolean IsListEmpty(List L);

boolean IsFull(List L);

void PrintList(List L);

void InsVLast(List *L, infotype X);

void InsertLast(List *L, address P);

int CountElement(List L);

void DelVFirst(List *L, infotype *X);

void DelFirst(List *L, address *P);

void InsertFirst(List *L, infotype X);

void DecimalToBinary(int n);

void CheckPalindrome(char *input);

   

#endif
