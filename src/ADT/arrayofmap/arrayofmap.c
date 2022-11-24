#include <stdio.h>
#include "arrayofmap.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
void MakeEmptyArrayOfMap(ArrayMap *A)
/* I.S. sembarang */
/* F.S. Terbentuk ArrayMap kosong dengan kapasitas IdxMax - IdxMin + 1 */
{
    (*A).NeffArrayOfMap = 0;
}

/* ********** SELEKTOR ********** */
int NbElmtArrayOfMap(ArrayMap A)
/* Mengirimkan banyaknya elemen efektif ArrayMap */
/* Mengirimkan nol jika ArrayMap kosong */
{
    return A.NeffArrayOfMap;
}

int MaxNbElArrayOfMap(ArrayMap A)
/* Mengirimkan maksimum elemen ArrayMap */
{
    return IdxMax - IdxMin + 1;
}

void DeleteLastArrayMap(ArrayMap *A)
/* I.S. A tidak kosong */
/* F.S. Elemen terakhir A dihapus: nilai info disimpan pada X */
{
    if (NbElmtArrayOfMap(*A) > 0)
    {
        (*A).NeffArrayOfMap--;
    }
}


IdxTypeArrayOfMap GetFirstIdxArrayOfMap(ArrayMap A)
/* Prekondisi : ArrayMap tidak kosong */
/* Mengirimkan indeks elemen ArrayMap pertama */
{
    return IdxMin;
}

IdxTypeArrayOfMap GetLastIdxArrayOfMap(ArrayMap A)
/* Prekondisi : ArrayMap tidak kosong */
/* Mengirimkan indeks elemen ArrayMap terakhir */
{
    return IdxMin + NbElmtArrayOfMap(A) - 1;
}


ElTypeArrayOfMap GetElmtArrayOfMap(ArrayMap A, IdxTypeArrayOfMap i)
/* Prekondisi : ArrayMap tidak kosong, i antara FirstIdxArrayOfMap(A)..LastIdxArrayOfMap(A) */
/* Mengirimkan elemen ArrayMap yang ke-i */
{
    return A.AMap[i - 1];
}

void CopyArrayOfMap(ArrayMap Ain, ArrayMap *Aout)
/* I.S. Ain terdefinisi, sembarang */
/* F.S. Aout berisi salinan Ain */
{
    MakeEmptyArrayOfMap(Aout);
    int i;
    for (i = 1; i <= NbElmtArrayOfMap(Ain); i++)
    {
        InsertLastArrayMap(Aout, GetElmtArrayOfMap(Ain, i));
    }
}

/* Assignment AHsl -> Ain */
void SetElArrayOfMap(ArrayMap *A, IdxTypeArrayOfMap i, ElTypeArrayOfMap M)
/* I.S. A terdefinisi, sembarang */
/* F.S. Elemen A yang ke-i bernilai v */
{
    (*A).AMap[i - 1] = M;
    (*A).NeffArrayOfMap++;
    
}

/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai M */
void SetNeffArrayOfMap(ArrayMap *A, IdxTypeArrayOfMap N)
/* I.S. A terdefinisi, sembarang */
/* F.S. Nilai elemen efektif A bernilai N */
{
    (*A).NeffArrayOfMap = N;
}
boolean IsIdxValidArrayOfMap(ArrayMap A, IdxTypeArrayOfMap i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran ArrayMap */
{
    return (i >= IdxMin && i <= MaxNbElArrayOfMap(A));
}

boolean IsIdxEffArrayOfMap(ArrayMap A, IdxTypeArrayOfMap i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk ArrayMap */
{
    return (i >= IdxMin && i <= NbElmtArrayOfMap(A));
}

boolean IsEmptyArrayOfMap(ArrayMap A)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NbElmtArrayOfMap(A) == 0);
}

boolean IsFullArrayOfMap(ArrayMap A)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmtArrayOfMap(A) == MaxNbElArrayOfMap(A));
}

void InsertFirstArrayMap(ArrayMap *A, ElTypeArrayOfMap M)
/* I.S. A mungkin kosong */
/* F.S. M menjadi elemen pertama A, jika A belum penuh A tetap jika A penuh. */
{
    if (NbElmtArrayOfMap(*A) < MaxNbElArrayOfMap(*A))
    {
        int i;
        for (i = NbElmtArrayOfMap(*A); i >= 1; i--)
        {
            (*A).AMap[i] = (*A).AMap[i - 1];
        }
        (*A).AMap[0] = M;
        (*A).NeffArrayOfMap++;
    }
}

void InsertAtArrayMap(ArrayMap *A, ElTypeArrayOfMap M, IdxTypeArrayOfMap i)
/* I.S. A tidak kosong, i adalah indeks yang valid */
/* F.S. M menjadi elemen ke-i A, jika A belum penuh A tetap jika A penuh. */
{
    if (NbElmtArrayOfMap(*A) < MaxNbElArrayOfMap(*A))
    {
        int j;
        for (j = NbElmtArrayOfMap(*A); j >= i; j--)
        {
            (*A).AMap[j] = (*A).AMap[j - 1];
        }
        (*A).AMap[i - 1] = M;
        (*A).NeffArrayOfMap++;
    }
}

void InsertLastArrayMap(ArrayMap *A, ElTypeArrayOfMap M)
/* I.S. A mungkin kosong */
/* F.S. M menjadi elemen terakhir A, jika A belum penuh A tetap jika A penuh. */
{
    if (NbElmtArrayOfMap(*A) < MaxNbElArrayOfMap(*A))
    {
        (*A).AMap[NbElmtArrayOfMap(*A)] = M;
        (*A).NeffArrayOfMap++;
    }
}

void DeleteFirstArrayMap(ArrayMap *A)
/* I.S. A tidak kosong */
/* F.S. Elemen pertama A dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    if (NbElmtArrayOfMap(*A) > 0)
    {
        int i;
        for (i = 1; i < NbElmtArrayOfMap(*A); i++)
        {
            (*A).AMap[i - 1] = (*A).AMap[i];
        }
        (*A).NeffArrayOfMap--;
    }
}

void DeleteAtArrayMap(ArrayMap *A, IdxTypeArrayOfMap i)
/* I.S. A tidak kosong, i adalah indeks yang valid */
/* F.S. Elemen ke-i A dihapus: nilai info disimpan pada X */
/*      dan alamat elemen ke-i di-dealokasi */
{
    if (NbElmtArrayOfMap(*A) > 0)
    {
        int j;
        for (j = i; j < NbElmtArrayOfMap(*A); j++)
        {
            (*A).AMap[j - 1] = (*A).AMap[j];
        }
        (*A).NeffArrayOfMap--;
    }
}