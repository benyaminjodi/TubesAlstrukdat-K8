#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
#include "diner-dash.h"
#include "tictactoe.h"
#include "snakeOnMeteor.h"
#include "hangman.h"
#include "chooseyouradv.h"

//Fungsi dan Prosedur 
boolean compareWord(Kata kata1, char *kata2)
{
    boolean same = true;
    if (kata1.Length != stringlen(kata2))
    {
        same = false;
    }
    else{   
        int i = 0;
        for (i=0 ; i<kata1.Length;i++)
        {
            if (kata1.TabWord[i] != *kata2)
            {
                same = false;
            }
            kata2++;
        }
    }
    return same;
}

boolean compareString(char *kata1, char *kata2)
{
    boolean same = true;
    int i,j;
    i = stringlen(kata1);
    j = stringlen(kata2);
    if (i != j)
    {
        same = false;
    }
    else
    {
        int k = 0;
        while (kata1[k] != '\0')
        {
            if (kata1[k] != kata2[k])
            {
                same = false;
            }
            k++;
        }
    }
    return same;
}

void Lowerstring(char *string)
{
    int i;
    for (i=0; i < stringlen(string); i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
    }
}

void Upperstring(char *string)
{
    int i;
    for (i=0; i < stringlen(string); i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }
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
void STARTBNMO(ArrayDin *GameBNMO, ArrayMap *ScoreBoard)
{
    char string[50];
    char *temp;
    int i,ngame;
    StartWord("./data/config.txt");
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

    int nmap;
    for (nmap=1; nmap <= ngame; nmap++)
    {
        Map Score;
        CreateEmptyMap(&Score);
        int n;
        n = wordtoInt(CurrentWord);            
        for (int j = 0; j < n; j++)
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
            InsertMap(&Score, temp, x);
        }
        ADVName();
        SetElArrayOfMap(ScoreBoard, nmap, Score);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LOADBNMO(ArrayDin *GameBNMO, char* filename, Stack *HistoryBNMO,ArrayMap *ScoreBoard)
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
            Push(HistoryBNMO, temp);
            ADVWord();   
        }
        (*HistoryBNMO) = ReverseStack(HistoryBNMO);
        /*--- Membaca Map Semua Game---*/
        int nmap;
        for (nmap=1; nmap <= ngame; nmap++)
        {
            Map Score;
            CreateEmptyMap(&Score);
            int n;
            n = wordtoInt(CurrentWord);            
            for (int j = 0; j < n; j++)
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
                InsertMap(&Score, temp, x);
            }
            ADVName();
            SetElArrayOfMap(ScoreBoard, nmap, Score);
        }
        
       printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", filename);
    }
    
}

void SAVEBNMO(ArrayDin *GameBNMO, char* filename, Stack *HistoryBNMO, ArrayMap *ScoreBoard)
{
    char temp[50];
    printf("\n");
    concat("./data/", filename, temp);
    
    FILE *fpita;
    fpita = fopen(temp, "w");
    /* --- Game --- */
    fprintf(fpita, "%d", GameBNMO->Neff);
    int i=0;
    while (i < (*GameBNMO).Neff)
    {
        fprintf(fpita, "\n%s",(*GameBNMO).A[i]);
        i++;
    }

    /* --- History --- */
    fprintf(fpita, "\n%d", Top(*HistoryBNMO)+1);
    i=0;
    while (i < Top(*HistoryBNMO)+1)
    {
        fprintf(fpita, "\n%s",(*HistoryBNMO).T[Top(*HistoryBNMO)-i]);
        i++;
    }


    /* --- Array Map --- */
    int j= 0;
    for (j=0; j < (*ScoreBoard).NeffArrayOfMap; j++)
    {
        fprintf(fpita, "\n%d", (*ScoreBoard).AMap[j].Count);
        i=0;
        while (i < (*ScoreBoard).AMap[j].Count)
        {
            fprintf(fpita, "\n%s", (*ScoreBoard).AMap[j].Elements[i].Key);
            fprintf(fpita, " %d", (*ScoreBoard).AMap[j].Elements[i].Value);
            i++;
        }
    }
    printf("%s file berhasil disimpan.\n", filename);        

    fclose(fpita);   

}

void CREATEGAME (ArrayDin *GameBNMO, ArrayMap *ScoreBoard) 
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
        Map Score;
        CreateEmptyMap(&Score);
        InsertLastArrayMap(ScoreBoard, Score);
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

void DELETEGAME (ArrayDin *GameBNMO, Queue Q, ArrayMap *ScoreBoard ) 
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
                (*ScoreBoard).AMap[i] = (*ScoreBoard).AMap[i+1];
                i++;  
            } 
            (*GameBNMO).Neff--;
            (*ScoreBoard).NeffArrayOfMap--;

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

