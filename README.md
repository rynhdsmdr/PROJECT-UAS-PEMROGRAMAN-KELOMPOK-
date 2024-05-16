Anggota:
- Riyan Hadi Samudra
- Tasya Zahrani
- Alief Aulia SAG

cara menjalankan kode program tersebut adalah sebagai berikut :

buka command prompt atau terminal pada komputer.
lalu, kompilasi setiap berkas sumber menjadi sumber berkas objek menggunakan kompilasi c seperti GCC dengan menggunakan perintah
gcc -c tambahProduk.c
gcc -c kurangiProduk.c
gcc -c login.c
gcc -c menambahkanMember.c
gcc -c menampilkanProduk.c
gcc - c pembayaran.c
gcc -c menampilkanMember.c
gcc -c main.c

gabungkan berkas objek menjadi program eksekusi dalam perintah ini nama program eksekusinya adalah PROJEK_UASLAB_PEMROGRAMAN dengan sintaks gcc tambahProduk.o kurangiProduk.o login.o menambahkanMember.o menampilkanProduk.o pembayaran.o menampilkanMember.o main.o -o PROJEK_UASLAB_PEMROGRAMAN

untuk menjalankan program eksekusinya kita menggunakan sintaks ./PROJEK_UASLAB_PEMROGRAMAN

kemudian program akan menampilkan menu untuk memilih operasi yang diinginkan dan memasukkan pilihan tersebut, setelah memilih operasi maka pengguna diminta untuk memasukkan data yang sesuai dengan operasi yang dipilih.

setelah kita memasukkan bilangan, maka program akan melakukan konversi sesuai dengan pilihan operasi kita tadi dan mencetak hasilnya ke layar.
apabila pengguna memasukkan pilihan yang tidak valid, maka program tersebut akan menampilkan "pilihan Anda tidak valid."
