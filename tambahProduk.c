#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk menambahkan produk ke dalam file
void tambahproduk(struct Produk produk) {
    FILE *file = fopen("produk.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %d %.2f\n", produk.nama, produk.jumlah, produk.harga);
        fclose(file);
        printf("Produk berhasil ditambahkan.\n");
    } else {
        printf("Gagal membuka file.\n");
    }
}