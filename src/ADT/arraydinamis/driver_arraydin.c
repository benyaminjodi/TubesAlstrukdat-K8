#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "../../boolean.h"

int main()
{
    ArrayDin array;
    array = MakeArrayDin();
    char * temp; 
    int j;
    int n;
    printf("Masukkan jumlah string yang ingin di insert : ");
    scanf("%d", &n);
    printf("Masukkan string ke dalam array :  \n");
    for (j = 0; j <= n-1;j++)
    {
        temp = (char*) malloc (50*sizeof(char));
        scanf("%s", temp);      
        InsertLast(&array, temp);
    }
    printf("\n");
    printf("Hasil arraydin :\n");
    PrintArrayDin(array);
    printf("\n");

    printf("Hasil reverse arraydin : ");
    ReverseArrayDin(&array);
    PrintArrayDin(array);

    printf("Panjang arraydin : ");
    printf("%d\n", Length(array));

    printf("Melakukan insert first (mengisi kata 'kamu') \n");
    InsertFirst(&array, "kamu");
    PrintArrayDin(array);

    printf("Menghapus isi array idx terakhir : \n");
    DeleteLast(&array);
    PrintArrayDin(array);

    return 0;
}