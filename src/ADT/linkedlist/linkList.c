#include "linkList.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
    /* Mengirim true jika list kosong. Lihat definisi di atas. */

    return (First(L) == NIL) && (Last(L) == NIL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L) {
    /* I.S. L sembarang  */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */

    First(*L) = NIL;
    Last(*L) = NIL;
}

/****************** Manajemen Memori ******************/
addressNode Alokasi (int x, int y) {
    /* Mengirimkan addressNode hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka addressNode tidak nil. */
    /* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil. */

    addressNode P;

    P = (addressNode) malloc(sizeof(ElmtList));
    
    if (P != NIL) {
        InfoX(P) = x;
        InfoY(P) = y;
        Next(P) = NIL;
        Prev(P) = NIL;
    }
    else {
        P = NIL;
    }
    
    return P;
}

void Dealokasi (addressNode P) {
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian addressNode P */

    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressNode SearchList (List L, int x, int y) {
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan addressNode elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */

    addressNode P;
    boolean found;

    P = First(L);
    found = false;

    while ((P != NIL) && (!found)) {
        if (InfoX(P) == x && InfoY(P) == y) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }

    if (found) {
        return P;
    }
    else {
        return NIL;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, int x, int y) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

    addressNode P;

    P = Alokasi(x, y);

    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            Last(*L) = P;
        }
        else {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

void InsVLast (List *L, int x, int y) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    addressNode P;

    P = Alokasi(x, y);

    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            Last(*L) = P;
        }
        else {
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, int *x, int *y) {
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */

    addressNode P;

    P = First(*L);
    (*x) = InfoX(P);
    (*y) = InfoY(P);

    if (Next(P) == NIL) {
        First(*L) = NIL;
        Last(*L) = NIL;
    }
    else {
        First(*L) = Next(P);
        Prev(First(*L)) = NIL;
    }

    Dealokasi(P);
}

void DelVLast (List *L, int *x, int *y) {
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */

    addressNode P;

    P = Last(*L);
    (*x) = InfoX(P);
    (*y) = InfoY(P);

    if (Prev(P) == NIL) {
        First(*L) = NIL;
        Last(*L) = NIL;
    }
    else {
        Last(*L) = Prev(P);
        Next(Last(*L)) = NIL;
    }

    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressNode P) {
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-addressNode P sebagai elemen pertama */

    if (IsEmptyList(*L)) {
        First(*L) = P;
        Last(*L) = P;
    }
    else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLastList (List *L, addressNode P) {
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

    if (IsEmptyList(*L)) {
        First(*L) = P;
        Last(*L) = P;
    }
    else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

void InsertAfter (List *L, addressNode P, addressNode Prec) {
    /* I.S. Prec pastilah elemen list; P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

    if (Next(Prec) == NIL) {
        InsertLastList(L, P);
    }
    else {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
        Prev(P) = Prec;
    }
}

void InsertBefore (List *L, addressNode P, addressNode Succ) {
    /* I.S. Succ pastilah elemen list; P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

    if (Prev(Succ) == NIL) {
        InsertFirstList(L, P);
    }
    else {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
        Next(P) = Succ;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, addressNode *P) {
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */

    (*P) = First(*L);

    if (Next(First(*L)) == NIL) {
        First(*L) = NIL;
        Last(*L) = NIL;
    }
    else {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = NIL;
    }

    Next(*P) = NIL;
}

void DelLastList (List *L, addressNode *P) {
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

    (*P) = Last(*L);

    if (Prev(Last(*L)) == NIL) {
        First(*L) = NIL;
        Last(*L) = NIL;
    }
    else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = NIL;
    }

    Prev(*P) = NIL;
}

void DelP (List *L, infotypeNode X) {
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddressNode P, dengan Info(P)=X  */
    /* maka P dihapus dari list dan didealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */

    addressNode P;

    P = SearchList(*L, X.x, X.y);

    if (P != NIL) {
        if (P == First(*L)) {
            DelFirstList(L, &P);
        }
        else if (P == Last(*L)) {
            DelLastList(L, &P);
        }
        else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }

        Dealokasi(P);
    }
}

void DelAfter (List *L, addressNode *Pdel, addressNode Prec) {
    /* I.S. List tidak kosong. Prec adalah anggota list. */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */

    (*Pdel) = Next(Prec);

    if (Next(Prec) == Last(*L)) {
        Last(*L) = Prec;
        Next(Prec) = NIL;
    }
    else {
        Next(Prec) = Next(Next(Prec));
        Prev(Next(Prec)) = Prec;
    }

    Prev(*Pdel) = NIL;

    Dealokasi(*Pdel);
}

void DelBefore (List *L, addressNode *Pdel, addressNode Succ) {
    /* I.S. List tidak kosong. Succ adalah anggota list. */
    /* F.S. Menghapus Prev(Succ): */
    /*      Pdel adalah alamat elemen list yang dihapus  */

    (*Pdel) = Prev(Succ);

    if (Prev(Succ) == First(*L)) {
        First(*L) = Succ;
        Prev(Succ) = NIL;
    }
    else {
        Prev(Succ) = Prev(Prev(Succ));
        Next(Prev(Succ)) = Succ;
    }

    Next(*Pdel) = NIL;

    Dealokasi(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
    /* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

    addressNode P;

    printf("[");

    if (First(L) != NIL) {
        P = First(L);

        while (P != NIL) {
            printf("<%d, %d>", InfoX(P), InfoY(P));

            if (Next(P) != NIL) {
                printf(",");
            }

            P = Next(P);
        }
    }

    printf("]");
}

void PrintBackward (List L) {
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
    /* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
    /* Jika list kosong : menulis [] */

    addressNode P;

    printf("[");

    if (Last(L) != NIL) {
        P = Last(L);

        while (P != NIL) {
            printf("<%d, %d>", InfoX(P), InfoY(P));

            if (Prev(P) != NIL) {
                printf(",");
            }

            P = Prev(P);
        }
    }

    printf("]");
}