#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
#include "diner-dash.h"
#include "tictactoe.h"
#include "snakeOnMeteor.h"

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

void LOADBNMO(ArrayDin *GameBNMO, char* filename, ArrayDin *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe)
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
        printf("File konfigurasi sistem tidak ditemukan.\n");
    }
    else
    {
        fclose(fpita);
        StartWord(temp2);
        ngame = wordtoInt(CurrentWord);
        ADVWord();
        for (int j = 0; j < ngame; j++)
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

        /*--- RNG ---*/
        nsbrng = wordtoInt(CurrentWord);
        printf("%d\n", nsbrng);
        for (int j = 0; j < nsbrng; j++)
        {
            ADVName();
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            ADVName();
            int x = wordtoInt(CurrentWord);
            InsertMap(MapRNG, temp, x); 
        }

        /*--- Hangman ---*/
        nsbhangman = wordtoInt(CurrentWord);
        printf("%d\n", nsbhangman);
        for (int j = 0; j < nsbhangman; j++)
        {
            ADVName();
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            ADVName();
            int x = wordtoInt(CurrentWord);
            InsertMap(MapHangman, temp, x); 
        }

        /*--- DD ---*/
        nsbdd = wordtoInt(CurrentWord);
        printf("%d\n", nsbdd);
        for (int j = 0; j < nsbdd; j++)
        {
            ADVName();
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            ADVName();
            int x = wordtoInt(CurrentWord);
            InsertMap(MapDD, temp, x); 
        }

        /*--- Tower of Hanoi ---*/
        nsbtoh = wordtoInt(CurrentWord);
        printf("%d\n", nsbtoh);
        for (int j = 0; j < nsbtoh; j++)
        {
            ADVName();
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            ADVName();
            int x = wordtoInt(CurrentWord);
            InsertMap(MapTower, temp, x); 
        }

        /*--- Snake ---*/
        nsbsom = wordtoInt(CurrentWord);
        printf("%d\n", nsbsom);
        for (int j = 0; j < nsbsom; j++)
        {
            ADVName();
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            ADVName();
            int x = wordtoInt(CurrentWord);
            InsertMap(MapSnake, temp, x); 
        }

        //TicTacToe
        nsbttt = wordtoInt(CurrentWord);
        printf("%d\n", nsbttt);
        for (int j = 0; j < nsbttt; j++)
        {
            ADVName();
            wordtoString(CurrentWord, string);
            temp = (char *) malloc (CurrentWord.Length * sizeof(char));
            i = 0;
            while (i <= CurrentWord.Length)
            {
                temp[i] = string[i];
                
                i += 1;
            }
            ADVName();
            int x = wordtoInt(CurrentWord);
            InsertMap(MapTicTacToe, temp, x);
            
        }
        
       printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", filename);
    }
    
}

void SAVEBNMO(ArrayDin *GameBNMO, char* filename, ArrayDin *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe)
{
    char temp[50];
    printf("\n");
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

    fprintf(fpita, "\n%d", HistoryBNMO->Neff);
    i=0;
    while (i < (*HistoryBNMO).Neff)
    {
        fprintf(fpita, "\n%s",(*HistoryBNMO).A[i]);
        i++;
    }

    fprintf(fpita, "\n%d", MapRNG->Count);
    i=0;
    while (i < (*MapRNG).Count)
    {
        fprintf(fpita, "\n%s %d",(*MapRNG).Elements[i].Key, (*MapRNG).Elements[i].Value);
        i++;
    }

    fprintf(fpita, "\n%d", MapDD->Count);
    i=0;
    while (i < (*MapDD).Count)
    {
        fprintf(fpita, "\n%s %d",(*MapDD).Elements[i].Key, (*MapDD).Elements[i].Value);
        i++;
    }


    fprintf(fpita, "\n%d", MapHangman->Count);
    i=0;
    while (i < (*MapHangman).Count)
    {
        fprintf(fpita, "\n%s %d",(*MapHangman).Elements[i].Key, (*MapHangman).Elements[i].Value);
        i++;
    }

    fprintf(fpita, "\n%d", MapTower->Count);
    i=0;
    while (i < (*MapTower).Count)
    {
        fprintf(fpita, "\n%s %d",(*MapTower).Elements[i].Key, (*MapTower).Elements[i].Value);
        i++;
    }

    fprintf(fpita, "\n%d", MapSnake->Count);
    i=0;
    while (i < (*MapSnake).Count)
    {
        fprintf(fpita, "\n%s %d",(*MapSnake).Elements[i].Key, (*MapSnake).Elements[i].Value);
        i++;
    }

    fprintf(fpita, "\n%d", MapTicTacToe->Count);
    i=0;
    while (i < (*MapTicTacToe).Count)
    {
        fprintf(fpita, "\n%s %d",(*MapTicTacToe).Elements[i].Key, (*MapTicTacToe).Elements[i].Value);
        i++;
    }

    printf("%s file berhasil disimpan.\n", filename);        

    fclose(fpita);   

}

