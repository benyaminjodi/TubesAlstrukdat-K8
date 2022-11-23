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

void displayMatrixMap(matrixMap peta);

void updateMatrixMap(matrixMap *peta, List snake, int lastX, int lastY, int xFood, int yFood, int xMeteor, int yMeteor, int prevXMeteor, int prevYMeteor);

int listLength(List list);

int rng2(int lower, int upper);
// Menghasilkan bilangan random antara [lower..upper]

void initSnake(List *snake);

void validateCommand(char inpt, List snake, int xMeteor, int yMeteor, boolean initMeteor, boolean *isValid);

void moveSnake(List *snake, char inpt, int *lastX, int *lastY);

void addFood(int *xFood, int *yFood, List snake);

boolean isEating(List snake, int xFood, int yFood);

void eating(List *snake, int xFood, int yFood);

void addMeteor(int *xMeteor, int *yMeteor, int *prevXMeteor, int *prevYMeteor, boolean initMeteor);

void prosesMeteor(List *snake, int xMeteor, int yMeteor, boolean *isMeteorHitHead);

boolean isLose(List snake, boolean isMeteorHitHead);

int hitungScore(List snake, boolean isMeteorHitHead);

void snake(Map *MapSnake);