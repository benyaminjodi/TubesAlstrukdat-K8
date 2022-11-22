#include <stdio.h>
#include "stack.h"

int main()
{
    // Program untuk menguji ADT Stack
    Stack S;
    infostack X;
    CreateEmptyStack(&S);
    printf("Apakah stack kosong? %s\n", IsEmptyStack(S));
    printf("Apakah stack penuh? %s\n", IsFull(S));
    printf("Panjang stack: %d\n", LengthStack(S));
    printf("Push 1\n");
    Push(&S, "1");
    printf("Push 2\n");
    Push(&S, "2");
    printf("Push 3\n");
    Push(&S, "3");
    printf("Push 4\n");
    Push(&S, "4");
    printf("Push 5\n");
    Push(&S, "5");

    printf("Apakah stack kosong? %s\n", IsEmptyStack(S));
    int i = 0;
    while (i <= Top(S)+1)
    {
        printf("%d. %s\n", (i+1), InfoTop(S));
        i++;
    }


}