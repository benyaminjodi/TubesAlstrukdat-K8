#include<stdio.h>
#include "mesinkata.h"

boolean EndWord;
Kata CurrentWord;
Kata CurrentCommand;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK || CC == ENTER){
        ADV();
    }
}

void STARTWORD()
/* I.S. : CC sembarang 
   F.S. : EndWord = true, dan CC = MARK; 
          atau EndWord = false, CurrentWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
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


/* *** ADT untuk baca commands *** */

void IgnoreDot()
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */
{
    while ((CC == BLANK) && (CC == '.')) {
        ADVC();
    }
}

void STARTCOMMAND()
/* I.S. : CC sembarang 
   F.S. : EndWord = true, dan CC = ENTER; 
          atau EndWord = false, CurrentCommand adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    COMMAND();
    IgnoreDot();
    if (CC == ENTER){
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CurrentCommand adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, EndWord = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinCommand */
{
    IgnoreDot();
    if (CC == ENTER && !EndWord){
        EndWord = true;
    } else{
        SalinCommand();
        IgnoreDot();
    }
}

void SalinCommand()
/* Mengakuisisi kata, menyimpan dalam CurrentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CurrentCommand berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = ENTER; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != BLANK) && (CC != ENTER) && i != NMax) {
        CurrentCommand.TabKata[i] = CC;
        ADVC();
        i += 1;
    }
    
    if (i < NMax)
    {
        CurrentCommand.Length = i;
    }
    else
    {
        CurrentCommand.Length = NMax;
    }
}


