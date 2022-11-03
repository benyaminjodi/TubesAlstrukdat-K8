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
            else
            {
                (compareWord(command, "START") == false);
                endProgram = true;
            }
        }
        
    }
}