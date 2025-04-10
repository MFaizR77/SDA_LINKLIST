#include "queue.h"
#include "stack.h"

void CreateNode(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = data;
        (*p)->next = NULL;
    } else {
        printf("Alokasi memori gagal!\n");
    }
}

address Alokasi(infotype data) {
    address P;
    CreateNode(&P, data);
    return P;
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}


boolean IsListEmpty(List L) {
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
    if (is_Empty(*L)) {
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
    if (!is_Empty(*L)) {
        address P;
        DelFirst(L, &P);   
        *X = P->info;      
        DeAlokasi(&P);     
    }
}

void DelFirst(List *L, address *P) {
    if (!is_Empty(*L)) {
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


void InsertFirst(List *L, infotype X) {
    address P;
    CreateNode(&P, X);
    if (P != NULL) {
        P->next = L->First;
        L->First = P;
    }
}


void CheckPalindrome(char *input) {
    Stack S;
    Queue Q;
    CreateEmpty(&S);    
    CreateQueue(&Q);

    for (int i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
            char ch = tolower(input[i]);
            Push(&S, ch);       
            EnQueue(&Q, ch);    
        }    
    }
    

    int isPalindrom = 1;
    infotype fromStack, fromQueue;

    while (!IsEmpty(S) && !is_Empty(Q)) {
        Pop(&S, &fromStack);
        deQueue(&Q, &fromQueue);

        if (fromStack != fromQueue) {
            isPalindrom = 0;
            break;
        }
    }

    printf("\"%s\" %s palindrom.\n", input, isPalindrom ? "adalah" : "bukan");
}

