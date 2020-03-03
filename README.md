# Announcement

Beberapa file yang harus ada dalam repositori tersebut diantaranya:
* Direktori src yang berisi source code yang anda buat.
* File output yang berisi hasil uji dijkstra algorithm pada data uji.
* Makefile. Buatlah sehingga kompilasi program dapat dilakukan hanya dengan pemanggilan command ’make’ saja.
* File README.md yang berisi:
    * Petunjuk penggunaan program.
    * Pembagian tugas. Sampaikan dalam list pengerjaan untuk setiap mahasiswa. Sebagai contoh: XXXX mengerjakan fungsi YYYY, ZZZZ, dan YYZZ.
    * Laporan pengerjaan, dengan struktur laporan sesuai dengan deskripsi pada bagian sebelumnya.

# Readme
## Petunjuk pengunaan program
* Build binary dengan `make`
* Bila ingin menjalankan dijstra-serial gunakan `./MAIN_SERIAL <banyak-node>`
* Bila ingin menjalankan dijstra-parallel gunakan `./MAIN_PARALLEL <banyak-node> <banyak-thread>`

## Pembagian Tugas
* 13517010 membuat program utama serial, membuat makefile, readme
* 13517061 mengubah program serial menjadi parallel, testing

## Laporan Pengerjaan
### Deskripsi Solusi

### Analisis Solusi

### Jumlah Thread

### Pengukuran Kinerja
Data waktu (dalam mikrosekon) pengukuran kinerja sudah merupakan hasil mean dari 5 kali percobaan (kecuali pada kasus 3000) untuk setiap kasus percobaan
Kasus     | Serial       | Parallel
100       | 25147.22     | 3968.86
500       | 3065850.1    | 267327.54
1000      | 22648403.66  | 2022286.14
3000      | 590860173.1  | 70485652.00

### Analisis Perbandingan Kinerja
Dari analisis singkat kami, dapat dilihat bahwa peningkatan kecepatan yang didapat dari proses pararel sekitar 10X lipat labih baik dari pada proses serial


