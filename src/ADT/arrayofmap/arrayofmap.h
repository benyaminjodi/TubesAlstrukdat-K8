#include "../../boolean.h"
#include "../map/map.h"

#ifndef ARRAY_OF_MAP_H
#define ARRAY_OF_MAP_H

/* Kamus Umum */

#define IdxMax 99
#define IdxMin 0
#define IdxUndefArrayOfMap -999 

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeArrayOfMap;
typedef Map ElTypeArrayOfMap;

typedef struct
{
    Map AMap[IdxMax - IdxMin + 1]; 
    int NeffArrayOfMap;                               
} ArrayMap;

/* ********** KONSTRUKTOR ********** */
void MakeEmptyArrayOfMap(ArrayMap *A);
/* I.S. sembarang */
/* F.S. Terbentuk ArrayMap kosong dengan kapasitas IdxMax - IdxMin + 1 */

/* ********** SELEKTOR ********** */
int NbElmtArrayOfMap(ArrayMap A);
/* Mengirimkan banyaknya elemen efektif ArrayMap */
/* Mengirimkan nol jika ArrayMap kosong */

int MaxNbElArrayOfMap(ArrayMap A);
/* Mengirimkan maksimum elemen ArrayMap */

IdxTypeArrayOfMap GetFirstIdxArrayOfMap(ArrayMap A);
/* Prekondisi : ArrayMap tidak kosong */
/* Mengirimkan indeks elemen ArrayMap pertama */

IdxTypeArrayOfMap GetLastIdxArrayOfMap(ArrayMap A);
/* Prekondisi : ArrayMap tidak kosong */
/* Mengirimkan indeks elemen ArrayMap terakhir */


ElTypeArrayOfMap GetElmtArrayOfMap(ArrayMap A, IdxTypeArrayOfMap i);
/* Prekondisi : ArrayMap tidak kosong, i antara FirstIdxArrayOfMap(A)..LastIdxArrayOfMap(A) */
/* Mengirimkan elemen ArrayMap yang ke-i */


void CopyArrayOfMap(ArrayMap Ain, ArrayMap *Aout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */

/* Assignment THsl -> Tin */
void SetElArrayOfMap(ArrayMap *A, IdxTypeArrayOfMap i, ElTypeArrayOfMap M);
/* I.S. A terdefinisi, sembarang */
/* F.S. Elemen A yang ke-i bernilai v */

/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai M */
void SetNeffArrayOfMap(ArrayMap *A, IdxTypeArrayOfMap N);
/* I.S. A terdefinisi, sembarang */
/* F.S. Nilai elemen efektif A bernilai N */

boolean IsIdxValidArrayOfMap(ArrayMap A, IdxTypeArrayOfMap i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran ArrayMap */

boolean IsIdxEffArrayOfMap(ArrayMap A, IdxTypeArrayOfMap i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk ArrayMap */

boolean IsEmptyArrayOfMap(ArrayMap A);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

boolean IsFullArrayOfMap(ArrayMap A);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertFirstArrayMap(ArrayMap *A, ElTypeArrayOfMap M);
/* I.S. A mungkin kosong */
/* F.S. M menjadi elemen pertama A, jika A belum penuh; A tetap jika A penuh. */

void InsertAtArrayMap(ArrayMap *A, ElTypeArrayOfMap M, IdxTypeArrayOfMap i);
/* I.S. A tidak kosong, i adalah indeks yang valid */
/* F.S. M menjadi elemen ke-i A, jika A belum penuh; A tetap jika A penuh. */

void InsertLastArrayMap(ArrayMap *A, ElTypeArrayOfMap M);
/* I.S. A mungkin kosong */
/* F.S. M menjadi elemen terakhir A, jika A belum penuh; A tetap jika A penuh. */

void DeleteFirstArrayMap(ArrayMap *A);
/* I.S. A tidak kosong */
/* F.S. Elemen pertama A dihapus: nilai info disimpan pada X */

void DeleteAtArrayMap(ArrayMap *A, IdxTypeArrayOfMap i);
/* I.S. A tidak kosong, i adalah indeks yang valid */
/* F.S. Elemen ke-i A dihapus: nilai info disimpan pada X */

void DeleteLastArrayMap(ArrayMap *A);
/* I.S. A tidak kosong */
/* F.S. Elemen terakhir A dihapus: nilai info disimpan pada X */


#endif