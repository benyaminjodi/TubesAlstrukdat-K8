#include "../boolean.h"
#include "../console.h"
#include "../ADT/map/map.h"
#define KSG 32
#define BACK 32
#define TIANG 177
#define DISK 178
#define ALAS 220

#define PCK -1
#define LANTAI -2
#define BG -3
#define LABELS -4

void menu();
void createTower();
void reset();
//void freeBufer();
void moved(int asal, int tujuan);
void drawSymbol(int code, int amount);
void drawRows(int value);
void draw();

int replay();
int fromAsal();
int toTujuan();
int isEmptyHanoi(int index);
int validitas(int asal, int tujuan);
int getTop(int* t);
int PopHanoi(int* t);
void PushHanoi(int* t, int value);
int checkCondition();
void TowerOfHanoi(Map* MapTowerOfHanoi);

int*getArray(int index);
