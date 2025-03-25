#include "queue.h"

void CreateNode(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = data;
        (*p)->next = NULL;
    } else {
        printf("Alokasi memori gagal!\n");
    }
}


void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}


boolean isEmpty(List L) {
    return (L.First == NULL);
}


void PrintList(List L) {
    address temp = L.First;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}


void InsVLast(List *L, infotype X) {
    address P;
    CreateNode(&P, X);
    if (P != NULL) {
        InsertLast(L, P);
    }
}


void InsertLast(List *L, address P) {
    if (isEmpty(*L)) {
        L->First = P;
    } else {
        address temp = L->First;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}


void DelVFirst(List *L, infotype *X) {
    if (!isEmpty(*L)) {
        address P = L->First;
        *X = P->info; 
        L->First = P->next;
        DeAlokasi(&P);
    }
}


void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = L->First;
        L->First = (*P)->next;
        (*P)->next = NULL;
    }
}

int CountElement(List L) {
    int count = 0;
    address temp = L.First;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


boolean IsFull(List L){
  return CountElement(L)>= MAXQueue;
}
