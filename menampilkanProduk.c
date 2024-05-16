#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk menampilkan daftar produk dari file
void tampilkanproduk() {
    FILE *file = fopen("produk.txt", "r");
    if (file != NULL) {
        struct Produk produk;
        printf("Nama\t\tJumlah\t\tHarga\n");
        while (fscanf(file, "%s %d %f", produk.nama, &produk.jumlah, &produk.harga) != EOF) {
            printf("%s\t\t%d\t\t%.2f\n", produk.nama, produk.jumlah, produk.harga);
        }
        fclose(file);
    } else {
        printf("Gagal membuka file.\n");
    }
}