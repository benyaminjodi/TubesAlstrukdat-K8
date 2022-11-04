#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"


int main()
{
    ArrayDin ArrayGame;
    ArrayGame = MakeArrayDin();

    boolean endProgram = false;
    char *command;
    printf("Welcome to BNMO\n");
    printf("START/LOAD(?)\n");
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        scanf("%s", command);
        if (IsEmpty(ArrayGame))
        {
            if (compareWord(command, "START") == true)
            {
                STARTBNMO(&ArrayGame);
            }
        }
        else
        {
            if (compareWord(command, "LISTGAME") == true)
            {
                LISTGAME(ArrayGame);
            }
        }
        if (compareWord(command, "EXIT") == true)
            {
                endProgram = true;
            }
        
    }
}