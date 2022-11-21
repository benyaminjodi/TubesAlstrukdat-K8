#include <stdio.h>
#include "map.h"
#include "../../console.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
   return M.Count == Nil;
}

boolean IsFullMap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
   return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int i=0;
    int loc;
    boolean found = false;
    while (i < M.Count && !found)
    {
        if (compareString(M.Elements[i].Key, k)== true)
        {
            found = true;
            loc = i;
        }
        i++;
    }
    if (found)
    {
        return M.Elements[loc].Value;
    }
    else 
    {
        return Undefined;
    }
}

void InsertMap(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsEmptyMap(*M))
    {
        M->Elements[0].Key = k;
        M->Elements[0].Value = v;
        M->Count++;
    }
    else
    {
        int i = 0;
        boolean found = false;
        while (i < M->Count && !found)
        {
            if (M->Elements[i].Key == k)
            {
                found = true;
            }
            i++;
        }
        if (!found)
        {
            int i,j;
            i=0;
            while (v < M->Elements[i].Value)
            {
                i++;
            }
            for(j=i;j<M->Count;j++)
            {
                M->Elements[j+1].Key = M->Elements[j].Key;
                M->Elements[j+1].Value = M->Elements[j].Value;
            }
            M->Elements[i].Key = k;
            M->Elements[i].Value = v;
            M->Count++;
        }
    }
}
void DeleteMap(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    int i = 0;
    int loc;
    boolean found = false;
    while (i < M->Count && !found)
    {
        if (M->Elements[i].Key == k)
        {
            found = true;
            loc = i;
        }
        i++;
    }
    if (found)
    {
        int j;
        for (j=loc; j <M->Count-1;j++)
        {
            M->Elements[j]= M->Elements[j+1];
        }
        M->Count--;

    }
}


boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int i = 0;
        boolean found = false;
        while (i < M.Count && !found)
        {
            if (M.Elements[i].Key == k)
            {
                found = true;
            }
            i++;
        }
    return found;
}

void PrintMap(Map M)
/* I.S. M terdefinisi */
/* F.S. M dicetak ke layar */
{
    int longestname = LongestString(M);
    if (longestname == 0)
    {
        printf("| %-10s | %-10s |\n", "NAMA", "SCORE");
        printf("---- SCOREBOARD KOSONG ----\n");
    }
    else
    {
        printf("| NAMA");
        for (int i = 0; i < longestname + 2 ; i++)
        {
            printf(" ");
        }
        printf(" | %-10s |\n", "SCORE");
        for (int i = 0; i < longestname + 23; i++)
        {
            printf("-");
        }
        printf("\n");
        for (int i = 0; i < M.Count; i++)
        {
            printf("| %s", M.Elements[i].Key);
            for (int j = 0; j < longestname - (stringlen(M.Elements[i].Key) - 6); j++)
            {
                printf(" ");
            }
            printf(" | %-10d |\n", M.Elements[i].Value);
        }
    }
}

int LongestString(Map M)
/* Mengembalikan panjang string terpanjang pada Key M */
/* I.S. M tidak kosong */
/* F.S. k adalah key dengan string terpanjang pada M */
{
    int n = 0;
    int i = 0;
    while(i < M.Count){
        if (stringlen(M.Elements[i].Key) > n){
            n = stringlen(M.Elements[i].Key);
        }
        i++;
    }
    return n;
}
int stringlen(char *s)
/* Mengembalikan panjang string s */
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}


