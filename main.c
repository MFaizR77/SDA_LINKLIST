#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    List dataKota;
    CreateListKota(&dataKota);

    int pilihan;
    char buffer[100];
    char namaKota[100], namaOrang[100];
    addressKota kotaDipilih = NULL;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Kota (Akhir)\n");
        printf("2. Tambah Kota (Awal)\n");
        printf("3. Tambah Orang ke Kota (Akhir)\n");
        printf("4. Tambah Orang ke Kota (Awal)\n");
        printf("5. Tampilkan Seluruh Kota dan Orang\n");
        printf("6. Tampilkan Total Kota & Nama\n");
        printf("7. Keluar\n");
        printf("Pilihan: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                InsertLastKota(&dataKota, namaKota);
                break;

            case 2:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                InsertFirstKota(&dataKota, namaKota);
                break;

            case 3:
            case 4:
                printf("Masukkan nama kota tempat orang ditambahkan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;

                kotaDipilih = dataKota.First;
                while (kotaDipilih != NULL && strcmp(kotaDipilih->kt, namaKota) != 0) {
                    kotaDipilih = kotaDipilih->nextKota;
                }

                if (kotaDipilih != NULL) {
                    printf("Masukkan nama orang: ");
                    fgets(namaOrang, sizeof(namaOrang), stdin);
                    namaOrang[strcspn(namaOrang, "\n")] = 0;

                    if (pilihan == 3) {
                        InsertLastOrang(kotaDipilih, namaOrang);
                    } else {
                        InsertFirstOrang(kotaDipilih, namaOrang);
                    }
                } else {
                    printf("Kota tidak ditemukan.\n");
                }
                break;

            case 5:
                TampilList(dataKota);
                break;

            case 6:
                HitungTotal(dataKota);
                break;

            case 7:
                DealokasiList(&dataKota);
                printf("Terima kasih!\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 7);

    return 0;
}
