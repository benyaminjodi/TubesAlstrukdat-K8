#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mesinkarakter.h"

void rng(){
    srand(time(NULL));
    int r = rand()%101;
    int masukan;
    int score = 10;
    int i = 0;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("%d\n", r);
    printf("Tebakan: ");
    //scanf("%d", &masukan);
    StartCommand();
    masukan = wordtoInt(CurrentCommand);

    while (masukan != r && i < 9){
                if (masukan < r){
                    printf("Lebih besar\n");
                }
                else if (masukan > r){
                    printf("Lebih kecil\n");
                }
                i++;
                printf("Tebakan: ");
                //scanf("%d", &masukan);
                StartCommand();
                masukan = wordtoInt(CurrentCommand);
                score--;
    }

    if (score > 0 && masukan == r){
        printf("Ya, X adalah ");
        printf("%d.\n", masukan);
        printf("Score yang didapatkan adalah %d.", score);
    }
    else{
        printf("Anda tidak beruntung. Score yang didapatkan adalah 0.");
    }
    //return 0;
}
