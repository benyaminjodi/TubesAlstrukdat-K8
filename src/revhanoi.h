#define KSG 32
#define BACK 32
#define TIANG 177
#define DISK 178
#define ALAS 220

#define PCK -1
#define LANTAI -2
#define BG -3
#define LABELS -4

int* A;
int* B;
int* C;
int* win;
int tinggi = 0, moves =0, asal, tujuan, wrong=0;

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
int isEmpty(int index);
int validitas(int asal, int tujuan);
int getTop(int* t);
int Pop(int* t);
void Push(int* t, int value);
int checkCondition();

int*getArray(int index);
