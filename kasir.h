#ifndef KASIR_H
#define KASIR_H

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
void tambahproduk(struct Produk produk);

// Fungsi untuk mengurangi jumlah produk dari file
void kurangiproduk(char *namaproduk, int jumlah);

// Fungsi untuk menampilkan daftar produk dari file
void tampilkanproduk();

// Fungsi untuk melakukan pembayaran
void pembayaran();

// Fungsi untuk melakukan login
int login(char *username, char *password);

// Fungsi untuk menambahkan member ke dalam file
void tambahmember(struct Member member);

// Fungsi untuk menampilkan daftar member dari file
void tampilkanmember();

#endif