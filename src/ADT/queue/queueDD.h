/* File : QueueDD.h */
/* Definisi ADT QueueDD dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QueueDDPESANAN_H
#define QueueDDPESANAN_H
#include "../../boolean.h"
#define IDX_UNDEF -1
#define CAPACITYDD 20

/* Definisi elemen dan address */
typedef struct {
        int id;
        int durasiMasak;
        int ketahanan;
        int harga;
} ElTypeDD;
typedef struct {
	ElTypeDD buffer[CAPACITYDD]; 
	int idxHead;
	int idxTail;
} QueueDD;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueDD, maka akses elemen : */
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
void CreateQueueDD(QueueDD *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDD(QueueDD q);
/* Mengirim true jika q kosong */
boolean isFullDD(QueueDD q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */

int lengthDD(QueueDD q);
/* Mengirimkan banyaknya elemen QueueDD. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueDD(QueueDD *q, ElTypeDD val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur". */

void dequeueDD(QueueDD *q, ElTypeDD *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., setiap elemen melakukan pergeseran ke kiri; q mungkin kosong */
        
#endif