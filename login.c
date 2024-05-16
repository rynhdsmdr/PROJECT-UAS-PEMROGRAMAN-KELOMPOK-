#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk melakukan login
int login(char *username, char *password) {
    FILE *file = fopen("logins.txt", "r");
    if (file != NULL) {
        struct Pengguna pengguna;
        while (fscanf(file, "%s %s", pengguna.username, pengguna.password) != EOF) {
            if (strcmp(username, pengguna.username) == 0 && strcmp(password, pengguna.password) == 0) {
                fclose(file);
                return 1; // Login berhasil
            }
        }
        fclose(file);
    }
    return 0; // Login gagal
}