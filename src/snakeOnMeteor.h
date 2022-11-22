#include <stdio.h>
#include <time.h>
#include "boolean.h"
#include "ADT/linkedlist/linkList.h"
#include "ADT/mesinkata/mesinkata.h"
#include "console.h"

typedef struct {
    char buffer[5][5];
} matrixMap;

void CreateEmptyMatrixMap(matrixMap *peta);
// I.S. peta terdefinisi 
// F.S. Mengisi peta dengan char 0

void displayMatrixMap(matrixMap peta);

void updateMatrixMap(matrixMap *peta, List snake, List makanan, List meteor, int lastX, int lastY, int xDelMeteor, int yDelMeteor);

int listLength(List list);

int rng2(int lower, int upper);

void initSnake(List *snake);

void validateCommand(char inpt, List snake, List meteor, boolean *isValid);

void moveSnake(List *snake, char inpt, int *lastX, int *lastY);

void addMakanan(List *makanan, List snake);

boolean isMakan(List snake, List makanan);

void prosesMakan(List *snake, List *makanan);

void addMeteor(List *meteor, List makanan);

void delMeteor(List *meteor, int *xDelMeteor, int *yDelMeteor);

boolean prosesMeteor(List *snake, List meteor, boolean *isMeteorHitHead);

boolean isLose(List snake, boolean isMeteorHitHead);

int hitungScore(List snake, boolean isMeteorHitHead);

void snake(Map *MapSnake);