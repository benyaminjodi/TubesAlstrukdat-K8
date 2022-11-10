#include<stdio.h>
#include "mesinkarakter.h"

int main()
{
    START("./data/test_mesinkar.txt");
    while (CC != '.')
    {
        printf("%c\n", CC);
        ADV();
    }
    printf("Silakan ketikkan contoh inputan pada terminal\n");
    StartC();
    while (CC != '\n')
    {
        printf("%c\n", CC);
        ADVC();
    }


    

}