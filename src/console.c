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
    STARTWORD("./data/config.txt");
    x = wordtoInt(CurrentWord);
    ADVRow();
    for (int j = 0; j < x; j++)
    {
        wordtoString(CurrentWord, string);
        temp = (char *) malloc (CurrentWord.Length * sizeof(char));
        i = 0;
        while (i <= CurrentWord.Length)
        {
            temp[i] = string[i];
            i++;
        }
        InsertLast(GameBNMO, *temp);
        ADVWORD();
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}