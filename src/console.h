#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arraydinamis/arraydin.h"
#include "ADT/queue/queue.h"
#include "ADT/queue/queueDD.h"
#include "ADT/map/map.h"
#include "ADT/stack/stack.h"


boolean compareWord(Kata kata1, char *kata2);

boolean compareString(char *kata1, char *kata2);

void concat(char *s1, char *s2, char *soutput);

int wordtoInt (Kata Word);

void wordtoString(Kata CurrentWord, char *string);

void STARTBNMO(ArrayDin *GameBNMO);

void LOADBNMO(ArrayDin *GameBNMO, char* filename, Stack *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe);

void SAVEBNMO(ArrayDin *GameBNMO, char* filename, Stack *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe);

void CREATEGAME (ArrayDin *GameBNMO);

void QUEUEGAME (Queue *QueueBNMO, ArrayDin GameList);

void LISTGAME(ArrayDin GameBNMO);

void DELETEGAME (ArrayDin *GameBNMO, Queue Q);

void PLAYGAME(Queue *QueueBNMO, Stack *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe);

void SKIPGAME(Queue *QueueBNMO, int n, Stack *HistoryBNMO, Map *MapRNG, Map *MapDD, Map *MapHangman, Map *MapTower, Map *MapSnake, Map *MapTicTacToe);

void SCOREBOARD(Map RNG, Map MapDD, Map MapHangman, Map MapTower, Map MapSnake, Map MapTicTacToe);

void RESETSCOREBOARD(Map *MapRNG , Map *MapDD , Map *MapHangman , Map *MapTower , Map *MapSnake , Map *MapTicTacToe);

void HISTORY(Stack HistoryBNMO, int n);

void RESETHISTORY(Stack *HistoryBNMO);

void COMMANDLAIN ();

void RNG();

void HELP();

void QUIT();
