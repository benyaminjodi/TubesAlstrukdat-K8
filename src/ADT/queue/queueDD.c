#include <stdio.h>
#include "queueDD.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong */
{
  return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
{
  return IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY-1;
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
  if (isEmpty(q)) {
    return 0;
  } else {
    return IDX_TAIL(q) - IDX_HEAD(q) + 1;
  }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur". */
{
  if (!isFull(*q)) {
    if (isEmpty(*q)) {
      IDX_HEAD(*q) = 0;
      IDX_TAIL(*q) = 0;
    } else {
      IDX_TAIL(*q)++;
    }
    TAIL_ID(*q) = val.id;
    TAIL_DURASI(*q) = val.durasiMasak;
    TAIL_KETAHANAN(*q) = val.ketahanan;
    TAIL_HARGA(*q) = val.harga;

  }
}

void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., setiap elemen melakukan pergeseran ke kiri; q mungkin kosong */
{
  if (!isEmpty(*q)) {
    (*val).id = HEAD_ID(*q);
    (*val).durasiMasak = HEAD_DURASI(*q);
    (*val).ketahanan = HEAD_KETAHANAN(*q);
    (*val).harga = HEAD_HARGA(*q);
    if (length(*q) == 1) {
      IDX_HEAD(*q) = IDX_UNDEF;
      IDX_TAIL(*q) = IDX_UNDEF;
    } else {
      IDX_TAIL(*q)--;
      for (int i = 0; i < length(*q); i++) {
        (*q).buffer[i] = (*q).buffer[i+1];
      }
    }
  }
}
