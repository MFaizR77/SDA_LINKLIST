#include "stack.h"

boolean ListEmpty(List L) {
    return (L.First == NULL);
}


address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}


void DeAlokasi(address P) {
    if (P != NULL) {
        free(P);
    }
}


void InsertFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        P->next = L->First;
        L->First = P;
    }
}


void DelFirst(List *L, infotype *X) {
    if (!IsEmpty(*L)) {
        address P = L->First;
        *X = P->info;
        L->First = P->next;
        DeAlokasi(P);
    }
}


void PrintList(List L) {
    address P = L.First;
    printf("Stack: ");
    while (P != NULL) {
        printf("%d -> ", P->info);
        P = P->next;
    }
    printf("NULL\n");
}


void DecimalToBinary(int n) {
    List L;
    infotype X;
    CreateEmpty(&L);
    
    if (n == 0) {
        printf("Biner: 0\n");
        return;
    }
    
    while (n > 0) {
        X = n % 2;
        Push(&L, X);
        n /= 2;
    }
	
    PrintList(L);
	printf("Biner: ");
    while (!IsEmpty(L)) {
        Pop(&L, &X);
        printf("%d", X);
    }

    printf("\n");
}
