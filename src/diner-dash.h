#ifndef DINER_DASH_H
#define DINER_DASH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "ADT/queue/queueDD.h"
#include "ADT/mesinkata/mesinkata.h"
#include "console.h"


void displayData(int saldo, QueueDD Qpesanan, QueueDD Qmasak, QueueDD Qsaji);
// I.S. saldo, Qpesanan, Qmasak, dan Qsaji terdefinisi. Qpesanan pasti sudah terisi. Qmasak dan Qsaji mungkin kosong
// F.S. Menampilkan nilai saldo, Qpesanan, Qmasak, dan Qsaji dalam bentuk tabel

int rng(int lower, int upper);
// Menghasilkan bilangan random antara [lower..upper]

void initPesanan(QueueDD *Qpesanan);
// I.S. QueueDD pesanan terdefinisi dan merupakan QueueDD kosong
// F.S. QueueDD pesanan terisi 3 elemen yang bernilai random 

void copyElemen(int processID, QueueDD *Qin, QueueDD Qout);
// I.S. Qin, Qout, dan idx terdefinisi. Elemen dengan indeks idx terdapat pada Qout
// F.S. Menyalin sebuah elemen QueueDD berindeks idx ke QueueDD lain (Qin) tanpa menghapus elemen dari Qout

boolean isCook(char* command);
// Mengecek apakah masukan berupa 'cook', akan mengembalikan true jika iya

boolean isServe(char* command);
// Mengecek apakah masukan berupa 'serve', akan mengembalikan true jika iya

boolean isSkip(char* command);
// Mengecek apakah masukan berupa 'skip', akan mengembalikan true jika iya

void sortDurasi(QueueDD *Qin);
// I.S. Qin terdefinisi, mungkin terurut
// F.S. Qin terurut membesar berdasarkan durasi memasak

void sortID(QueueDD *Qin); 
// I.S. Qin terdefinisi, mungkin terurut
// F.S. Qin terurut membesar berdasarkan id

void sortKetahanan(QueueDD *Qin);
// I.S. Qin terdefinisi, mungkin terurut
// F.S. Qin terurut membesar berdasarkan id

boolean isMemberID(QueueDD Qcek, int processID);
// Mengecek apakah sebuah ID makanan terdapat pada suatu QueueDD. Jika ada, akan mengembalikan true

void displayStatusCook(int processID, QueueDD Qpesanan, QueueDD *Qmasak, QueueDD Qsaji);
// I.S. processID, Qpesanan, Qmasak, dan Qsaji terdefinisi. Qpesanan tidak mungkin kosong
// F.S. Memproses command jika panjang Qmasak tidak lebih dari 5. Jika memenuhi, maka akan menyalin elemen dengan processID dari Qpesanan ke Qmasak

void displayStatusServe(int processID, int *saldo, int *countTerlayani, QueueDD *Qpesanan, QueueDD *Qsaji, QueueDD *Qmasak);
// I.S. processID, saldo, countTerlayani, Qpesanan, dan Qsaji terdefinisi. Qpesaanan tidak mungkin kosong
// F.S. Makanan pada Qsaji dan Qpesanan dideQueueDD
// Proses:  menghilangkan pesanan dari Qpesanan dan Qsaji, menambahkan saldo sesuai harga pesanan, dan menambah jumlah pelanggan terlayani 

void newRound(QueueDD *Qmasak, QueueDD *Qsaji);
// I.S. Qmasak dan Qsaji terdefinisi. 
// F.S. Mengurangi durasi dari setiap elemen pada Qmasak dan mengurangi ketahanan pada setiap elemen pada Qsaji

void pindahElemenQmasak(QueueDD *Qmasak, QueueDD *Qsaji);
// I.S. Qmasak dan Qsaji terdefinisi 
// F.S. Elemen pada Qmasak tidak ada yang berdurasi 0
// Proses: mengurut Qmasak berdasarkan durasi sehingga lebih mudah untuk dideQueueDD

void pindahElemenQsaji(QueueDD *Qsaji, QueueDD *Qpesanan);
// I.S. Qsaji dan Qpesanan terdefinisi 
// F.S. Elemen pada Qsaji tidak ada yang memiliki ketahanan 0

void validasiCommandCook(QueueDD Qpesanan, QueueDD Qsaji, int processID, boolean *isValid);
// I.S. Qpesanan, Qsaji, processID, dan boolean isValid terdefinisi 
// F.S. Mengubah nilai boolean isValid menjadi true jika processID terdapat di Qpesanan. Jika tidak, akan diberi pesan eror.

void validasiCommandServe(QueueDD Qpesanan, QueueDD Qmasak, QueueDD Qsaji, int processID, boolean *isValid);
// I.S. Qpesanan, Qmasak, Qsaji, processID, dan boolean isValid terdefinisi 
// F.S. Mengubah nilai boolean isValid menjadi true jika processID terdapat di Qsaji dan processID merupakan head ID makanan dari Qpesanan. Jika tidak, akan diberi pesan eror.

void addPesanan(QueueDD *Qpesanan, int *IDpesanan);
// I.S. Qpesanan dan IDPesanan terdefinisi
// F.S. Menambahkan elemen ke Qpesanan 

void dinerDash();
// Program utama diner-dash

#endif