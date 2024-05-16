#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

int main() {
    char username[MAX_LOGIN_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("enter your username: ")
    scanf("%s", username);
    printf("enter your password: ");
    scanf("%s", password);

    if (login(username, password)) {
        int pilihan;
        do {
            printf("\nMenu:\n");
            printf("1. Tambah produk\n");
            printf("2. Kurangi produk\n");
            printf("3. Lihat daftar produk\n");
            printf("4. Tambah member\n");
            printf("5. Lihat daftar member\n");
            printf("6. Pembayaran\n");
            printf("7. Keluar\n");
            printf("Pilihan Anda: ");
            scanf("%d", &pilihan);

            getchar();

            switch (pilihan) {
                case 1: {
                    struct Produk produkbaru;
                    printf("Masukkan nama produk: ");
                    scanf("%s", produkbaru.nama);
                    printf("Masukkan jumlah produk: ");
                    scanf("%d", &produkbaru.jumlah);
                    printf("Masukkan harga produk: ");
                    scanf("%f", &produkbaru.harga);
                    tambahproduk(produkbaru);
                    break;
                }
                case 2: {
                    char namaproduk[MAX_NAME_LENGTH];
                    int jumlah;
                    printf("Masukkan nama produk: ");
                    scanf("%s", namaproduk);
                    printf("Masukkan jumlah produk yang akan dikurangi: ");
                    scanf("%d", &jumlah);
                    kurangiproduk(namaproduk, jumlah);
                    break;
                }
                case 3: {
                    tampilkanproduk();
                    break;
                    }
                case 4: {
                    struct Member memberbaru;
                    printf("Masukkan nama member: ");
                    scanf("%s", memberbaru.nama);
                    printf("Masukkan umur member: ");
                    scanf("%d", &memberbaru.umur);
                    printf("Masukkan alamat member: ");
                    scanf("%s", memberbaru.alamat);
                    tambahmember(memberbaru);
                    break;
                }
                case 5: {
                    tampilkanmember();
                    break;
                }
                case 6: {
                    pembayaran();
                    break;
                }
                case 7: {
                    printf("Terima kasih, sampai jumpa!\n");
                    break;
                }
                default: {
                    printf("Pilihan tidak valid.\n");
                    break;
                }
            }
        } while (pilihan != 7);
    } else {
        printf("Login failed. please try again.\n");
    }

    return 0;
}