void CREATEGAME (ArrayDin *GameBNMO) 
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    char *namaGame;
    char *temp;
    int i;
    namaGame = (char *) malloc (50 * sizeof(char));
    StartGame();
    wordtoString(CurrentCommand, namaGame);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    i = 0;
    while (i <= CurrentCommand.Length)
    {
        temp[i] = namaGame[i];
        
        i += 1;
    }
    if (IsMemberArray(*GameBNMO, temp))
    {
        printf("Game sudah ada di dalam sistem. Silahkan masukkan nama game yang valid.\n");
    }
    else
    {
        InsertLast(GameBNMO, namaGame);
        printf("Game berhasil ditambahkan.\n");
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

void PLAYGAME(Queue *QueueBNMO, ArrayDin *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe)
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
            dinerDash(MapDD);
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "HANGMAN"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            //HANGMAN();   
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);                
        }

        else if (compareString((*QueueBNMO).buffer[0], "TOWER OF HANOI"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            //TOH();
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        else if (compareString((*QueueBNMO).buffer[0], "SNAKE ON METEOR"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            snake(MapSnake);
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        //BONUS
        else if (compareString((*QueueBNMO).buffer[0], "TICTACTOE"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            tictactoe(MapTicTacToe);
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                           
        }
        else
        {
            srand(time(NULL));
            int r = rand()%1000;
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            printf("%d", r);
            InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);
             
        }
        dequeue(QueueBNMO, &val);  
    }
    printf("\n");
      
}

void SKIPGAME(Queue *QueueBNMO, int n, ArrayDin *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe)
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
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                            
            }
            else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                dinerDash(MapDD);
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                            
            }
            else if (compareString((*QueueBNMO).buffer[0], "HANGMAN"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                //HANGMAN();   
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);                
            }

            else if (compareString((*QueueBNMO).buffer[0], "TOWER OF HANOI"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                //TOH();
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
            }

            else if (compareString((*QueueBNMO).buffer[0], "SNAKE ON METEOR"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                snake(MapSnake);
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]);  
            }

            //BONUS
            else if (compareString((*QueueBNMO).buffer[0], "TICTACTOE"))
            {
                printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
                printf("\n");
                tictactoe(MapTicTacToe);
                InsertFirst(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                            
            }
            else
            {
                srand(time(NULL));
                int r = rand()%1000;
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
    if (IsEmpty(*HistoryBNMO))
    {
        printf("Belum ada game yang dimainkan. History Kosong.\n");
    }
    else
    {
        printf("Berikut adalah daftar Game yang telah dimainkan : \n");
        if (n <= Length(*HistoryBNMO))
        {
            int i = 0;
            while (i < n)
            {
                printf("%d. %s\n", (i+1), (*HistoryBNMO).A[i]);
                
                i++;
            }
        }
        else
        {
            int i = 0;
            while (i < Length(*HistoryBNMO))
            {
                printf("%d. %s\n", (i+1), (*HistoryBNMO).A[i]);
                i++;
            }
        }

    }
    
}

void SCOREBOARD(Map MapRNG, Map MapDD, Map MapHangman, Map MapTower, Map MapSnake, Map MapTicTacToe)
{
    //-----------------RNG-----------------
    printf("**** SCOREBOARD GAME RNG ****\n");
    PrintMap(MapRNG);
    printf("\n");

    //-----------------Diner Dash-----------------
    printf("**** SCOREBOARD GAME Diner Dash ****\n");
    PrintMap(MapDD);
    printf("\n");

    //-----------------Hangman-----------------
    printf("**** SCOREBOARD GAME Hangman ****\n");
    PrintMap(MapHangman);
    printf("\n");

    //-----------------Tower of Hanoi-----------------
    printf("**** SCOREBOARD GAME Tower of Hanoi ****\n");
    PrintMap(MapTower);
    printf("\n");

    //-----------------Snake on Meteor-----------------
    printf("**** SCOREBOARD GAME Snake on Meteor ****\n");
    PrintMap(MapSnake);
    printf("\n");

    //-----------------Tic Tac Toe-----------------
    printf("**** SCOREBOARD GAME TICTACTOE ****\n");
    PrintMap(MapTicTacToe);
    printf("\n");

}

void RESETSCOREBOARD(Map *MapRNG , Map *MapDD , Map *MapHangman , Map *MapTower , Map *MapSnake , Map *MapTicTacToe)
{
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    printf("1. RNG\n");
    printf("2. Diner DASH\n");
    printf("3. HANGMAN\n");
    printf("4. TOWER OF HANOI\n");
    printf("5. SNAKE ON METEOR\n");
    printf("6. TICTACTOE\n");

    printf("\n");
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    StartCommand();
    int inp = wordtoInt(CurrentCommand);
    ADVCommand();
    
    if(inp>=0 && inp <= 6)
    {
        if (inp == 0)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD ALL...\n");
                printf("\n");
                CreateEmptyMap(MapRNG);
                CreateEmptyMap(MapDD);
                CreateEmptyMap(MapHangman);
                CreateEmptyMap(MapTower);
                CreateEmptyMap(MapSnake);
                CreateEmptyMap(MapTicTacToe);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD ALL DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }

        if(inp ==1)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD RNG (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD RNG...\n");
                printf("\n");
                CreateEmptyMap(MapRNG);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD RNG DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }

        if(inp ==2)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD Diner Dash (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD Diner Dash...\n");
                printf("\n");
                CreateEmptyMap(MapDD);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD Diner Dash DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }

        if(inp ==3)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD Hangman (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD Hangman...\n");
                printf("\n");
                CreateEmptyMap(MapHangman);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD Hangman DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }

        if(inp ==4)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD Tower of Hanoi (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD Tower of Hanoi...\n");
                printf("\n");
                CreateEmptyMap(MapTower);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD Tower of Hanoi DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }

        if(inp ==5)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD Snake on Meteor (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD Snake on Meteor...\n");
                printf("\n");
                CreateEmptyMap(MapSnake);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD Snake on Meteor DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }

        if(inp ==6)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD Tic Tac Toe (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD Tic Tac Toe...\n");
                printf("\n");
                CreateEmptyMap(MapTicTacToe);
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD Tic Tac Toe DIBATALKAN\n");
            }
            else
            {
                printf("INPUT TIDAK VALID\n");
            }
        }
    }
    else
    {
        printf("INPUT TIDAK VALID\n");
    }

}


void RESETHISTORY(ArrayDin *HistoryBNMO)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
    StartCommand();
    if (compareWord(CurrentCommand, "YA") == true)
    {
        (*HistoryBNMO) = MakeArrayDin();
        printf("History berhasil di-reset\n"); 
    }
    else if (compareWord(CurrentCommand, "TIDAK") == true)
    {
        printf("History tidak jadi di-reset.\n");
        HISTORY(HistoryBNMO, Length(*HistoryBNMO));
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

