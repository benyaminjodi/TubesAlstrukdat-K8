#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"


int main()
{
    ArrayDin ArrayGame;
    Queue QueueGame;
    Queue QueuePlay;
    ArrayGame = MakeArrayDin();
    CreateQueue(&QueueGame);
    CreateQueue(&QueuePlay);
    boolean endProgram = false;
    printf(" _    _         _ _         _      \n");
    printf("| |  | |       | | |       | |     \n");
    printf("| |__| |  ___  | | |  ___  | |     \n");
    printf("|  __  | / _ . | | | / _ . | |     \n");
    printf("| |  | | . __/ | | |  (_)  |_|     \n");
    printf("|_|  |_| '___  |_|_| .___/ (_)     \n");
                          
                        
    printf("Welcome to BNMO\n");                          
     
    printf("START/LOAD(?)\n");
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        StartCommand();
        //printf("%s\n", CurrentCommand);
        //ADVCommand();
        //printf("%s\n", CurrentCommand);
        if (IsEmpty(ArrayGame))
        {
            if (compareWord(CurrentCommand, "START") == true)
            {
                STARTBNMO(&ArrayGame);
            }
            else if (compareWord(CurrentCommand, "LOAD") == true)
            {
                ADVCommand();
                // printf("%s", CurrentCommand);
                char filename[50];
                wordtoString(CurrentCommand, filename);
                //printf("%s", filename);
                LOADBNMO(&ArrayGame, filename);
                
            }
            else if (compareWord(CurrentCommand, "HELP") == true)
            {
                HELP();
            }
            else
            {
               printf("Program belum memiliki file konfigurasi\n");
               printf("Silakan load file dengan command LOAD <filename>\n"); 

            }
        }
        else{
            if (compareWord(CurrentCommand, "LIST") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    LISTGAME(ArrayGame);
                }
                
            }
            if (compareWord(CurrentCommand, "QUEUE") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    QUEUEGAME(&QueueGame, ArrayGame);
                }
            }
            else if (compareWord(CurrentCommand, "CREATE") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    CREATEGAME(&ArrayGame);
                }
            }
            else if (compareWord(CurrentCommand, "QUEUE") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    QUEUEGAME(&QueueGame, ArrayGame);
                }
            }
            else if (compareWord(CurrentCommand, "PLAY") == true)
            {
                ADVCommand();   
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    PLAYGAME(&QueueGame);
                }
            }
            else if (compareWord(CurrentCommand, "DELETE") == true)
            {
                ADVCommand();
                if (compareWord(CurrentCommand, "GAME") == true)
                {
                    DELETEGAME (&ArrayGame, QueueGame);
                }
            }
            else if (compareWord(CurrentCommand, "SAVE") == true)
            {
                ADVCommand();
                // printf("%s\n",CurrentCommand);
                char filename[50];
                wordtoString(CurrentCommand, filename);   
                // printf("%s",filename);            
                SAVE(&ArrayGame, filename);
            }

            else if (compareWord(CurrentCommand, "HELP") == true)
            {
                HELP();
            }
            else if (compareWord(CurrentCommand, "QUIT") == true)
                {
                    QUIT();
                }
            else
            {
                COMMANDLAIN();
            }
            
        }
    }
}