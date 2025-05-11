#include <stdio.h>
#include <string.h>
#include "header.h"


int main() {
    Isi_Tree T;
    int jumlahNode;

    for(int i = 0; i <= jml_maks; i++){
        T[i].info = '\0';
        T[i].ps_fs = nil;
        T[i].ps_nb = nil;
        T[i].ps_pr = nil;
    }

    printf("Masukkan jumlah node: ");
    scanf("%d", &jumlahNode);

    Create_tree(T, jumlahNode);

    printf("\n=== Print Visual Tree ===\n");
    StartPrintVisualTree(T);

    printf("\n=== PreOrder Traversal ===\n");
    PreOrder(T);

    printf("\n\n=== InOrder Traversal ===\n");
    InOrder(T);

    printf("\n\n=== PostOrder Traversal ===\n");
    PostOrder(T);

    printf("\n\n=== Level Order Traversal ===\n");
    Level_order(T, jumlahNode);

    printf("\n\n=== Detail Isi Tree ===\n");
    PrintTree(T);


    printf("\nJumlah elemen: %d\n", nbElmt(T));
    printf("Jumlah daun: %d\n", nbDaun(T));
    printf("Kedalaman pohon (depth): %d\n", Depth(T));

    char cari;
    printf("\nMasukkan data yang mau dicari: ");
    scanf(" %c", &cari);

    if(Search(T, cari)){
        printf("%c ditemukan di tree.\n", cari);
        printf("Level node %c adalah %d.\n", cari, Level(T, cari));
    } else {
        printf("%c tidak ditemukan di tree.\n", cari);
    }
    return 0;
}

