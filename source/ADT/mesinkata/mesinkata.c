#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Kata CurrentWord;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK) && (CC != MARK)){
        ADV();
    }
}

void STARTWORD(char* filename)
/* I.S. : CC sembarang 
   F.S. : EndWord = true, dan CC = MARK; 
          atau EndWord = false, CurrentWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(filename);
    IgnoreBlank();
    if (CC != MARK){
        EndWord = false;
        ADVWORD();
    } else {
        EndWord = true;
    }
}

void ADVWORD()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CurrentWord adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyWord */
{
    IgnoreBlank();
    if (CC == MARK && !EndWord){
        EndWord = true;
    } else{
        CopyWord();
        IgnoreBlank();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam CurrentWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CurrentWord berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != MARK) && (CC != BLANK) && i != NMax) {
        CurrentWord.TabKata[i] = CC;
        ADV();
        i++;
    }
    if (i < NMax)
    {
        CurrentWord.Length = i;
    }
    else
    {
        CurrentWord.Length = NMax;
    }
    
}

