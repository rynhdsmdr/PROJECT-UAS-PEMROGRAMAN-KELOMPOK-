#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk menambahkan member ke dalam file
void tambahmember(struct Member member) {
    FILE *file = fopen("members.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %d %s\n", member.nama, member.umur, member.alamat);
        fclose(file);
        printf("Member berhasil ditambahkan.\n");
    } else {
        printf("Gagal membuka file.\n");
    }
}
