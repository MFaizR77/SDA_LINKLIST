#include "header.h"
#include <stdio.h>

void Create_tree(Isi_Tree X, int Jml_Node){
    int i;
    infotype data;
    fo(i, n){
        printf("Masukkan data node ke-%d: ", i);
        scanf(" %c", &data);  
        X[i].info = data;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    fo(i, n){
        int child;
        printf("Masukkan child pertama dari %c (0 jika tidak ada): ", X[i].info);
        scanf("%d", &child);
        if(child != 0){
            X[i].ps_fs = child;
            X[child].ps_pr = i;

            int sibling = child;
            while(1){
                int next_sibling;
                printf("Masukkan next sibling dari %c (0 jika tidak ada): ", X[sibling].info);
                scanf("%d", &next_sibling);
                if(next_sibling == 0)
                    break;
                X[sibling].ps_nb = next_sibling;
                X[next_sibling].ps_pr = i;
                sibling = next_sibling;
            }
        }
    }
}

boolean IsEmpty (Isi_Tree P){
    return (P[1].info == '\0');
}

void PreOrder(Isi_Tree P) {
    e return;

    int stack[100];
    int top = -1;

    stack[++top] = 1;

    while (top != -1) {
        int curr = stack[top--];
        printf("%c ", P[curr].info);

        
        int child = P[curr].ps_fs;
        int children[100];
        int n = 0;

        while (child != nil) {
            children[n++] = child;
            child = P[child].ps_nb;
        }

        for (int i = n - 1; i >= 0; i--) {
            stack[++top] = children[i];
        }
    }
}


void InOrder(Isi_Tree P) {
    e return;

    typedef struct {
        int idx;
        int stage; 
    } StackItem;

    StackItem stack[100];
    int top = -1;

    stack[++top] = (StackItem){1, 0};

    while (top != -1) {
        StackItem *curr = &stack[top];

        if (curr->stage == 0) {
          
            curr->stage = 1;
            int left = P[curr->idx].ps_fs;
            if (left != nil) {
                stack[++top] = (StackItem){left, 0};
            }
        } else if (curr->stage == 1) {
        
            curr->stage = 2;
            printf("%c ", P[curr->idx].info);
           
            int fs = P[curr->idx].ps_fs;
            if (fs != nil) {
                int right = P[fs].ps_nb; 
                if (right != nil)
                    stack[++top] = (StackItem){right, 0};
            }
        } else {
            top--;
        }
    }
}



void PostOrder(Isi_Tree P) {
    e return;

    typedef struct {
        int idx;
        int visited;
    } StackItem;

    StackItem stack[100];
    int top = -1;

    stack[++top] = (StackItem){1, 0};

    while (top != -1) {
        StackItem *curr = &stack[top];

        if (curr->visited == 0) {
            curr->visited = 1;

            int child = P[curr->idx].ps_fs;
            int children[100];
            int n = 0;

            while (child != nil) {
                children[n++] = child;
                child = P[child].ps_nb;
            }

            for (int i = n - 1; i >= 0; i--) {
                stack[++top] = (StackItem){children[i], 0};
            }
        } else {
            printf("%c ", P[curr->idx].info);
            top--;
        }
    }
}


void Level_order(Isi_Tree X, int Maks_node){
    for(int i = 1; i <= Maks_node; i++){
        printf("%c ", X[i].info);
    }
}

void PrintTree(Isi_Tree T) {
    printf("\nSeluruh Node pada Non Binary Tree:\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (T[i].info != '\0') {
            printf("\n--> Indeks ke-%d", i);
            printf("\n------------------------------------");
            printf("\ninfo array ke %d     :    %c", i, T[i].info);
            printf("\nfirst son array ke %d:    %d", i, T[i].ps_fs);
            printf("\nnext brother array ke %d: %d", i, T[i].ps_nb);
            printf("\nparent array ke %d   :    %d", i, T[i].ps_pr);
            printf("\n------------------------------------");
        }
    }
    printf("\nKlik apapun untuk melanjutkan!\n");
    getchar(); getchar();  
}

boolean Search (Isi_Tree P, infotype X){
    for(int i = 1; i <= jml_maks; i++){
        if(P[i].info == X)
            return true;
    }
    return false;
}

int nbElmt (Isi_Tree P){
    int count = 0;
    for(int i = 1; i <= jml_maks; i++){
        if(P[i].info != '\0')
            count++;
    }
    return count;
}

int nbDaun (Isi_Tree P){
    int count = 0;
    for(int i = 1; i <= jml_maks; i++){
        if(P[i].info != '\0' && P[i].ps_fs == nil)
            count++;
    }
    return count;
}

int Level (Isi_Tree P, infotype X){
    int idx = -1;
    for(int i = 1; i <= jml_maks; i++){
        if(P[i].info == X){
            idx = i;
            break;
        }
    }
    if(idx == -1)
        return -1;

    int level = 0;
    while(P[idx].ps_pr != nil){
        idx = P[idx].ps_pr;
        level++;
    }
    return level;
}

int Depth (Isi_Tree P){
    int max_depth = 0;
    for(int i = 1; i <= jml_maks; i++){
        if(P[i].info != '\0'){
            int depth = 0, idx = i;
            while(P[idx].ps_pr != nil){
                idx = P[idx].ps_pr;
                depth++;
            }
            if(depth > max_depth)
                max_depth = depth;
        }
    }
    return max_depth;
}

int Max (infotype Data1, infotype Data2){
    return (Data1 > Data2) ? Data1 : Data2;
}

void PrintVisualTree(Isi_Tree P, int idx, int depth){
    if(idx != nil && P[idx].info != '\0'){
        for(int i = 0; i < depth; i++){
            printf("|--");  
        }
        printf("%c\n", P[idx].info);

        if(P[idx].ps_fs != nil){
            PrintVisualTree(P, P[idx].ps_fs, depth + 1);
        }

        if(P[idx].ps_nb != nil){
            PrintVisualTree(P, P[idx].ps_nb, depth);
        }
    }
}

void StartPrintVisualTree(Isi_Tree P){
    if (!IsEmpty(P)){
        PrintVisualTree(P, 1, 0); 
    }
}


