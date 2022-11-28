#include <stdio.h>
#include "map.h"
int main()
{
    Map M;
    char A,B,C;
    CreateEmptyMap(&M);
    InsertMap(&M, &A , 2);
    InsertMap(&M, &B, 3);
    InsertMap(&M, &C, 4);
    printf("%d\n", Value(M, &A));
    printf("%d\n", Value(M, &B));
    printf("%d\n", Value(M, &C));
    
    DeleteMap(&M, &A);
    printf("%d\n", Value(M, &A));
    printf("%d\n", Value(M, &B));
    printf("%d\n", Value(M, &C));
    return 0;

}