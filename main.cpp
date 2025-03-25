#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    List L;
    infotype X;
    int pilihan;
    CreateEmpty(&L); 
    
    do {
        printf("\nMENU STACK LINKED LIST");
        printf("\n1. Push (Tambah Elemen)");
        printf("\n2. Exit");
        printf("\nPilihan: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                printf("Masukkan elemen: ");
                scanf("%d", &X); 
                DecimalToBinary(X); 
                printf("Elemen %d telah ditambahkan ke stack.\n", X);
                break;
            case 2:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 2);

    return 0;
}

// int main() {
//     List L;
//     infotype X;
//     int choice, value, precValue;
//     address Prec;  // Pindahkan deklarasi ke sini

//     CreateList(&L);
//     printf("List dibuat.\n");

//     do {
//         printf("\nMenu:\n");
//         printf("1. Insert First\n");
//         printf("2. Insert Last\n");
//         printf("3. Insert After\n");
//         printf("4. Delete First\n");
//         printf("5. Delete Last\n");
//         printf("6. Delete Value\n");
//         printf("7. Delete All Ganjil\n");
//         printf("8. Print List\n");
//         printf("9. Exit\n");
//         printf("Pilih operasi: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Masukkan nilai: ");
//                 scanf("%d", &value);
//                 InsVFirst(&L, value);
//                 break;
//             case 2:
//                 printf("Masukkan nilai: ");
//                 scanf("%d", &value);
//                 InsVLast(&L, value);
//                 break;
//             case 3:
//                 printf("Masukkan nilai baru: ");
//                 scanf("%d", &value);
//                 printf("Masukkan nilai elemen sebelum nilai baru: ");
//                 scanf("%d", &precValue);

//                 Prec = First(L);
//                 while (Prec != Nil && Info(Prec) != precValue) {
//                     Prec = Next(Prec);
//                 }

//                 if (Prec != Nil) {
//                     address P = Alokasi(value);
//                     if (P != Nil) {
//                         InsertAfter(&L, P, Prec);
//                     } else {
//                         printf("Gagal mengalokasikan memori!\n");
//                     }
//                 } else {
//                     printf("Elemen %d tidak ditemukan.\n", precValue);
//                 }
//                 break;
//             case 4:
//                 DelVFirst(&L, &X);
//                 printf("Elemen pertama (%d) dihapus.\n", X);
//                 break;
//             case 5:
//                 DelVLast(&L, &X);
//                 printf("Elemen terakhir (%d) dihapus.\n", X);
//                 break;
//             case 6:
//                 printf("Masukkan nilai yang ingin dihapus: ");
//                 scanf("%d", &value);
//                 DelP(&L, value);
//                 break;
//             case 7:
//                 DelAllGanjil(&L);
//                 printf("Semua bilangan ganjil dihapus.\n");
//                 break;
//             case 8:
//                 PrintInfo(L);
//                 break;
//             case 9:
//                 printf("Keluar dari program.\n");
//                 break;
//             default:
//                 printf("Pilihan tidak valid!\n");
//         }
//     } while (choice != 9);

//     return 0;
// }
