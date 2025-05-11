#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    Isi_Tree T1, T2;
    int jumlahNode1, jumlahNode2;
    int menu;

    
    for (int i = 0; i <= jml_maks; i++) {
        T1[i].info = '\0';
        T1[i].ps_fs = nil;
        T1[i].ps_nb = nil;
        T1[i].ps_pr = nil;

        T2[i].info = '\0';
        T2[i].ps_fs = nil;
        T2[i].ps_nb = nil;
        T2[i].ps_pr = nil;
    }


    printf("Masukkan jumlah node untuk Tree 1: ");
    scanf("%d", &jumlahNode1);
    Create_tree(T1, jumlahNode1);

    do {
        printf("\n1. Traversal PreOrder");
        printf("\n2. Traversal InOrder");
        printf("\n3. Traversal PostOrder");
        printf("\n4. Traversal Level Order");
        printf("\n5. Print visualisasi Tree");
        printf("\n6. Search node Tree");
        printf("\n7. Jumlah Daun/Leaf");
        printf("\n8. Mencari Level node Tree");
        printf("\n9. Kedalaman Tree");
        printf("\n10. Membandingkan 2 node Tree");
        printf("\n11. Print Tree");
        printf("\n12. Exit");
        printf("\nPilih Menu: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                printf("\n=== PreOrder Traversal ===\n");
                PreOrder(T1);
                break;
            case 2:
                printf("\n=== InOrder Traversal ===\n");
                InOrder(T1);
                break;
            case 3:
                printf("\n=== PostOrder Traversal ===\n");
                PostOrder(T1);
                break;
            case 4:
                printf("\n=== Level Order Traversal ===\n");
                Level_order(T1, jumlahNode1);
                break;
            case 5:
                printf("\n=== Print Visual Tree ===\n");
                StartPrintVisualTree(T1);
                break;
            case 6: {
                char cari;
                printf("Masukkan data yang mau dicari: ");
                scanf(" %c", &cari);
                if(Search(T1, cari)) {
                    printf("%c ditemukan di tree.\n", cari);
                } else {
                    printf("%c tidak ditemukan di tree.\n", cari);
                }
                break;
            }
            case 7:
                printf("Jumlah daun: %d\n", nbDaun(T1));
                break;
            case 8: {
                char cari;
                printf("Masukkan data: ");
                scanf(" %c", &cari);
                printf("Level node %c adalah %d.\n", cari, Level(T1, cari));
                break;
            }
            case 9:
                printf("Kedalaman pohon (depth): %d\n", Depth(T1));
                break;
            case 10:{
                printf("Masukkan jumlah node untuk Tree 2: ");
                scanf("%d", &jumlahNode2);
                Create_tree(T2, jumlahNode2);

                int elmt1 = nbElmt(T1);
                int elmt2 = nbElmt(T2);
                int max = Max(elmt1, elmt2);

                printf("Jumlah elemen Tree 1: %d\n", elmt1);
                printf("Jumlah elemen Tree 2: %d\n", elmt2);
                printf("Tree yang lebih besar memiliki %d node.\n", max);
                break;
            }   
            case 11: 
                PrintTree(T1);
                break;
            case 12:
                printf("Keluar dari program.\n");
                break;    
            default:
                printf("Menu tidak valid.\n");
        }

    } while(menu != 12);

    return 0;
}
