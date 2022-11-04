#ifndef DINER_DASH_H
#define DINER_DASH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "queueDD.h"


void displayData(int saldo, Queue Qpesanan, Queue Qmasak, Queue Qsaji);
// I.S. saldo, Qpesanan, Qmasak, dan Qsaji terdefinisi. Qpesanan pasti sudah terisi. Qmasak dan Qsaji mungkin kosong
// F.S. Menampilkan nilai saldo, Qpesanan, Qmasak, dan Qsaji dalam bentuk tabel

int rng(int lower, int upper);
// Menghasilkan bilangan random antara [lower..upper]

void initPesanan(Queue *Qpesanan);
// I.S. Queue pesanan terdefinisi dan merupakan queue kosong
// F.S. Queue pesanan terisi 3 elemen yang bernilai random 

void copyElemen(int processID, Queue *Qin, Queue Qout);
// I.S. Qin, Qout, dan idx terdefinisi. Elemen dengan indeks idx terdapat pada Qout
// F.S. Menyalin sebuah elemen queue berindeks idx ke queue lain (Qin) tanpa menghapus elemen dari Qout

boolean isCook(char* command);
// Mengecek apakah masukan berupa 'cook', akan mengembalikan true jika iya

boolean isServe(char* command);
// Mengecek apakah masukan berupa 'serve', akan mengembalikan true jika iya

void sortDurasi(Queue *Qin);
// I.S. Qin terdefinisi, mungkin terurut
// F.S. Qin terurut membesar berdasarkan durasi memasak

void sortID(Queue *Qin); 
// I.S. Qin terdefinisi, mungkin terurut
// F.S. Qin terurut membesar berdasarkan id

void sortKetahanan(Queue *Qin);
// I.S. Qin terdefinisi, mungkin terurut
// F.S. Qin terurut membesar berdasarkan id

boolean isMemberID(Queue Qcek, int processID);
// Mengecek apakah sebuah ID makanan terdapat pada suatu queue. Jika ada, akan mengembalikan true

void displayStatusCook(int processID, Queue Qpesanan, Queue *Qmasak, Queue Qsaji);
// I.S. processID, Qpesanan, Qmasak, dan Qsaji terdefinisi. Qpesanan tidak mungkin kosong
// F.S. Memproses command jika panjang Qmasak tidak lebih dari 5. Jika memenuhi, maka akan menyalin elemen dengan processID dari Qpesanan ke Qmasak

void displayStatusServe(int processID, int *saldo, int *countTerlayani, Queue *Qpesanan, Queue *Qsaji, Queue *Qmasak);
// I.S. processID, saldo, countTerlayani, Qpesanan, dan Qsaji terdefinisi. Qpesaanan tidak mungkin kosong
// F.S. Makanan pada Qsaji dan Qpesanan didequeue
// Proses:  menghilangkan pesanan dari Qpesanan dan Qsaji, menambahkan saldo sesuai harga pesanan, dan menambah jumlah pelanggan terlayani 

void newRound(Queue *Qmasak, Queue *Qsaji);
// I.S. Qmasak dan Qsaji terdefinisi. 
// F.S. Mengurangi durasi dari setiap elemen pada Qmasak dan mengurangi ketahanan pada setiap elemen pada Qsaji

void pindahElemenQmasak(Queue *Qmasak, Queue *Qsaji);
// I.S. Qmasak dan Qsaji terdefinisi 
// F.S. Elemen pada Qmasak tidak ada yang berdurasi 0
// Proses: mengurut Qmasak berdasarkan durasi sehingga lebih mudah untuk didequeue

void pindahElemenQsaji(Queue *Qsaji, Queue *Qpesanan);
// I.S. Qsaji dan Qpesanan terdefinisi 
// F.S. Elemen pada Qsaji tidak ada yang memiliki ketahanan 0

boolean validasiCommand(char *command, int processID, Queue Qpesanan, Queue Qmasak, Queue Qsaji);

void addPesanan(Queue *Qpesanan, int *IDpesanan);
// I.S. Qpesanan dan IDPesanan terdefinisi
// F.S. Menambahkan elemen ke Qpesanan 


#endif