#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk mengurangi jumlah produk dari file
void kurangiproduk(char *namaproduk, int jumlah) {
    FILE *tempFile = fopen("temp.txt", "w");
    FILE *file = fopen("produk.txt", "r");

    if (file == NULL || tempFile == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    struct Produk produk;
    int found = 0;

    while (fscanf(file, "%s %d %f", produk.nama, &produk.jumlah, &produk.harga) != EOF) {
        if (strcmp(produk.nama, namaproduk) == 0) {
            if (produk.jumlah >= jumlah) {
                produk.jumlah -= jumlah;
                found = 1;
            } else {
                printf("Stok tidak mencukupi untuk pengurangan.\n");
            }
        }
        fprintf(tempFile, "%s %d %.2f\n", produk.nama, produk.jumlah, produk.harga);
    }

    fclose(file);
    fclose(tempFile);

    remove("produk.txt");
    rename("temp.txt", "produk.txt");

    if (!found) {
        printf("Produk tidak ditemukan.\n");
    }
}