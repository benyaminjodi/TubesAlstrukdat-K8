#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
#include "diner-dash.h"
#include "tictactoe.h"

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

void LOADBNMO(ArrayDin *GameBNMO, char *filename, ArrayDin *HistoryBNMO, Map *SBRNG, Map *SBHANGMAN, Map *SBDD, Map *SBToH, Map *SBSoM, Map *SBTTT)
{
    char string[50];
    char *temp; 
    char temp2[50];
    int i,ngame, nhistory, nsbrng, nsbhangman, nsbdd, nsbtoh, nsbsom, nsbttt;
    concat("./data/",filename, temp2);
    // printf("%s\n", temp2);
    FILE *fpita;
    fpita = fopen(temp2, "r");
    if (fpita == NULL)
    {
        printf("File sistem tidak ditemukan. Silahkan masukkan nama file yang valid\n");
    }
    else
    {
        //Game
        STARTWord(fpita);
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

        //History
        nhistory = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nhistory; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(HistoryBNMO, temp);
            ADVWord();
            
        }

        //SBRNG
        nsbrng = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nsbrng; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(SBRNG, temp);
            ADVWord();
            
        }

        //SBHANGMAN
        nsbhangman = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nsbhangman; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(SBHANGMAN, temp);
            ADVWord();
            
        }

        //SBDD  
        nsbdd = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nsbdd; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(SBDD, temp);
            ADVWord();
            
        }

        //SBToH
        nsbtoh = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nsbtoh; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(SBToH, temp);
            ADVWord();
            
        }

        //SBSoM
        nsbsom = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nsbsom; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(SBSoM, temp);
            ADVWord();
            
        }

        //SBTTT
        nsbttt = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < nsbttt; j++)
        {
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            InsertLast(SBTTT, temp);
            ADVWord();
            
        }

        printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", filename);
    }
       
}

void SAVEBNMO(ArrayDin *GameBNMO, char *filename, ArrayDin *HistoryBNMO, Map *SBRNG, Map *SBHANGMAN, Map *SBDD, Map *SBToH, Map *SBSoM, Map *SBTTT)
{
    char temp[50];
    printf("\n");
    concat("./data/", filename, temp);
    FILE *fpita;
    fpita = fopen(temp, "w");
    fprintf(fpita, "%d", GameBNMO->Neff);
    int i=0;
    //Game
    while (i < (*GameBNMO).Neff)
    {
        fprintf(fpita, "\n%s",(*GameBNMO).A[i]);
        i++;
    }

    //History
    i=0;
    while (i < (*HistoryBNMO).Neff)
    {
        fprintf(fpita, "\n%s",(*HistoryBNMO).A[i]);
        i++;
    }

    //SBRNG
    i=0;
    while (i< (*SBRNG).Neff)
    {
        fprintf(fpita, "\n%s",(*SBRNG).A[i]);
        i++;
    }

    //SBHANGMAN
    i=0;
    while (i< (*SBHANGMAN).Neff)
    {
        fprintf(fpita, "\n%s",(*SBHANGMAN).A[i]);
        i++;
    }

    //SBDD
    i=0;
    while (i< (*SBDD).Neff)
    {
        fprintf(fpita, "\n%s",(*SBDD).A[i]);
        i++;
    }

    //SBToH
    i=0;
    while (i< (*SBToH).Neff)
    {
        fprintf(fpita, "\n%s",(*SBToH).A[i]);
        i++;
    }   

    //SBSoM
    i=0;   
    while (i< (*SBSoM).Neff)
    {
        fprintf(fpita, "\n%s",(*SBSoM).A[i]);
        i++;
    }

    //SBTTT
    i=0;
    while (i< (*SBTTT).Neff)
    {
        fprintf(fpita, "\n%s",(*SBTTT).A[i]);
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
    if (!IsMember(*GameBNMO, namaGame))
    {
        InsertLast(GameBNMO, namaGame);
        printf("Game %s berhasil ditambahkan.\n", namaGame);
    }
    else
    {
        printf("Game %s sudah ada.\n", namaGame);
    }
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
    if ((x<=6 && x >=1) || x>(*GameBNMO).Neff) {
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

void PLAYGAME(Queue *QueueBNMO, ArrayDin *HistoryBNMO)
{
    char game[50];
    ElType val;

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
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);            
        }
        else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            dinerDash(); 
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);                
        }
        else if (compareString((*QueueBNMO).buffer[0], "HANGMAN"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            HANGMAN();   
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);                
        }

        else if (compareString((*QueueBNMO).buffer[0], "TOWER OF HANOI"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            TOH();
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        else if (compareString((*QueueBNMO).buffer[0], "SNAKE ON METEOR"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            SNAKE();
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        //BONUS
        else if (compareString((*QueueBNMO).buffer[0], "TICTACTOE"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            tictactoe(); 
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);   
        }
        else
        {
            srand(time(NULL));
            int r = rand()%10;
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            printf("%d", r);
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }
        dequeue(QueueBNMO, &val);  
    }
    printf("\n");
      
}

void SKIPGAME(Queue *QueueBNMO, int n, ArrayDin *HistoryBNMO)
{
    ElType val;
    if (n<1)
    {
        printf("Input yang diberikan tidak valid");
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

        if (n >= length(*QueueBNMO))
        {
            printf("Tidak ada permainan lagi dalam daftar game-mu\n");
            CreateQueue(QueueBNMO);
        }
        else
        {
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
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);            
            }
            else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                dinerDash(); 
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);                
            }
            else if (compareString((*QueueBNMO).buffer[0], "HANGMAN"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                HANGMAN();   
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);                
            }

            else if (compareString((*QueueBNMO).buffer[0], "TOWER OF HANOI"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                TOH();
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
            }

            else if (compareString((*QueueBNMO).buffer[0], "SNAKE ON METEOR"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                SNAKE();
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
            }

            //BONUS
            else if (compareString((*QueueBNMO).buffer[0], "TICTACTOE"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                tictactoe(); 
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);   
            }
            else
            {
                srand(time(NULL));
                int r = rand()%10;
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                printf("%d", r);
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
            }
            dequeue(QueueBNMO, &val);     
        }
    }
}

void HISTORY(ArrayDin *HistoryBNMO, int n)
{
    printf("Berikut adalah daftar Game yang telah dimainkan : \n");
    if (n <= length(*HistoryBNMO))
    {
        int i = 0;
        while (i < n)
        {
            printf("%d. %s\n", (i+1), (*HistoryBNMO).buffer[i]);
            i++;
        }
    }
    else
    {
        int i = 0;
        while (i < length(*HistoryBNMO))
        {
            printf("%d. %s\n", (i+1), (*HistoryBNMO).buffer[i]);
            i++;
        }
    }
}

void RESETHISTORY(ArrayDin *HistoryBNMO)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
    StartCommand();
    if (compareWord(CurrentCommand, "YA") == true)
    {
        CreateArrayDin(HistoryBNMO);
        printf("History berhasil di-reset\n"); 
    }
    else if (compareWord(CurrentCommand, "TIDAK") == true)
    {
        printf("History tidak jadi di-reset.\n");
        HISTORY();
    }
    else
    {
        printf("Input yang diberikan tidak valid\n");
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
    printf("CREATE GAME     : Command untuk menambahkan game ke dalam list game yang tersedia\n");
    printf("LIST GAME       : Command untuk menampilkan daftar game yang disediakan oleh sistem\n");
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

