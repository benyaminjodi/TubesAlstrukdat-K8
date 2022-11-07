#include<stdio.h>
#include "mesinkata.h"

boolean endWord;
Kata CurrentWord;
Kata CurrentCommand;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == ' ' || CC == ENTER){
        ADV();
    }
}

void StartWord(char * filename)
/* I.S. : CC sembarang 
   F.S. : endWord = true, dan CC = MARK; 
          atau endWord = false, CurrentWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(filename);
    IgnoreBlank();
    if (CC != MARK)
    {
        endWord = false;
        CopyWord();
    }
    else
    {
        endWord = true;
    }
}


void ADVWord()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CurrentWord adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyWord */
{
    IgnoreBlank();
    if (CC == ENTER){
        endWord = true;
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
    while (CC != ENTER && !feof(pita)) {
        CurrentWord.TabWord[i] = CC;
        ADV();
        i++;
    }
    if (i <= NMax)
    {
        CurrentWord.Length = i;
    }
    else
    {
        CurrentWord.Length = NMax;
    }
    
}


/* *** ADT untuk baca commands *** */

void IgnoreBlankC()
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */
{
    while (CC == ' ')
    {
        ADVC();
    }
}

void StartCommand()
/* I.S. : CC sembarang 
   F.S. : endWord = true, dan CC = ENTER; 
          atau endWord = false, CurrentCommand adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    StartC();
    IgnoreBlankC();
    if (CC == ENTER){
        endWord = true;
    } else {
        endWord = false;
        CopyCommand();
    }
}

void ADVCommand()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S      . : CurrentCommand adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinCommand */
{
    IgnoreBlankC();
    if (CC == ENTER && !endWord){
        endWord = true;
    } else{
        CopyCommand();
        IgnoreBlankC();
    }
}

void CopyCommand()
/* Mengakuisisi kata, menyimpan dalam CurrentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CurrentCommand berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = ENTER; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((CC != ENTER) && i != NMax && (CC != BLANK))
    {
        CurrentCommand.TabWord[i] = CC;
        ADVC();
        i++;
    }
    if (i <= NMax)
    {
        CurrentCommand.Length = i;
    }
    else
    {
        CurrentCommand.Length = NMax;
    }
    
}
