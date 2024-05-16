#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LOGIN_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_MEMBER_NAME_LENGTH 50
#define MAX_MEMBER_EMAIL_LENGTH 50

// Struct untuk menyimpan informasi produk
struct Produk {
    char nama[MAX_NAME_LENGTH];
    int jumlah;
    float harga;
};

// Struct untuk menyimpan informasi pengguna
struct Pengguna {
    char username[MAX_LOGIN_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Struct untuk menyimpan informasi member
struct Member {
    char nama[MAX_NAME_LENGTH];
    int umur;
    char alamat[MAX_NAME_LENGTH];
};

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

int main() {
    char username[MAX_LOGIN_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Masukkan username: ");
    scanf("%s", username);
    printf("Masukkan password: ");
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
        printf("Login gagal. Silakan coba lagi.\n");
    }

    return 0;
}