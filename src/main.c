#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"


int main()
{
    ArrayDin ArrayGame;
    Queue QueueGame;
    ArrayGame = MakeArrayDin();
    CreateQueue(&QueueGame);

    boolean endProgram = false;
    printf("Welcome to BNMO\n");
    printf("START/LOAD(?)\n");
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        StartCommand();
        // printf("%s\n", CurrentCommand);
        if (IsEmpty(ArrayGame))
        {
            if (compareWord(CurrentCommand, "START") == true)
            {
                STARTBNMO(&ArrayGame);
            }
        }
        else{
            if (compareWord(CurrentCommand, "LIST GAME") == true)
            {
                LISTGAME(ArrayGame);
            }
            if (compareWord(CurrentCommand, "DELETE GAME") == true)
            {
                DELETEGAME (&ArrayGame, QueueGame);
            }
            if (compareWord(CurrentCommand, "HELP") == true)
            {
                HELP();
            }
            if (compareWord(CurrentCommand, "QUIT") == true)
                {
                    QUIT();
                }
        }
    }
}