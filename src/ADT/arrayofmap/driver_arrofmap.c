#include<stdio.h>
#include<stdlib.h>
#include "../../console.h"
#include "arrayofmap.h"

int main()
{
    ArrayMap A;
    Map B;
    CreateEmptyMap(&B);
    MakeEmptyArrayOfMap(&A);
    printf("Apakah arraf of map kosong ? %s", IsEmptyArrayOfMap(A) ? "true" : "false");
    printf("\n");
    printf("Apakah array of map penuh ? %s", IsFullArrayOfMap(A) ? "true" : "false");
    printf("\n");
    printf("Banyak elemen saat ini %d", NbElmtArrayOfMap(A));
    printf("Sekarang dilakukan input pada program \n");
    InsertMap(&B, "Jodi", 10);

    printf("Apakah map kosong ? %s", IsEmptyMap(B) ? "true" : "false");
    printf("\n");
    SetElArrayOfMap(&A, 0, B);
    printf("Apakah arraf of map kosong ? %s", IsEmptyArrayOfMap(A) ? "true" : "false");
    printf("\n");
    printf("Banyak elemen saat ini %d", NbElmtArrayOfMap(A));
    printf("\n");

    return 0;
}