#include <stdio.h>
#include "queueDD.h"

/* *** Kreator *** */
void CreateQueueDD(QueueDD *q)
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
boolean isEmptyDD(QueueDD q)
/* Mengirim true jika q kosong */
{
  return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFullDD(QueueDD q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
{
  return IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITYDD-1;
}

int lengthDD(QueueDD q)
/* Mengirimkan banyaknya elemen QueueDD. Mengirimkan 0 jika q kosong. */
{
  if (isEmptyDD(q)) {
    return 0;
  } else {
    return IDX_TAIL(q) - IDX_HEAD(q) + 1;
  }
}

/* *** Primitif Add/Delete *** */
void enqueueDD(QueueDD *q, ElTypeDD val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur". */
{
  if (!isFullDD(*q)) {
    if (isEmptyDD(*q)) {
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

void dequeueDD(QueueDD *q, ElTypeDD *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., setiap elemen melakukan pergeseran ke kiri; q mungkin kosong */
{
  if (!isEmptyDD(*q)) {
    (*val).id = HEAD_ID(*q);
    (*val).durasiMasak = HEAD_DURASI(*q);
    (*val).ketahanan = HEAD_KETAHANAN(*q);
    (*val).harga = HEAD_HARGA(*q);
    if (lengthDD(*q) == 1) {
      IDX_HEAD(*q) = IDX_UNDEF;
      IDX_TAIL(*q) = IDX_UNDEF;
    } else {
      IDX_TAIL(*q)--;
      for (int i = 0; i < lengthDD(*q); i++) {
        (*q).buffer[i] = (*q).buffer[i+1];
      }
    }
  }
}
