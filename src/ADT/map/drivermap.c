#include <stdio.h>
#include "map.h"
int main()
{
    Map M;
    char A,B,C;
    CreateEmptyMap(&M);
    Insert(&M, &A, 2);
    Insert(&M, &B, 3);
    Insert(&M, &C, 4);
    printf("%d\n", Value(M, &A));
    printf("%d\n", Value(M, &B));
    printf("%d\n", Value(M, &C));
    
    Delete(&M, &A);
    printf("%d\n", Value(M, &A));
    printf("%d\n", Value(M, &B));
    printf("%d\n", Value(M, &C));
    return 0;

}