#include <stdio.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/linkedlist/linkList.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../console.h"

typedef struct {
    char buffer[5][5];
} matrixMap;

void CreateEmptyMatrixMap(matrixMap *peta);
// I.S. peta terdefinisi 
// F.S. Membuat peta kosong. Peta kosong berisikan character 0

void displayMatrixMap(matrixMap peta);
// I.S. peta terdefinisi
// F.S. Menampilkan peta

void updateMatrixMap(matrixMap *peta, List snake, int lastX, int lastY, int xFood, int yFood, int xMeteor, int yMeteor, int prevXMeteor, int prevYMeteor, int xObstacle, int yObstacle);
// I.S. peta, snake, lastX, lastY, xFood, yFood, xMeteor, yMeteor, prevXMeteor, prevYMeteor, xObstacle, dan yObstacle terdefinisi 
// Mengupdate peta sesuai dengan lokasi snake, food, meteor, dan obstacle

int listLength(List list);
// Mengambalikan panjang dari sebuah list

int rng2(int lower, int upper);
// Menghasilkan bilangan random antara [lower..upper]

void initSnake(List *snake);
// I.S. snake terdefinisi 
// F.S. menginisialisasi snake saat game dijalankan

void validateCommand(char inpt, List snake, int xMeteor, int yMeteor, boolean initMeteor, boolean *isValid, boolean *isHeadStuck);
// I.S. semua variable input dan output terdefinisi 
// F.S. memvalidasi command yang yang diinput

void moveSnake(List *snake, char inpt, int *lastX, int *lastY);
// I.S. snake, inpt, lastX, dan lastY terdefinisi 
// F.S. snake bergerak sesuai input

void addFood(int *xFood, int *yFood, List snake, int xObstacle, int yObstacle);
// I.S. xFood, yFood, snake, xObstacle, yObstacle terdefinisi
// F.S. memberikan nilai kepada xFood dan yFood

boolean isEating(List snake, int xFood, int yFood);
// Mengembalikan nilai true jika kepala snake berada di koordinat xFood dan yFood (snake berhasil makan)

void eating(List *snake, int xFood, int yFood, boolean *isTailStuck);
// I.S. snake, xFood, yFood, dan isTailStuck terdefinisi 
// F.S. menambahkan ekor baru di akhir snake jika masih ada tempat

void addMeteor(int *xMeteor, int *yMeteor, int *prevXMeteor, int *prevYMeteor, boolean initMeteor, int xFood, int yFood, int xObstacle, int yObstacle);
// I.S. semua variable input dan output terdefinisi 
// F.S. memberikan nilai pada xMeteor dan yMeteor

void prosesMeteor(List *snake, int xMeteor, int yMeteor, boolean *isMeteorHitHead);
// I.S. snake, xMeteor, yMeteor, dan isMeteorHitHead terdefinisi
// F.S. Jika terkena, tubuh snake dikurangi 1 panjangnya. Jika meteor mengenai kepala, boolean isMeteorHitHead bernilai true.

void addObstacle(List snake, int *xObstacle, int *yObstacle);
// I.S. snake, xObstacle, yObstacle terdefinisi 
// F.S. Menambahkan obstacle yang tidak bisa dilewati oleh snake

boolean isLose(List snake, boolean isMeteorHitHead, int xObstacle, int yObstacle, boolean isTailStuck, boolean isHeadStuck);
// Mengembalikan nilai true jika salah satu kondisi kalah terpenuhi 

int hitungScore(List snake, boolean isMeteorHitHead, boolean isTailStuck);
// Menghitung score berdasarkan kondisi kalah

void snake(Map *MapSnake);
// Program utama