void PLAYGAME(Queue *QueueBNMO, Stack *HistoryBNMO,ArrayMap *ScoreBoard, ArrayDin *GameBNMO)
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
            RNG(&(*ScoreBoard).AMap[0]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                         
        }
        else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            dinerDash(&(*ScoreBoard).AMap[1]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "HANGMAN"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            HANGMAN(&(*ScoreBoard).AMap[2]);   
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);                
        }

        else if (compareString((*QueueBNMO).buffer[0], "TOWER OF HANOI"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            //TOH();
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        else if (compareString((*QueueBNMO).buffer[0], "SNAKE ON METEOR"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            snake(&(*ScoreBoard).AMap[4]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        //BONUS
        else if (compareString((*QueueBNMO).buffer[0], "TICTACTOE"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            tictactoe(&(*ScoreBoard).AMap[5]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "CHOOSE YOUR ADV"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            chooseyouradv(&(*ScoreBoard).AMap[6]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }
        else
        {
            srand(time(NULL));
            int score = rand()%10;
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            printf("Skor anda adalah %d\n", score);
            int idx;
            for (idx=0; idx < (*GameBNMO).Neff; idx++){
                if (compareString((*GameBNMO).A[idx], (*QueueBNMO).buffer[0])){
                    break;
                }
            }
            char *temp;
            char player[50];
            printf("Player Name: ");
            StartGame();
            wordtoString(CurrentCommand, player);
            temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
            i = 0;
            while (i <= CurrentCommand.Length)
            {
                temp[i] = player[i];
                
                i += 1;
            }
            temp[i]='0';
            InsertMap(&(*ScoreBoard).AMap[idx], temp, score);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);
             
        }
        dequeue(QueueBNMO, &val);  
    }
    printf("\n");
      
}

void SKIPGAME(Queue *QueueBNMO, int n, Stack *HistoryBNMO,ArrayMap *ScoreBoard, ArrayDin *GameBNMO)
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
            RNG(&(*ScoreBoard).AMap[0]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                         
        }
        else if (compareString((*QueueBNMO).buffer[0], "Diner DASH"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            dinerDash(&(*ScoreBoard).AMap[1]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "HANGMAN"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            HANGMAN(&(*ScoreBoard).AMap[2]);   
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);                
        }

        else if (compareString((*QueueBNMO).buffer[0], "TOWER OF HANOI"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            //TOH();
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        else if (compareString((*QueueBNMO).buffer[0], "SNAKE ON METEOR"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            snake(&(*ScoreBoard).AMap[4]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }

        //BONUS
        else if (compareString((*QueueBNMO).buffer[0], "TICTACTOE"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            tictactoe(&(*ScoreBoard).AMap[5]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]); 
                           
        }
        else if (compareString((*QueueBNMO).buffer[0], "CHOOSE YOUR ADV"))
        {
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            chooseyouradv(&(*ScoreBoard).AMap[6]);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);  
        }
        else
        {
            srand(time(NULL));
            int score = rand()%10;
            printf("Loading %s ...\n", (*QueueBNMO).buffer[0]);
            printf("\n");
            printf("Skor anda adalah %d\n", score);
            int idx;
            for (idx=0; idx < (*GameBNMO).Neff; idx++){
                if (compareString((*GameBNMO).A[idx], (*QueueBNMO).buffer[0])){
                    break;
                }
            }
            char *temp;
            char player[50];
            printf("Player Name: ");
            StartGame();
            wordtoString(CurrentCommand, player);
            temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
            i = 0;
            while (i <= CurrentCommand.Length)
            {
                temp[i] = player[i];
                
                i += 1;
            }
            temp[i]= '\0';
            InsertMap(&(*ScoreBoard).AMap[idx], temp, score);
            Push(HistoryBNMO, (*QueueBNMO).buffer[0]);
             
        }
        dequeue(QueueBNMO, &val); 
        }
    }
}

void HISTORY(Stack HistoryBNMO, int n)
{
    if (IsEmptyStack(HistoryBNMO))
    {
        printf("Belum ada game yang dimainkan. History Kosong.\n");
    }
    else
    {
        printf("Berikut adalah daftar Game yang telah dimainkan : \n");
        if (n <= Top(HistoryBNMO)+1)
        {
    
            int i = 0;
            while (i < n)
            {
                printf("%d. %s\n", (i+1), InfoTop(HistoryBNMO));
                char* val;
                Pop(&HistoryBNMO, &val);
                i++;
            }
        }
        else if (n >Top(HistoryBNMO)+1)
        {
            int i = 0;
            int n;
            n = Top(HistoryBNMO);
            while (i <= n)
            {
                printf("%d. %s\n", (i+1), InfoTop(HistoryBNMO));
                char* val;
                Pop(&HistoryBNMO, &val);
                i++;
            }
        }
    }
    
}

void SCOREBOARD(ArrayMap ScoreBoard, ArrayDin GameBNMO)
{
    int i = 0;
    for (i = 0; i < GameBNMO.Neff; i++)
    {
        printf("*** SCOREBOARD GAME %s ***\n", (GameBNMO).A[i]);
        PrintMap((ScoreBoard).AMap[i]);
        printf("\n");
    }
    
}

void RESETSCOREBOARD(ArrayMap *ScoreBoard, ArrayDin *GameBNMO)
{
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    int k;
    for (int k = 0; k < (*GameBNMO).Neff; k++)
    {
        printf("%d. %s\n", (k+1), (*GameBNMO).A[k]);
    }

    printf("\n");
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    StartCommand();
    int inp = wordtoInt(CurrentCommand);
    ADVCommand();
 
    if(inp>=0 && inp <= (*GameBNMO).Neff)
    {
        if (inp == 0)
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?");
            StartCommand();
            
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD ALL...\n");
                printf("\n");
                int j;
                for (j=0; j < ScoreBoard->NeffArrayOfMap; j++)
                {
                    CreateEmptyMap(&(ScoreBoard->AMap[j]));
                }
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
        else
        {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)?", (*GameBNMO).A[inp-1]);
            StartCommand();
            if (compareWord(CurrentCommand, "YA") == true)
            {
                printf("MELAKUKAN RESET SCOREBOARD %s...\n", (*GameBNMO).A[inp-1] );
                printf("\n");
                CreateEmptyMap(&ScoreBoard->AMap[inp-1]);
                
            }
            else if (compareWord(CurrentCommand, "TIDAK") == true)
            {
                printf("RESET SCOREBOARD %s DIBATALKAN\n", (*GameBNMO).A[inp-1]);
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

void RESETHISTORY(Stack *HistoryBNMO)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK)");
    StartCommand();
    if (compareWord(CurrentCommand, "YA") == true)
    {
        CreateEmptyStack(HistoryBNMO);
        printf("History berhasil di-reset\n"); 
    }
    else if (compareWord(CurrentCommand, "TIDAK") == true)
    {
        printf("History tidak jadi di-reset.\n");
        HISTORY(*HistoryBNMO, Top(*HistoryBNMO)+1);
    }
    else
    {
        printf("Input yang diberikan tidak valid\n");
    }
    
}

void RNG(Map *MapRNG){
    srand(time(NULL));
    int r = rand()%101;
    int masukan;
    int score = 10;
    int i = 0;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
 
    StartCommand();
    masukan = wordtoInt(CurrentCommand);

    while (masukan != r && i < 9){
                if (masukan < r){
                    printf("Lebih besar\n");
                }
                else if (masukan > r){
                    printf("Lebih kecil\n");
                }
                i++;
                printf("Tebakan: ");

                StartCommand();
                masukan = wordtoInt(CurrentCommand);
                score--;
    }

    if (score > 0 && masukan == r){
        printf("Ya, X adalah ");
        printf("%d.\n", masukan);
        printf("Score yang didapatkan adalah %d.", score);
    }
    else{
        printf("Anda tidak beruntung. Score yang didapatkan adalah 0.");
    }
    
    char player [50];
    char *temp;
    int k;
    printf("\n");
    printf("Masukkan nama pemain: ");
    StartGame();
    wordtoString(CurrentCommand, player);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    k = 0;
    while (k <= CurrentCommand.Length){
        temp[k] = player[k];
            k += 1;
    }
    InsertMap(MapRNG, temp, score);
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
    printf("HISTORY <n>     : Command untuk menampilkan riwayat permainan sebanyak n kali\n");\
    printf("RESET HISTORY   : Command untuk menghapus semua riwayat permainan\n");
    printf("SCOREBOARD      : Command untuk menampilkan scoreboard dari game tersedia\n");
    printf("RESET SCOREBOARD: Command untuk menghapus scoreboard dari game yang dipilih\n");
    printf("SKIPGAME        : Command untuk melewati permainan ke-n\n");
    printf("QUIT            : Command untuk keluar dari permainan\n");
    printf("HELP            : Command untuk menampilkan daftar-daftar command\n");
    
} 

void QUIT() {
    printf("Anda keluar dari game BNMO. \n");
    printf("Bye bye ... \n");
    exit(0);
}

