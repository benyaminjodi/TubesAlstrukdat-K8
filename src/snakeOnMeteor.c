#include "snakeOnMeteor.h"

/*
HAL YANG MASIH HARUS DIPERBAIKIN
1. Proses kena meteor
2. Kondisi kalah
3. ??? (ga tau, coba cek aja misalnya ada yang kurang)

command gcc: gcc src/console.c src/ADT/arraydinamis/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/queue/queue.c src/ADT/queue/queueDD.c src/ADT/map/map.c src/diner-dash.c src/tictactoe.c src/snakeOnMeteor.c src/ADT/linkedlist/linkList.c -o snakeOnMeteor
*/

void CreateEmptyMatrixMap(matrixMap *peta) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            (*peta).buffer[i][j] = '0';
        }
    }
}

void displayMatrixMap(matrixMap peta) {
    printf("-----------------\n");
    for (int i = 0; i < 5; i++) {
        printf("|");
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                printf(" ");
            }
            if (peta.buffer[i][j] == '0') {
                printf(" ");
            } else {
                printf("%c", peta.buffer[i][j]);
            }
            if (j != 4) {
                printf("  ");
            } else {
                printf(" ");
            }
        }
        printf("|");
        printf("\n");
    }
    printf("-----------------\n");
}

void updateMatrixMap(matrixMap *peta, List snake, List makanan, List meteor, int lastX, int lastY, int xDelMeteor, int yDelMeteor) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == lastX && i == lastY) {
                (*peta).buffer[i][j] = '0';
            }
            if (j == xDelMeteor && i == yDelMeteor) {
                (*peta).buffer[i][j] = '0';
            }
            if (SearchList(snake, j, i) != NIL) {
                addressNode P = First(snake);
                addressNode Q = SearchList(snake, j, i);
                int count = 0;
                while (P != Q) {
                    count++;
                    P = Next(P);
                }
                if (count == 0) {
                    (*peta).buffer[i][j] = 'H';
                } else {
                    (*peta).buffer[i][j] = count + '0';
                }
            }
            if (SearchList(makanan, j, i) != NIL) {
                (*peta).buffer[i][j] = 'o';
            }
            if (SearchList(meteor, j, i) != NIL) {
                (*peta).buffer[i][j] = 'm';
            }
        }
    }
}

int listLength(List list) {
    addressNode P = First(list);
    int length = 0;
    while (P != NIL) {
        length++;
        P = Next(P);
    }
    return length;
}

int rng2(int lower, int upper)
// Menghasilkan bilangan random antara [lower..upper]
{
  int r = (rand() % (upper - lower + 1)) + lower;
  return r;
}

void initSnake(List *snake) {
    int xHead = rng2(0, 4);
    int yHead = rng2(0, 2);
    InsVFirst(snake, xHead, yHead);
    if (xHead >= 2) {
        InsVLast(snake, xHead-1, yHead);
        InsVLast(snake, xHead-2, yHead);
    } else if (xHead == 1) {
        InsVLast(snake, xHead-1, yHead);
        if (yHead > 0) {
            InsVLast(snake, xHead-1, yHead-1);
        } else {
            InsVLast(snake, xHead-1, yHead+1);
        }
    } else {
        InsVLast(snake, xHead, yHead+1);
        InsVLast(snake, xHead, yHead+2);
    }
}

