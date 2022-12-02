
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
    ArrayMap ScoreBoard;
    

    ArrayGame = MakeArrayDin();
    CreateQueue(&QueueGame);
    CreateEmptyStack(&StackHistory);
    MakeEmptyArrayOfMap(&ScoreBoard);

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
                STARTBNMO(&ArrayGame, &ScoreBoard);
            }
            /* ----LOAD---- */
            else if (compareWord(CurrentCommand, "LOAD") == true)
            {
                ADVCommand();
                char filename[50];
                wordtoString(CurrentCommand, filename);
                LOADBNMO(&ArrayGame, filename, &StackHistory, &ScoreBoard);
                
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
                else
                {
                    COMMANDLAIN();
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
                else
                {
                    COMMANDLAIN();
                }
            }
            /* ----CREATE GAME--- */
            else if (compareWord(CurrentCommand, "CREATE") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    CREATEGAME(&ArrayGame, &ScoreBoard);
                }
                else
                {
                    COMMANDLAIN();
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
                else
                {
                    COMMANDLAIN();
                }
            }
            /* ----PLAY GAME--- */
            else if (compareWord(CurrentCommand, "PLAY") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    PLAYGAME(&QueueGame, &StackHistory, &ScoreBoard, &ArrayGame);
                }
                else
                {
                    COMMANDLAIN();
                }
            }
            /* ----DELETE GAME--- */
            else if (compareWord(CurrentCommand, "DELETE") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    DELETEGAME (&ArrayGame, QueueGame, &ScoreBoard, &StackHistory);
                }
                else
                {
                    COMMANDLAIN();
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
                    SKIPGAME(&QueueGame, x,  &StackHistory, &ScoreBoard, &ArrayGame);
                } 
                else
                {
                    COMMANDLAIN();
                }
            }

            else if (compareWord(CurrentCommand, "SCOREBOARD") == true)
            {
                SCOREBOARD(ScoreBoard, ArrayGame);
            }

            else if (compareWord(CurrentCommand, "RESET") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "SCOREBOARD") == true)
                {
                    RESETSCOREBOARD(&ScoreBoard, &ArrayGame);
                }
                else if (compareWord(CurrentCommand, "HISTORY") == true)
                {
                    RESETHISTORY(&StackHistory);
                }
                else
                {
                    COMMANDLAIN();
                }
            }

            else if (compareWord(CurrentCommand, "HISTORY") == true)
            {
                ADVCommand();  
                int x;
                x = wordtoInt(CurrentCommand);
                HISTORY(StackHistory, x);   
            }            
            /* ---SAVE--- */
            else if (compareWord(CurrentCommand, "SAVE") == true)
            {
                ADVCommand();
                char filename[50];
                wordtoString(CurrentCommand, filename);     
                       
                SAVEBNMO(&ArrayGame, filename, &StackHistory, &ScoreBoard);
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
            
            while(!EndWord)
            {
                ADVCommand();
            }
            
        }
    }
}