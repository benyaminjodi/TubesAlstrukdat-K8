#include<stdio.h>
#include <stdlib.h>
#include "console.h"


boolean compareWord(char *kata1, char *kata2)
{
    boolean same = true;
    while (*kata1 != '\0' && *kata2 != '\0')
    {
        if (*kata1 != *kata2)
        {
            same = false;
        }
        kata1++;
        kata2++;
    }
    return same;
}

int wordtoInt(Kata Word) {
    int i=0;
    int x = 0;

    while (i<Word.Length) 
    {
        x = (x*10) + (Word.TabWord[i] - '0');
        i++;;
    } 
    return x;
}

void wordtoString(Kata CurrentWord, char *string)
{
    int i = 0;

    for (i=0;i < CurrentWord.Length; i++ )
    {
        string[i] = CurrentWord.TabWord[i];
    }
    string[i] = '\0';
}

void STARTBNMO(ArrayDin *GameBNMO)
{
    char string[50];
    char *temp;
    int i,x;
    StartWord("./data/config.txt");
    x = wordtoInt(CurrentWord);
    //printf("%s\n", CurrentWord);
    ADVWord();
    //printf("%s\n", CurrentWord);
    for (int j = 0; j < x; j++)
    {
        wordtoString(CurrentWord, string);
        temp = (char *) malloc (CurrentWord.Length * sizeof(char));
        i = 0;
        while (i <= CurrentWord.Length)
        {
            temp[i] = string[i];
            
            i += 1;
        }
        InsertLast(GameBNMO, temp);
        ADVWord();
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LISTGAME (ArrayDin GameBNMO)
{
    int i;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i=0; i < GameBNMO.Neff; i++){
        printf("%d. %s\n", (1+i), GameBNMO.A[i]);
    }
}