void validateCommand(char inpt, List snake, List meteor, boolean *isValid) {
    if (inpt == 'w' || inpt == 'W') {
        if (InfoY(First(snake)) != 0) {
            if (SearchList(snake, InfoX(First(snake)), InfoY(First(snake))-1) != NIL) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                printf("Silakan input command lain\n");
            } else if (SearchList(meteor, InfoX(First(snake)), InfoY(First(snake))-1) != NIL) {
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silakan masukkan command lainnya\n");
            } else {
                (*isValid) = true;
                printf("Berhasil bergerak ke atas\n");
            }
        } else {
            printf("Anda tidak dapat bergerak ke atas\n");
            printf("Silakan input command lain\n");
        }
    } else if (inpt == 'a' || inpt == 'A') {
        if (InfoX(First(snake)) != 0) {
            if (SearchList(snake, InfoX(First(snake))-1, InfoY(First(snake))) != NIL) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                printf("Silakan input command lain\n");
            } else if (SearchList(meteor, InfoX(First(snake))-1, InfoY(First(snake))) != NIL) {
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silakan masukkan command lainnya\n");
            } else {
                (*isValid) = true;
                printf("Berhasil bergerak ke kiri\n");
            }
        } else {
            printf("Anda tidak dapat bergerak ke kiri\n");
            printf("Silakan input command lain\n");
        }
    } else if (inpt == 's' || inpt == 'S') {
        if (InfoY(First(snake)) != 4) {
            if (SearchList(snake, InfoX(First(snake)), InfoY(First(snake))+1) != NIL) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                printf("Silakan input command lain\n");
            } else if (SearchList(meteor, InfoX(First(snake)), InfoY(First(snake))+1) != NIL) {
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silakan masukkan command lainnya\n");
            } else {
                (*isValid) = true;
                printf("Berhasil bergerak ke bawah\n");
            }
        } else {
            printf("Anda tidak dapat bergerak ke bawah\n");
            printf("Silakan input command lain\n");
        }
    } else if (inpt == 'd' || inpt == 'D') {
        if (InfoX(First(snake)) != 4) {
            if (SearchList(snake, InfoX(First(snake))+1, InfoY(First(snake))) != NIL) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                printf("Silakan input command lain\n");
            } else if (SearchList(meteor, InfoX(First(snake))+1, InfoY(First(snake))) != NIL) {
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silakan masukkan command lainnya\n");
            } else {
                (*isValid) = true;
                printf("Berhasil bergerak ke kanan\n");
            }
        } else {
            printf("Anda tidak dapat bergerak ke kanan\n");
            printf("Silakan input command lain\n");
        }
    } else {
        printf("Command tidak valid! Silakan input command menggunakan huruf w/a/s/d\n");
    }
}

void moveSnake(List *snake, char inpt, int *lastX, int *lastY) {
    addressNode P = First(*snake);
    int prevX = InfoX(P);
    int prevY = InfoY(P);
    // TIDAK BOLEH KE METEOR
    if (inpt == 'w' || inpt == 'W') {
        InfoY(First(*snake)) -= 1;
    } else if (inpt == 'a' || inpt == 'A') {
        InfoX(First(*snake)) -= 1;
    } else if (inpt == 's' || inpt == 'S') {
        InfoY(First(*snake)) += 1;
    } else if (inpt == 'd' || inpt == 'D') {
        InfoX(First(*snake)) += 1;
    }
    P = Next(P);
    while (P != NIL) {
        int tempX = InfoX(P);
        int tempY = InfoY(P);
        InfoX(P) = prevX;
        InfoY(P) = prevY;
        P = Next(P);
        prevX = tempX;
        prevY = tempY;
    }
    *lastX = prevX;
    *lastY = prevY;
}

void addMakanan(List *makanan, List snake) {
    int xFood = rng2(0, 4);
    int yFood = rng2(0, 4);
    if (!IsEmptyList(*makanan)) {
        while (SearchList(snake, xFood, yFood) != NIL && SearchList(*makanan, xFood, yFood) != NIL) {
            xFood = rng2(0, 4);
            yFood = rng2(0, 4);
        }
    } else {
        while (SearchList(snake, xFood, yFood) != NIL) {
            xFood = rng2(0, 4);
            yFood = rng2(0, 4);
        }
    }
    InsVLast(makanan, xFood, yFood);
}

boolean isMakan(List snake, List makanan) {
    int headX = InfoX(First(snake));
    int headY = InfoY(First(snake));
    if (SearchList(makanan, headX, headY)) {
        return true;
    } else {
        return false;
    }
}

void prosesMakan(List *snake, List *makanan) {
    int tailX = InfoX(Last(*snake));
    int tailY = InfoY(Last(*snake));
    if (tailX > 0) {
        InsVLast(snake, tailX-1, tailY);
    } else if (tailY > 0) {
        InsVLast(snake, tailX, tailY-1);
    } else {
        InsVLast(snake, tailX, tailY+1);
    }
    addressNode P = SearchList(*makanan, InfoX(First(*snake)), InfoY(First(*snake)));
    if (listLength(*makanan) == 1 || P == First(*makanan)) {
        int xFood, yFood;
        DelVFirst(makanan, &xFood, &yFood);
    } else {
        addressNode prev = Prev(P);
        addressNode Pdel;
        DelAfter(makanan, &Pdel, prev);
    }
    addMakanan(makanan, *snake);
}

void addMeteor(List *meteor, List makanan) {
    int xMeteor = rng2(0,4);
    int yMeteor = rng2(0,4);
    if (!IsEmptyList(*meteor)) {
        addressNode P = SearchList(*meteor, xMeteor, yMeteor);
        if (!IsEmptyList(makanan)) {
            addressNode Q = SearchList(makanan, xMeteor, yMeteor);
            while (P != NIL && Q != NIL) {
                xMeteor = rng2(0,4);
                yMeteor = rng2(0,4);
                P = SearchList(*meteor, xMeteor, yMeteor);
                Q = SearchList(makanan, xMeteor, yMeteor);
            }
        } else {
            while (P != NIL) {
                xMeteor = rng2(0,4);
                yMeteor = rng2(0,4);
                P = SearchList(*meteor, xMeteor, yMeteor);
            }
        }
    }
    InsVLast(meteor, xMeteor, yMeteor);
}

