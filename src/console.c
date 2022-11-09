#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
#include "diner-dash.h"

//Fungsi dan Prosedur 
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

boolean compareString(char* kata1, char *kata2)
{
    boolean same = true;
    int i = 0;
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

int wordtoInt(Kata Word) 
{
    int i=0;
    int x = 0;

    while (i<Word.Length) 
    {
        x = (x*10) + (Word.TabWord[i] - '0');
        i++;;
    } 
    return x;
}

void concat(char *s1, char *s2, char *soutput)
{
    int i,j = 0;
    while (s1[i] != '\0') {
        soutput[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i] != '\0') {
        soutput[j] = s2[i];
        i++;
        j++;
    }
    soutput[j] = '\0';
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

// Command untuk Spesifikasi
void STARTBNMO(ArrayDin *GameBNMO)
{
    char string[50];
    char *temp;
    int i,x;
    StartWord("./data/config.txt");
    x = wordtoInt(CurrentWord);
    ADVWord();
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

void LOADBNMO(ArrayDin *GameBNMO, char *filename)
{
    char string[50];
    char *temp; 
    char temp2[50];
    int i,x;
    concat("./data/",filename, temp2);
    StartWord(temp2);
    x = wordtoInt(CurrentWord);
    ADVWord();
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
    printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", filename);
}

void SAVE(ArrayDin *GameBNMO, char *filename)
{
    char temp[50];
    concat("./data/", filename, temp);
    FILE *fpita;
    fpita = fopen(temp, "w");
    fprintf(fpita, "%d", GameBNMO->Neff);
    int i=0;
    while (i < (*GameBNMO).Neff)
    {
        fprintf(fpita, "\n%s",(*GameBNMO).A[i]);
        i++;
    }
    printf("%s file berhasil disimpan.\n", filename);        
    
    fclose(fpita);   

}

void CREATEGAME (ArrayDin *GameBNMO) 
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    char *namaGame;
    namaGame = (char *) malloc (50 * sizeof(char));
    StartGame();
    wordtoString(CurrentCommand, namaGame);
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

void DELETEGAME (ArrayDin *GameBNMO, Queue Q) 
{
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

void QUEUEGAME (Queue *QueueBNMO, ArrayDin GameBNMO) 
{
    printf("Berikut adalah daftar antrian game-mu");
    printf("\n");
    if (isEmpty(*QueueBNMO)) {
        printf("0. -\n");
    } else {
        int i;
        i =0;
        while (i< length(*QueueBNMO))
        {
            printf("%d. %s\n", (i+1), (*QueueBNMO).buffer[i]);
            i++;
        }
    }
    printf("\n");

    LISTGAME(GameBNMO);

    int x;
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    StartGame();
    x = wordtoInt(CurrentCommand);
    printf("\n");

    if (x>=1 && x<=Length(GameBNMO)) 
    {
        enqueue(QueueBNMO, GameBNMO.A[x-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");   
    } 
    else 
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}

void PLAYGAME(Queue *QueueBNMO)
{
    char game[50];
    ElType *val;

   if (isEmpty(*QueueBNMO))
   {
    printf("Tidak ada game dalam antrian\n");
   }
   else
   {
        printf("Berikut adalah daftar Game-mu : \n");
        int i= 0 ;
        while (i< length(*QueueBNMO))
        {
            printf("%d. %s\n", (i+1), (*QueueBNMO).buffer[i]);
            i++;
        }
        printf("\n");
        if (compareString((*QueueBNMO).buffer[0], "RNG"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            RNG(); 
                         
        }
        else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            dinerDash(); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "DINOSAUR IN EARTH"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan\n", (*QueueBNMO).buffer[0]);
            printf("Silahkan pilih game lain.");
            printf("\n");
                           
        }

        else if (compareString((*QueueBNMO).buffer[0], "RISEWOMAN"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan\n", (*QueueBNMO).buffer[0]);
            printf("Silahkan pilih game lain.");
            printf("\n");
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "EIFFEL TOWER"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan\n", (*QueueBNMO).buffer[0]);
            printf("Silahkan pilih game lain.");
            printf("\n");
                           
        }
        else
        {
            srand(time(NULL));
            int r = rand()%1000;
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            printf("%d", r);
             
        }
        dequeue(QueueBNMO, val);  
    }
    printf("\n");
      
}

void SKIPGAME(Queue *QueueBNMO, int n)
{
    ElType val;

    printf("Berikut adalah daftar Game-mu : \n");
        int i= 0 ;
        while (i< length(*QueueBNMO))
        {
            printf("%d. %s\n", (i+1), (*QueueBNMO).buffer[i]);
            i++;
        }
    printf("\n");

    if (n >= length(*QueueBNMO))
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu\n");
        CreateQueue(QueueBNMO);
    }
    else
    {
        int i;
        for (i=0;i<n; i++)
        {
            dequeue(QueueBNMO,&val);
        }    
          if (compareString((*QueueBNMO).buffer[0], "RNG"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            RNG(); 
                         
        }
        else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            dinerDash(); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "DINOSAUR IN EARTH"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan\n", (*QueueBNMO).buffer[0]);
            printf("Silahkan pilih game lain.");
            printf("\n");
                           
        }

        else if (compareString((*QueueBNMO).buffer[0], "RISEWOMAN"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan\n", (*QueueBNMO).buffer[0]);
            printf("Silahkan pilih game lain.");
            printf("\n");
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "EIFFEL TOWER"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan\n", (*QueueBNMO).buffer[0]);
            printf("Silahkan pilih game lain.");
            printf("\n");
                           
        }
        else
        {
            srand(time(NULL));
            int r = rand()%1000;
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            printf("%d", r);
             
        }
        dequeue(QueueBNMO,&val);     
    }
}

void RNG(){
    srand(time(NULL));
    int r = rand()%101;
    int masukan;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    StartCommand();
    masukan = wordtoInt(CurrentCommand);
    while (masukan != r){
        if (masukan < r){
            printf("Lebih besar\n");
        }
        else{
            printf("Lebih kecil\n");
        }
        printf("Tebakan: ");
        StartCommand();
        masukan = wordtoInt(CurrentCommand);
    }
    printf("Ya, X adalah ");
    printf("%d.", masukan);
}

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.");
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

