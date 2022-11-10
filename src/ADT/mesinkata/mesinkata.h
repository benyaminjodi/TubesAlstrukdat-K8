/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"

#define NMax 100
#define BLANK ' '


typedef struct {
	char TabWord[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndWord;
extern Kata CurrentWord;
extern Kata CurrentCommand;


/* *** ADT untuk baca file eksternal *** */

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = ENTER */

void StartWord();
/* I.S. : CC sembarang 
   F.S. : endWord = true, dan CC = MARK; 
          atau endWord = false, CurrentWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWord();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CurrentWord adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = ENTER, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam CurrentWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CurrentWord berisi kata yang sudah diakuisisi; 
          CC = ENTER dan akhir dari file; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* *** ADT untuk baca commands *** */

void IgnoreBlankC();
/* Mengabaikan satu atau beberapa BLANK dan MARK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK */

void StartCommand();
/* I.S. : CC sembarang 
   F.S. : endWord = true, dan CC = ENTER; 
          atau endWord = false, CurrentCommand adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVCommand();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S  : CurrentCommand adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika CC = ENTER, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinCommand */

void CopyCommand();
/* Mengakuisisi kata, menyimpan dalam CurrentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CurrentCommand berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = ENTER dan i = Nmax; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void StartGame();
/* I.S. : CC sembarang 
   F.S. : endWord = true, dan CC = ENTER; 
          atau endWord = false, CurrentCommand adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void CopyGame();
/* Mengakuisisi kata, menyimpan dalam CurrentCommand
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CurrentCommand berisi kata yang sudah diakuisisi; 
          CC = ENTER dan i = Nmax; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
#endif