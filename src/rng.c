#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/mesinkarakter/mesinkarakter.h"

void rng(){
    srand(time(NULL));
    int r = rand()%101;
    int masukan;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("%d\n", r);
    printf("Tebakan: ");
    scanf("%d", &masukan);
    while (masukan != r){
        if (masukan < r){
            printf("Lebih besar\n");
        }
        else{
            printf("Lebih kecil\n");
        }
        printf("Tebakan: ");
        scanf("%d", &masukan);
    }
    printf("Ya, X adalah ");
    printf("%d.", masukan);
}
