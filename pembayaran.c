#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk melakukan pembayaran
void pembayaran() {
    FILE *file = fopen("produk.txt", "r");
    float total = 0;

    if (file != NULL) {
        struct Produk produk;
        while (fscanf(file, "%s %d %f", produk.nama, &produk.jumlah, &produk.harga) != EOF) {
            total += produk.jumlah * produk.harga;
        }
        fclose(file);
        printf("Total pembayaran: %.2f\n", total);
        FILE *pembayaranFile = fopen("pembayaran.txt", "a");
        if (pembayaranFile != NULL) {
            fprintf(pembayaranFile, "Total pembayaran: %.2f\n", total);
            fclose(pembayaranFile);
            printf("Pembayaran berhasil disimpan.\n");
        } else {
            printf("Gagal menyimpan pembayaran.\n");
        }
    } else {
        printf("Gagal membuka file.\n");
    }
}