void delMeteor(List *meteor, int *xDelMeteor, int *yDelMeteor) {
    if (!IsEmptyList(*meteor)) {
        DelVFirst(meteor, xDelMeteor, yDelMeteor);
    }
}

boolean prosesMeteor(List *snake, List meteor, boolean *isMeteorHitHead) {
    addressNode lokasiMeteor = First(meteor);
    while (lokasiMeteor != NIL) {
        int xMeteor = InfoX(lokasiMeteor);
        int yMeteor = InfoY(lokasiMeteor);
        addressNode kena = SearchList(*snake, xMeteor, yMeteor);
        if (kena != NIL) {
            if (kena == First(*snake)) {
                int xHead, yHead;
                (*isMeteorHitHead) = true;
            } else {
                addressNode prev = Prev(kena);
                addressNode Pdel;
                DelAfter(snake, &Pdel, prev);
            }
        }
        lokasiMeteor = Next(lokasiMeteor);
    }
}

boolean isLose(List snake, boolean isMeteorHitHead) {
    if (isMeteorHitHead) {
        return true;
    } else if (listLength(snake) == 0) {
        return true;
    } else {
        return false;
    }
    // Belum tambahin kondisi kalah yg kedua
}

int hitungScore(List snake, boolean isMeteorHitHead) {
    if (isMeteorHitHead) {
        return 2*(listLength(snake)-1);
    } else {
        return 2*listLength(snake);
    }
}

void snake(Map *MapSnake) {
    List snake;
    List makanan;
    List meteor;
    matrixMap peta;
    CreateEmptyList(&snake);
    CreateEmptyList(&makanan);
    CreateEmptyList(&meteor);
    CreateEmptyMatrixMap(&peta);

    // INISIALISASI RNG
    srand(time(NULL));
    
    // PESAN SELAMAT DATANG
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Mengenerate peta, snake, dan makanan...\n");
    printf("Berhasil digenerate!\n");
    printf("_______________________________________\n");
    printf("Berikut merupakan peta permainan\n");
    
    // INISIALISASI GAME
    int lastX, lastY;
    int xDelMeteor, yDelMeteor;
    boolean isMeteorHitHead = false;
    int nTurn = 0;
    initSnake(&snake);
    addMakanan(&makanan, snake);
    updateMatrixMap(&peta, snake, makanan, meteor, lastX, lastY, xDelMeteor, yDelMeteor);
    displayMatrixMap(peta);
   
    // PROGRAM UTAMA
    while (isLose(snake, isMeteorHitHead) == false) {
        // TERIMA COMMAND
        char command[50];
        char inpt;
        boolean isValid = false;
        while (!isValid) {    
            printf("Silakan masukkan command Anda: ");
            StartCommand();
            if (CurrentCommand.Length == 1) {
                inpt = CurrentCommand.TabWord[0];
                validateCommand(inpt, snake, meteor, &isValid);
            } else {
                printf("Command tidak valid! Silakan input command menggunakan huruf w/a/s/d\n");
            }
        }

        // PROSES COMMAND
        moveSnake(&snake, inpt, &lastX, &lastY);
        if (isMakan(snake, makanan)) {
            prosesMakan(&snake, &makanan);
        }
        delMeteor(&meteor, &xDelMeteor, &yDelMeteor);
        addMeteor(&meteor, makanan);
        prosesMeteor(&snake, meteor, &isMeteorHitHead);
        updateMatrixMap(&peta, snake, makanan, meteor, lastX, lastY, xDelMeteor, yDelMeteor);
        displayMatrixMap(peta);

         // HANYA UNTUK TES
        printf("snake: ");
        PrintForward(snake);
        printf("\n");
        printf("makanan: ");
        PrintForward(makanan);
        printf("\n");
        printf("meteor: ");
        PrintForward(meteor);
        printf("\n");
    }

    // HITUNG SCORE
    int score = hitungScore(snake, isMeteorHitHead);
    printf("Score Anda: %d\n", score);

    // MASUKKAN NAMA PEMAIN DAN TAMBAH KE MAP
    char player[50];
    char *temp;
    int i;
    printf("\n");
    printf("Masukkan nama pemain: ");
    StartCommand();
    wordtoString(CurrentCommand, player);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    i = 0;
    while (i <= CurrentCommand.Length)
    {
        temp[i] = player[i];
        
        i += 1;
    }
    InsertMap(MapSnake, temp, score);
}