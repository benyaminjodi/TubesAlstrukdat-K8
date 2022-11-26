#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
#include "console.h"


void HangmanFile(ArrayDin *ListHangman)
{
    char string[50];
    char *temp;
    int i;
    StartWord("./data/hangman.txt");
    
    while(!feof(pita))
    {
        wordtoString(CurrentWord, string);
        temp = (char *) malloc (CurrentWord.Length * sizeof(char));
        i = 0;
        while (i <= CurrentWord.Length)
        {
            temp[i] = string[i];
            
            i += 1;
        }
        InsertLast(ListHangman, temp);
        ADVWord();  
            
    }
    wordtoString(CurrentWord, string);
    temp = (char *) malloc (CurrentWord.Length * sizeof(char));
    i = 0;
    while (i <= CurrentWord.Length)
    {
        temp[i] = string[i];
        
        i += 1;
    }
    InsertLast(ListHangman, temp);

}

void Before(Queue *Q)
{
    int i;
    Lowerstring(Q->buffer[i]);
    for (i=IDX_HEAD(*Q); i <= IDX_TAIL(*Q); i++){   
        printf("%s", (*Q).buffer[i]);
    }
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

void PrintKata(char *guess)
{
    Upperstring(guess);
    int i;
    for (i=0; i < stringlen(guess); i++){
        printf("%c ", guess[i]);
    }
}

boolean isInQueue(Queue QueueBefore, char *temp)
{
    if (isEmpty(QueueBefore))
    {
        return false;
    }
    else
    {
        int i;
        for (i=IDX_HEAD(QueueBefore); i <= IDX_TAIL(QueueBefore); i++){
            if (compareString(QueueBefore.buffer[i], temp) == true)
            {
                return true;
            }
        }
        return false;
    }
}


void HANGMAN(Map *MapHangman)
{
    printf("Welcome to Hangman Game\n");
    printf("Game ini memiliki 2 fitur : \n");
    printf("1. Play Hangman\n");
    printf("2. Add Kata\n");
    printf("MASUKKAN INPUT ANDA (1/2) : ");
    StartCommand();
    printf("\n");
    if (compareWord(CurrentCommand, "1") == true)
    {
        PlayHangman(MapHangman);
    }
    else if (compareWord(CurrentCommand, "2") == true)
    {
        AddKataHangman();
    }
    else
    {
        printf("Input anda salah\n");
    }
}

void AddKataHangman()
{
    char string[50];
    char *temp;
    ArrayDin ListHangman;
    ListHangman = MakeArrayDin();
    HangmanFile(&ListHangman);
    printf("Masukkan kata yang ingin ditambahkan : ");
    StartCommand();
    wordtoString(CurrentCommand, string);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    int i = 0;
    while (i <= CurrentCommand.Length)
    {
        temp[i] = string[i];
        
        i += 1;
    }
    Lowerstring(temp);
    boolean found =false;
    for(int j = 0; j < ListHangman.Neff; j++){
        Lowerstring(ListHangman.A[j]);
        if (compareString(ListHangman.A[j], temp) == true)
        {
            found = true;
        }
    }
    Upperstring(temp);
    if(found)
    {
        printf("Kata ini sudah ada di dalam sistem Hangman.\n");
    }
    else
    {
        FILE *pita;
        pita = fopen("./data/hangman.txt", "a");
        fprintf(pita, "\n");
        fprintf(pita, "%s", CurrentCommand);
        fclose(pita);
        printf("Kata berhasil ditambahkan\n");
    }
}


void PlayHangman(Map *MapHangman)
{
    char *hangmanstr;
    ArrayDin ListHangman;
    Queue QueueBefore;
    ListHangman = MakeArrayDin();
    CreateQueue(&QueueBefore);
    HangmanFile(&ListHangman);

    srand(time(NULL));
    int x = rand() % Length(ListHangman);
    char guess[stringlen(ListHangman.A[x])];
    int i;
    for (i = 0; i < stringlen(ListHangman.A[x]); i++)
    {
        guess[i] = '_';
    }
    guess[stringlen(ListHangman.A[x])] = '\0';
   
    /* Inisiasi kata yang akan ditebak*/
    hangmanstr = ListHangman.A[x];
    Lowerstring(hangmanstr);

    /* Inisiasi variabel */
    int chances = 10;
    int score = 0;

    boolean found;
    
    while (chances > 0)
    {
        found = false;
        char inp[50];
        char *temp;
        do
        {
        printf("Tebakan sebelumnya : ");
        if (isEmpty(QueueBefore))
        {
            printf("-\n");
        }
        else
        {
            Before(&QueueBefore);
            printf("\n");
        }        
        printf("Kata : ");
        PrintKata(guess);
        
        
        printf("\n");

        printf("Kesempatan   : %d\n", chances);

        printf("Masukkan tebakan : ");
       
        
            StartCommand();
            wordtoString(CurrentCommand, inp);
            temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
            int k = 0;
            while (k <= CurrentCommand.Length){
                temp[k] = inp[k];
                    k += 1;
            }
            Lowerstring(temp);
            
            if (stringlen(temp) != 1)
            {
                printf("Tebakan harus menggunakan 1 huruf!\n");
            }
            else if (isInQueue(QueueBefore, temp))
            {
                printf("Anda sudah pernah menebak huruf ini!\n");
            }
            printf("\n");
        } while ((stringlen(temp) != 1) || (isInQueue(QueueBefore, temp)));

        enqueue(&QueueBefore, temp);

        for (i = 0; i < stringlen(hangmanstr); i++)
        {
            if (hangmanstr[i] == temp[0])
            {
                found = true;
                guess[i] = temp[0];
            }
        }
        Lowerstring(guess);
        
        if (!found)
        {
            chances -= 1;
        }
        if (!found && chances == 0)
        {
            Upperstring(hangmanstr);
            printf("Kata yang ditebak adalah : %s \n", hangmanstr);
        }
        if (compareString(guess, hangmanstr) == true)
        {
            Upperstring(hangmanstr);
            printf("Selamat, Anda berhasil menebak kata %s!\n", hangmanstr);
            score += stringlen(hangmanstr);

            CreateQueue(&QueueBefore);         
            x = rand() % Length(ListHangman);   
            hangmanstr = ListHangman.A[x];
            Lowerstring(hangmanstr);
            
            for (i = 0; i < stringlen(hangmanstr); i++)
            {
                guess[i] = '_';
            }
            guess[stringlen(hangmanstr)] = '\0';  
            Lowerstring(guess);
        }
    }
    char *temp;
    char player[50];
    printf("Skor anda adalah %d\n", score);  
    printf("Player Name: ");
    StartCommand();
    wordtoString(CurrentCommand, player);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    i = 0;
    while (i <= CurrentCommand.Length)
    {
        temp[i] = player[i];
        
        i += 1;
    }
    InsertMap(MapHangman, temp, score);
}
