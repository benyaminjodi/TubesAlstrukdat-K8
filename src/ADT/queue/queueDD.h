/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEPESANAN_H
#define QUEUEPESANAN_H
#include "boolean.h"
#define IDX_UNDEF -1
#define CAPACITY 20

/* Definisi elemen dan address */
typedef struct {
        int id;
        int durasiMasak;
        int ketahanan;
        int harga;
} ElType;
typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail

#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

#define HEAD_ID(q) (q).buffer[(q).idxHead].id
#define TAIL_ID(q) (q).buffer[(q).idxTail].id

#define HEAD_DURASI(q) (q).buffer[(q).idxHead].durasiMasak
#define TAIL_DURASI(q) (q).buffer[(q).idxTail].durasiMasak

#define HEAD_KETAHANAN(q) (q).buffer[(q).idxHead].ketahanan
#define TAIL_KETAHANAN(q) (q).buffer[(q).idxTail].ketahanan

#define HEAD_HARGA(q) (q).buffer[(q).idxHead].harga
#define TAIL_HARGA(q) (q).buffer[(q).idxTail].harga

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q);
/* Mengirim true jika q kosong */
boolean isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur". */

void dequeue(Queue *q, ElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., setiap elemen melakukan pergeseran ke kiri; q mungkin kosong */
        
#endif