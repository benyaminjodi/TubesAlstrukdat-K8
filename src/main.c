
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

int main()
{
    ArrayDin ArrayGame;
    Queue QueueGame;
    Stack StackHistory;
    Map MapTicTacToe;
    Map MapRNG;
    Map MapDD;
    Map MapHangman;
    Map MapTower;
    Map MapSnake;

    ArrayGame = MakeArrayDin();
    CreateQueue(&QueueGame);
    CreateEmptyStack(&StackHistory);
    CreateEmptyMap(&MapTicTacToe);
    CreateEmptyMap(&MapRNG);
    CreateEmptyMap(&MapDD);
    CreateEmptyMap(&MapHangman);
    CreateEmptyMap(&MapTower);
    CreateEmptyMap(&MapSnake);

    boolean endProgram = false;
    printf(" _    _         _ _         _      \n");
    printf("| |  | |       | | |       | |     \n");
    printf("| |__| |  ___  | | |  ___  | |     \n");
    printf("|  __  | / _ . | | | / _ . | |     \n");
    printf("| |  | | . __/ | | |  (_)  |_|     \n");
    printf("|_|  |_| '___  |_|_| .___/ (_)     \n");
    printf("--------Kelompok 8 K1---------     \n");                      
    printf("       Welcome to BNMO             \n");                           
    printf("        START/LOAD(?)              \n");
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        StartCommand();
        if (IsEmpty(ArrayGame))
        {
            /* ----START---- */
            if (compareWord(CurrentCommand, "START") == true)
            {
                STARTBNMO(&ArrayGame);
            }
            /* ----LOAD---- */
            else if (compareWord(CurrentCommand, "LOAD") == true)
            {
                ADVCommand();
                char filename[50];
                wordtoString(CurrentCommand, filename);
                LOADBNMO(&ArrayGame, filename, &StackHistory, &MapRNG, &MapDD, &MapHangman, &MapTower, &MapSnake, &MapTicTacToe);
                
            }
            /* ---HELP--- */
            else if (compareWord(CurrentCommand, "HELP") == true)
            {
                HELP();
            }
            /*---INPUTAN DILUAR START/LOAD--- */
            else
            {
               printf("Program belum memiliki file konfigurasi\n");
               printf("Silakan load file dengan command LOAD <filename>\n"); 

            }
        }
        else{
            /* ---LIST GAME--- */
            if (compareWord(CurrentCommand, "LIST") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    LISTGAME(ArrayGame);
                }
            }
            /* ---QUEUE GAME--- */
            else if (compareWord(CurrentCommand, "QUEUE") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    QUEUEGAME(&QueueGame, ArrayGame);
                }
            }
            /* ----CREATE GAME--- */
            else if (compareWord(CurrentCommand, "CREATE") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    CREATEGAME(&ArrayGame);
                }
            }
            /* ----QUEUE GAME--- */
            else if (compareWord(CurrentCommand, "QUEUE") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    QUEUEGAME(&QueueGame, ArrayGame);
                }
            }
            /* ----PLAY GAME--- */
            else if (compareWord(CurrentCommand, "PLAY") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    PLAYGAME(&QueueGame, &StackHistory, &MapRNG, &MapDD, &MapHangman, &MapTower, &MapSnake, &MapTicTacToe);
                }
            }
            /* ----DELETE GAME--- */
            else if (compareWord(CurrentCommand, "DELETE") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    DELETEGAME (&ArrayGame, QueueGame);
                }
            }
            /* ----SKIPGAME <n>--- */
            else if (compareWord(CurrentCommand, "SKIP") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    ADVCommand();
                    int x;
                    x = wordtoInt(CurrentCommand);
                    SKIPGAME(&QueueGame, x,  &StackHistory, &MapRNG, &MapDD, &MapHangman, &MapTower, &MapSnake, &MapTicTacToe);
                } 
            }

            else if (compareWord(CurrentCommand, "SCOREBOARD") == true)
            {
                SCOREBOARD(MapRNG, MapDD, MapHangman, MapTower, MapSnake, MapTicTacToe);
            }
            else if (compareWord(CurrentCommand, "RESET") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "SCOREBOARD") == true)
                {
                    RESETSCOREBOARD(&MapRNG, &MapDD, &MapHangman, &MapTower, &MapSnake, &MapTicTacToe);
                }
            }

            else if (compareWord(CurrentCommand, "HISTORY") == true)
            {
                ADVCommand();  
                int x;
                x = wordtoInt(CurrentCommand);
                HISTORY(StackHistory, x);   
            }

            else if (compareWord(CurrentCommand, "RESET") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "HISTORY") == true)
                {
                    RESETHISTORY(&StackHistory);
                }
            }
            
            /* ---SAVE--- */
            else if (compareWord(CurrentCommand, "SAVE") == true)
            {
                ADVCommand();
                char filename[50];
                wordtoString(CurrentCommand, filename);     
                       
                SAVEBNMO(&ArrayGame, filename, &StackHistory, &MapRNG, &MapDD, &MapHangman, &MapTower, &MapSnake, &MapTicTacToe);
            }
            /* ---HELP--- */
            else if (compareWord(CurrentCommand, "HELP") == true)
            {
                HELP();
            }
            /* ---QUIT--- */
            else if (compareWord(CurrentCommand, "QUIT") == true)
            {
                QUIT();
            }
            /* ---COMMAND LAIN--- */
            else
            {
                COMMANDLAIN();
            }
            
        }
    }
}