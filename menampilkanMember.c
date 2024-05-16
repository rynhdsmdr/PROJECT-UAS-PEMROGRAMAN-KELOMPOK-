#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk menampilkan daftar member dari file
void tampilkanmember() {
    FILE *file = fopen("members.txt", "r");
    if (file != NULL) {
        struct Member member;
        printf("Nama\t\tUmur\t\tAlamat\n");
        while (fscanf(file, "%s %d %s", member.nama, &member.umur, &member.alamat) != EOF) {
            printf("%s\t\t%d\t\t%s\n", member.nama, member.umur, member.alamat);
        }
        fclose(file);
    } else {
        printf("Gagal membuka file.\n");
    }
}