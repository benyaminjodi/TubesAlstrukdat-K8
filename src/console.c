#include<stdio.h>
#include <stdlib.h>
#include "console.h"


boolean compareWord(Kata kata1, char *kata2)
{
    boolean same = true;
    int i = 0;
    for (i=0 ; i<kata1.Length;i++)
    {
        if (kata1.TabWord[i] != *kata2)
        {
            same = false;
        }
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

void CREATEGAME (ArrayDin *GameBNMO) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    char *namaGame;
    namaGame = (char *) malloc (50 * sizeof(char));
    scanf("%s", namaGame);
    InsertLast(GameBNMO, namaGame);
    printf("Game berhasil ditambahkan\n");
}

void LISTGAME (ArrayDin GameBNMO)
{
    int i;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i=0; i < GameBNMO.Neff; i++){
        printf("%d. %s\n", (1+i), GameBNMO.A[i]);
    }
}

void DELETEGAME (ArrayDin *GameBNMO, Queue Q) {
    LISTGAME(*GameBNMO);
    printf("Masukkan nomor game yang akan dihapus: ");
    StartCommand();
    int x;
    x = wordtoInt(CurrentCommand);
    if ((x<=5 && x >=1) || x>(*GameBNMO).Neff) {
        printf("Game gagal dihapus\n");
    } else {
        boolean found = false;
        int j = 0 ;
        while (j<length(Q) && found == false) {
            if (Q.buffer[j]==(*GameBNMO).A[x-1]) {
                found = true;
            } j++;
        }
        if (found) {
            printf("Game gagal dihapus\n");
        } else {
            int i = x-1;
            while (i<(*GameBNMO).Neff) {
                (*GameBNMO).A[i] = (*GameBNMO).A[i+1];
                i++;  
            } 
            (*GameBNMO).Neff--;
            printf("Game berhasil dihapus\n");
        }
    }
    printf("\n");
}

void HELP() 
{
    printf("DAFTAR COMMAND \n");
    printf("\n");
    printf("START           : Command untuk memulai permainan BNMO dan menampilkan list game yang dapat dimainkan\n");
    printf("LOAD            : Command untuk membuka file yang berisi game yang dapat dimainkan dan histori bermain\n");
    printf("SAVE            : Command untuk menyimpan nama file yang akan disimpan di disk\n");
    printf("CREATE GAME     : Command untuk menampilkan daftar game yang disediakan oleh sistem\n");
    printf("DELETE GAME     : Command untuk menghapus sebuah game dari daftar game tanpa menghapus 5 game awal pada konfigurasi atau yang sedang diqueue\n");
    printf("QUEUE GAME      : Command untuk menambahkan permainan ke list game yang akan dimainkan\n");
    printf("PLAY GAME       : Command untuk memainkan game yang ada di list game yang akan dimainkan\n");
    printf("SKIPGAME        : Command untuk melewati permainan ke-n\n");
    printf("QUIT            : Command untuk keluar dari permainan\n");
    printf("HELP            : Command untuk menampilkan daftar-daftar command\n");
    
} 

void QUIT() {
    printf("Anda keluar dari game BNMO. \n");
    printf("Bye bye ... \n");
    exit(0);
}

