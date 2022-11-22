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
// F.S. Mengisi peta dengan angka 0