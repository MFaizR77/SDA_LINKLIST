#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mahasiswa.h"

int main() {
    List L1, L2;
    CreateList(&L1);
    CreateList(&L2);
    
    int pilihan;
    infotype nilai;
    char nim[20], nama[50];
    address P, Prec, Pdel;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa (First)\n");
        printf("2. Tambah Mahasiswa (Last)\n");
        printf("3. Hapus Mahasiswa (Berdasarkan Nama)\n");
        printf("4. Cari Mahasiswa\n");
        printf("5. Cetak List\n");
        printf("6. Sorting Berdasarkan Nilai\n");
        printf("7. Sorting Berdasarkan Nama\n");
        printf("8. Pindahkan Mahasiswa (Nilai > 70 ke List 2)\n");
        printf("9. Hapus Nama yang Duplikat di List 2\n");
        printf("10. Hitung Jumlah Mahasiswa\n");
        printf("11. Cek List Kosong\n");
        printf("12. Hapus Elemen Pertama\n");
        printf("13. Hapus Elemen Terakhir\n");
        printf("14. Sisipkan Setelah Elemen Tertentu\n");
        printf("15. Hapus Setelah Elemen Tertentu\n");
        printf("16. Hapus Semua Elemen\n");
        printf("17. Cari Mahasiswa (Search NIM di List)\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';

                printf("Masukkan NIM: ");
                fgets(nim, sizeof(nim), stdin);
                nim[strcspn(nim, "\n")] = '\0';

                printf("Masukkan Nilai: ");
                scanf("%d", &nilai);
                getchar();

                InsVFirst(&L1, nilai, nim, nama);
                break;

            case 2:
                printf("Masukkan Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';

                printf("Masukkan NIM: ");
                fgets(nim, sizeof(nim), stdin);
                nim[strcspn(nim, "\n")] = '\0';

                printf("Masukkan Nilai: ");
                scanf("%d", &nilai);
                getchar();

                InsVLast(&L1, nilai, nim, nama);
                break;

            case 3:
                printf("Masukkan Nama Mahasiswa yang akan dihapus: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';

                DelP(&L1, nama);
                printf("Mahasiswa dengan nama %s telah dihapus.\n", nama);
                break;

            case 4:
                printf("Masukkan NIM Mahasiswa yang dicari: ");
                fgets(nim, sizeof(nim), stdin);
                nim[strcspn(nim, "\n")] = '\0';

                P = Search(L1, nim);
                if (P != NULL) {
                    printf("Mahasiswa ditemukan: %s - %s - %d\n", nim(P), nama(P), Info(P));
                } else {
                    printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
                }
                break;

            case 5:
                printf("\nData Mahasiswa List 1:\n");
                PrintInfo(L1);
                printf("\nData Mahasiswa List 2:\n");
                PrintInfo(L2);
                break;

            case 6:
                SortingByValue(&L1);
                printf("List 1 telah diurutkan berdasarkan nilai.\n");
                break;

            case 7:
                SortingByName(&L1);
                printf("List 1 telah diurutkan berdasarkan nama.\n");
                break;

            case 8:
                ChangeListTo(&L1, &L2);
                printf("Mahasiswa dengan nilai > 70 telah dipindahkan ke List 2.\n");
                break;

            case 9:
                RemoveDuplicateNames(&L2);
                printf("Nama yang duplikat di List 2 telah dihapus.\n");
                break;

            case 10:
                printf("Jumlah Mahasiswa dalam List 1: %d\n", CountElements(L1));
                printf("Jumlah Mahasiswa dalam List 2: %d\n", CountElements(L2));
                break;

            case 11:
                // Menggunakan ListEmpty
                if (ListEmpty(L1)) {
                    printf("List 1 kosong.\n");
                } else {
                    printf("List 1 tidak kosong.\n");
                }
                
                if (ListEmpty(L2)) {
                    printf("List 2 kosong.\n");
                } else {
                    printf("List 2 tidak kosong.\n");
                }
                break;

            case 12:
                // Menggunakan DelVFirst
                if (!ListEmpty(L1)) {
                    DelVFirst(&L1);
                    printf("Elemen pertama List 1 telah dihapus.\n");
                } else {
                    printf("List 1 kosong, tidak ada yang dapat dihapus.\n");
                }
                break;

            case 13:
                // Menggunakan DelVLast
                if (!ListEmpty(L1)) {
                    DelVLast(&L1);
                    printf("Elemen terakhir List 1 telah dihapus.\n");
                } else {
                    printf("List 1 kosong, tidak ada yang dapat dihapus.\n");
                }
                break;

            case 14:
                // Menggunakan InsertAfter
                if (ListEmpty(L1)) {
                    printf("List 1 kosong, tidak dapat menyisipkan elemen.\n");
                } else {
                    printf("Masukkan NIM mahasiswa yang akan dijadikan referensi: ");
                    fgets(nim, sizeof(nim), stdin);
                    nim[strcspn(nim, "\n")] = '\0';
                    Prec = Search(L1, nim);
                    
                    if (Prec != NULL) {
                        printf("Masukkan Nama mahasiswa baru: ");
                        fgets(nama, sizeof(nama), stdin);
                        nama[strcspn(nama, "\n")] = '\0';

                        printf("Masukkan NIM mahasiswa baru: ");
                        fgets(nim, sizeof(nim), stdin);
                        nim[strcspn(nim, "\n")] = '\0';

                        printf("Masukkan Nilai mahasiswa baru: ");
                        scanf("%d", &nilai);
                        getchar();

                        P = CreateMahasiswa(nilai, nim, nama);
                        InsertAfter(&L1, P, Prec);
                        printf("Mahasiswa baru telah disisipkan setelah mahasiswa dengan NIM %s.\n", nim(Prec));
                    } else {
                        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
                    }
                }
                break;

            case 15:
                // Menggunakan DelAfter
                if (ListEmpty(L1)) {
                    printf("List 1 kosong, tidak dapat menghapus elemen.\n");
                } else if (CountElements(L1) < 2) {
                    printf("List 1 hanya memiliki 1 elemen, tidak dapat menggunakan DelAfter.\n");
                } else {
                    printf("Masukkan NIM mahasiswa yang akan dijadikan referensi: ");
                    fgets(nim, sizeof(nim), stdin);
                    nim[strcspn(nim, "\n")] = '\0';
                    
                    Prec = Search(L1, nim);
                    if (Prec != NULL && Next(Prec) != NULL) {
                        DelAfter(&L1, &Pdel, Prec);
                        printf("Mahasiswa setelah mahasiswa dengan NIM %s telah dihapus.\n", nim(Prec));
                        DeAlokasi(Pdel);
                    } else if (Prec != NULL) {
                        printf("Tidak ada mahasiswa setelah mahasiswa dengan NIM %s.\n", nim(Prec));
                    } else {
                        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
                    }
                }
                break;

            case 16:
                // Menggunakan DelAll
                DelAll(&L1);
                DelAll(&L2);
                printf("Semua elemen dalam List 1 dan list 2 telah dihapus.\n");
                break;

            case 17:
                // Menggunakan FSearch
                printf("Masukkan Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';

                printf("Masukkan NIM: ");
                fgets(nim, sizeof(nim), stdin);
                nim[strcspn(nim, "\n")] = '\0';

                printf("Masukkan Nilai: ");
                scanf("%d", &nilai);
                getchar();

                P = CreateMahasiswa(nilai, nim, nama);
                
                if (FSearch(L1, P)) {
                    printf("Mahasiswa dengan data yang sama sudah ada dalam List 1.\n");
                } else {
                    printf("Mahasiswa dengan data tersebut tidak ditemukan dalam List 1.\n");
                }
                
                DeAlokasi(P); // Dealokasi karena sudah tidak dibutuhkan
                break;

            case 0:
                printf("Keluar dari program.\n");
                // Pastikan untuk membersihkan semua memori sebelum keluar
                DelAll(&L1);
                DelAll(&L2);
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}