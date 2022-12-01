#include "snakeOnMeteor.h"

void CreateEmptyMatrixMap(matrixMap *peta) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            (*peta).buffer[i][j] = '0';
        }
    }
}

void displayMatrixMap(matrixMap peta) {
    printf("Berikut merupakan peta permainan\n");
    printf("+-----+-----+-----+-----+-----+\n");
    for (int i = 0; i < 5; i++) {
        printf("|");
        for (int j = 0; j < 5; j++) {
            if (peta.buffer[i][j] == '0') {
                printf("     ");
            } else {
                printf("  %c  ", peta.buffer[i][j]);
            }
            if (j < 4) {
                printf("|");
            }
        }
        printf("|");
        printf("\n");
        if (i < 4) {
            printf("+-----+-----+-----+-----+-----+\n");
        }
    }
    printf("+-----+-----+-----+-----+-----+\n");
}

void updateMatrixMap(matrixMap *peta, List snake, int lastX, int lastY, int xFood, int yFood, int xMeteor, int yMeteor, int prevXMeteor, int prevYMeteor, int xObstacle, int yObstacle) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == lastX && i == lastY) {
                (*peta).buffer[i][j] = '0';
            }
            if (j == prevXMeteor && i == prevYMeteor) {
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
            if (xFood == j && yFood == i) {
                (*peta).buffer[i][j] = 'o';
            }
            if (xMeteor == j && yMeteor == i) {
                (*peta).buffer[i][j] = 'm';
            }
            if (xObstacle == j && yObstacle == i) {
                (*peta).buffer[i][j] = 'x';
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
    int yHead = rng2(0, 4);
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
    addressNode P = First(*snake);
    while (P != Nil) {
        if (InfoY(P) < 0 || InfoY(P) > 4) {
            InfoY(P) = InfoY(P) % 5;
        }
        P = Next(P);
    }
}

void validateCommand(char inpt, List snake, int xMeteor, int yMeteor, boolean initMeteor, boolean *isValid, boolean *isHeadStuck) {
    if (inpt == 'w' || inpt == 'W' || inpt == 'a' || inpt == 'A' || inpt == 's' || inpt == 'S' || inpt == 'd' || inpt == 'D') {
        addressNode w = SearchList(snake, InfoX(First(snake)), InfoY(First(snake))-1);
        addressNode a = SearchList(snake, InfoX(First(snake))-1, InfoY(First(snake)));
        addressNode s = SearchList(snake, InfoX(First(snake)), InfoY(First(snake))+1);
        addressNode d = SearchList(snake, InfoX(First(snake))+1, InfoY(First(snake)));
        *isHeadStuck = (w != NIL) && (a != NIL) && (s != NIL) && (d != NIL);
        if (!(*isHeadStuck)) {
            if (inpt == 'w' || inpt == 'W') {
                if (InfoY(First(snake)) != 0) {
                    if (w != NIL) {
                        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                        printf("Silakan input command lain\n");
                    } else if (initMeteor) {
                        if (InfoX(First(snake)) == xMeteor && (InfoY(First(snake))-1) == yMeteor) {
                            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            printf("Silakan masukkan command lainnya\n");
                        } else {
                            (*isValid) = true;
                            printf("Berhasil bergerak ke atas\n");
                        }
                    } else {
                        (*isValid) = true;
                        printf("Berhasil bergerak ke atas\n");
                    }
                } else {
                    (*isValid) = true;
                    printf("Anda berada di posisi teratas\n");
                    printf("Kepala snake akan muncul di posisi terbawah\n");
                }
            } else if (inpt == 'a' || inpt == 'A') {
                if (InfoX(First(snake)) != 0) {
                    if (a != NIL) {
                        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                        printf("Silakan input command lain\n");
                    } else if (initMeteor) {
                        if ((InfoX(First(snake))-1) == xMeteor && InfoY(First(snake)) == yMeteor) {
                            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            printf("Silakan masukkan command lainnya\n");
                        } else {
                            (*isValid) = true;
                            printf("Berhasil bergerak ke kiri\n");
                        }
                    } else {
                        (*isValid) = true;
                        printf("Berhasil bergerak ke kiri\n");
                    }
                } else {
                    (*isValid) = true;
                    printf("Anda berada di posisi terkiri\n");
                    printf("Kepala snake akan muncul di posisi terkanan\n");
                }
            } else if (inpt == 's' || inpt == 'S') {
                if (InfoY(First(snake)) != 4) {
                    if (s != NIL) {
                        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                        printf("Silakan input command lain\n");
                    } else if (initMeteor) {
                        if (InfoX(First(snake)) == xMeteor && (InfoY(First(snake))+1) == yMeteor) {
                            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            printf("Silakan masukkan command lainnya\n");
                        } else {
                            (*isValid) = true;
                            printf("Berhasil bergerak ke bawah\n");
                        }
                    } else {
                        (*isValid) = true;
                        printf("Berhasil bergerak ke bawah\n");
                    }
                } else {
                    (*isValid) = true;
                    printf("Anda berada di posisi terbawah\n");
                    printf("Kepala snake akan muncul di posisi teratas\n");
                }
            } else if (inpt == 'd' || inpt == 'D') {
                if (InfoX(First(snake)) != 4) {
                    if (d != NIL) {
                        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                        printf("Silakan input command lain\n");
                    } else if (initMeteor) {
                        if ((InfoX(First(snake))+1) == xMeteor && InfoY(First(snake)) == yMeteor) {
                            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                            printf("Silakan masukkan command lainnya\n");
                        } else {
                            (*isValid) = true;
                            printf("Berhasil bergerak ke kanan\n");
                        }
                    } else {
                        (*isValid) = true;
                        printf("Berhasil bergerak ke kanan\n");
                    }
                } else {
                    (*isValid) = true;
                    printf("Anda berada di posisi terkanan\n");
                    printf("Kepala snake akan muncul di posisi terkiri\n");
                }
            }
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
        if (InfoY(First(*snake)) < 0) {
            InfoY(First(*snake)) = 4;
        }
    } else if (inpt == 'a' || inpt == 'A') {
        InfoX(First(*snake)) -= 1;
        if (InfoX(First(*snake)) < 0) {
            InfoX(First(*snake)) = 4;
        }
    } else if (inpt == 's' || inpt == 'S') {
        InfoY(First(*snake)) += 1;
        if (InfoY(First(*snake)) > 4) {
            InfoY(First(*snake)) = 0;
        }
    } else if (inpt == 'd' || inpt == 'D') {
        InfoX(First(*snake)) += 1;
        if (InfoX(First(*snake)) > 4) {
            InfoX(First(*snake)) = 0;
        }
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

void addFood(int *xFood, int *yFood, List snake, int xObstacle, int yObstacle) {
    *xFood = rng2(0, 4);
    *yFood = rng2(0, 4);
    while ((SearchList(snake, *xFood, *yFood) != NIL) || ((*xFood == xObstacle) && (*yFood == yObstacle))) {
        *xFood = rng2(0, 4);
        *yFood = rng2(0, 4);
    }
}

boolean isEating(List snake, int xFood, int yFood) {
    int xHead = InfoX(First(snake));
    int yHead = InfoY(First(snake));
    if (xHead == xFood && yHead == yFood) {
        return true;
    } else {
        return false;
    }
}

void eating(List *snake, int xFood, int yFood, boolean *isTailStuck) {
    int tailX = InfoX(Last(*snake));
    int tailY = InfoY(Last(*snake));
    if (tailX > 0 && SearchList(*snake, tailX-1, tailY) == NIL) {
        InsVLast(snake, tailX-1, tailY);
    } else if (tailY > 0 && SearchList(*snake, tailX, tailY-1) == NIL) {
        InsVLast(snake, tailX, tailY-1);
    } else if (SearchList(*snake, tailX, tailY+1) == NIL) {
        InsVLast(snake, tailX, tailY+1);
    } else if (SearchList(*snake, tailX+1, tailY) == NIL) {
        InsVLast(snake, tailX+1, tailY);
    } else {
        *isTailStuck = true;
    }
}

void addMeteor(int *xMeteor, int *yMeteor, int *prevXMeteor, int *prevYMeteor, boolean initMeteor,int xFood, int yFood, int xObstacle, int yObstacle) {
    if (initMeteor) {
        *prevXMeteor = *xMeteor;
        *prevYMeteor = *yMeteor;
    }
    *xMeteor = rng2(0,4);
    *yMeteor = rng2(0,4);
    while (*xMeteor == xObstacle && *yMeteor == yObstacle && *xMeteor == xFood && *yMeteor == yFood) {
        *xMeteor = rng2(0,4);
        *yMeteor = rng2(0,4);
    }
}

void prosesMeteor(List *snake, int xMeteor, int yMeteor, boolean *isMeteorHitHead) {
    addressNode kena = SearchList(*snake, xMeteor, yMeteor);
    if (kena != NIL) {
        printf("Anda terkena meteor!\n");
        if (kena == First(*snake)) {
            (*isMeteorHitHead) = true;
        } else {
            addressNode prev = Prev(kena);
            addressNode Pdel;
            DelAfter(snake, &Pdel, prev);
        }
    } else {
        printf("Anda beruntung tidak terkena meteor! Silakan lanjutkan permainan\n");
    }
}

void addObstacle(List snake, int *xObstacle, int *yObstacle) {
    *xObstacle = rng2(0, 4);
    *yObstacle = rng2(0, 4);
    while (SearchList(snake, *xObstacle, *yObstacle) != NIL) {
        *xObstacle = rng2(0, 4);
        *yObstacle = rng2(0, 4);
    }
}

boolean isLose(List snake, boolean isMeteorHitHead, int xObstacle, int yObstacle, boolean isTailStuck, boolean isHeadStuck) {
    if (isMeteorHitHead) {
        printf("Kepala snake terkena meteor!\n");
        printf("GAME OVER\n");
        return true;
    } else if (listLength(snake) == 0) {
        printf("Seluruh tubuh snake terkena meteor!\n");
        printf("GAME OVER\n");
        return true;
    } else if (InfoX(First(snake)) == xObstacle && InfoY(First(snake)) == yObstacle) {
        printf("Kepala snake terkena obstacle!\n");
        printf("GAME OVER\n");
        return true;
    } else if (isTailStuck) {
        printf("Tail snake menabrak badan!\n");
        printf("GAME OVER\n");
        return true;
    } else if (isHeadStuck) {
        printf("Snake tidak dapat bergerak kemana-mana!\n");
        printf("GAME OVER\n");
        return true;
    } else {
        return false;
    }
    // Belum tambahin kondisi kalah yg kedua
}

int hitungScore(List snake, boolean isMeteorHitHead, boolean isTailStuck) {
    if (isMeteorHitHead) {
        return 2*(listLength(snake)-1);
    } else {
        return 2*listLength(snake);
    }
}

void snake(Map *MapSnake) {
    List snake;
    int xFood;
    int yFood;
    int xMeteor;
    int yMeteor;
    int xObstacle;
    int yObstacle;
    matrixMap peta;
    CreateEmptyList(&snake);
    CreateEmptyMatrixMap(&peta);

    // INISIALISASI RNG
    srand(time(NULL));
    
    // PESAN SELAMAT DATANG
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Mengenerate peta, snake, dan makanan...\n");
    printf("Berhasil digenerate!\n");
    printf("_______________________________________\n");
    
    // INISIALISASI GAME
    int lastX, lastY;
    int prevXMeteor, prevYMeteor;
    boolean isMeteorHitHead = false;
    boolean initMeteor = false;
    boolean isTailStuck = false;
    boolean isHeadStuck = false;
    int nTurn = 1;
    initSnake(&snake);
    addObstacle(snake, &xObstacle, &yObstacle);
    addFood(&xFood, &yFood, snake, xObstacle, yObstacle);
    updateMatrixMap(&peta, snake, lastX, lastY, xFood, yFood, xMeteor, yMeteor, prevXMeteor, prevYMeteor, xObstacle, yObstacle);
    displayMatrixMap(peta);
   
    // PROGRAM UTAMA
    while (isLose(snake, isMeteorHitHead, xObstacle, yObstacle, isTailStuck, isHeadStuck) == false) {
        // TERIMA COMMAND
        char command[50];
        char inpt;
        boolean isValid = false;
        while (!isValid) {
            printf("\n");
            printf("TURN %d:\n", nTurn);
            printf("Silakan masukkan command Anda: ");
            StartCommand();
            if (CurrentCommand.Length == 1) {
                inpt = CurrentCommand.TabWord[0];
                validateCommand(inpt, snake, xMeteor, yMeteor, initMeteor, &isValid, &isHeadStuck);
            } else {
                printf("Command tidak valid! Silakan input command menggunakan huruf w/a/s/d\n");
            }
        }
        nTurn++;

        // PROSES COMMAND
        if (!isHeadStuck) {
            moveSnake(&snake, inpt, &lastX, &lastY);
        }
        if (isEating(snake, xFood, yFood)) {
            eating(&snake, xFood, yFood, &isTailStuck);
            addFood(&xFood, &yFood, snake, xObstacle, yObstacle);
        }
        addMeteor(&xMeteor, &yMeteor, &prevXMeteor, &prevYMeteor, initMeteor, xFood, yFood, xObstacle, yObstacle);
        initMeteor = true;
        prosesMeteor(&snake, xMeteor, yMeteor, &isMeteorHitHead);
        updateMatrixMap(&peta, snake, lastX, lastY, xFood, yFood, xMeteor, yMeteor, prevXMeteor, prevYMeteor, xObstacle, yObstacle);
        displayMatrixMap(peta);

        // HANYA UNTUK TES
        // printf("snake: ");
        // PrintForward(snake);
        // printf("\n");
        // printf("Meteor: ");
        // printf("<%d, %d>\n", xMeteor, yMeteor);
        // printf("Makanan: ");
        // printf("<%d, %d>\n", xFood, yFood);
    }

    // HITUNG SCORE
    int score = hitungScore(snake, isMeteorHitHead, isTailStuck);
    printf("Score Anda: %d\n", score);

    // MASUKKAN NAMA PEMAIN DAN TAMBAH KE MAP
    char player[50];
    char *temp;
    int i;
    printf("\n");
    printf("Masukkan nama pemain: ");
    StartGame();
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