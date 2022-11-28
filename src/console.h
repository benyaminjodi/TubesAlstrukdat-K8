#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arraydinamis/arraydin.h"
#include "ADT/queue/queue.h"
#include "ADT/queue/queueDD.h"
#include "ADT/map/map.h"
#include "ADT/stack/stack.h"
#include "ADT/arrayofmap/arrayofmap.h"

void Lowerstring(char *string);

void Upperstring(char *string);

boolean compareWord(Kata kata1, char *kata2);

boolean compareString(char *kata1, char *kata2);

void concat(char *s1, char *s2, char *soutput);

int wordtoInt (Kata Word);

void wordtoString(Kata CurrentWord, char *string);

void STARTBNMO(ArrayDin *GameBNMO, ArrayMap *ScoreBoard);

void LOADBNMO(ArrayDin *GameBNMO, char* filename,Stack *HistoryBNMO, ArrayMap *ScoreBoard);

void SAVEBNMO(ArrayDin *GameBNMO, char* filename, Stack *HistoryBNMO, ArrayMap *ScoreBoard);

void CREATEGAME (ArrayDin *GameBNMO, ArrayMap *ScoreBoard);

void QUEUEGAME (Queue *QueueBNMO, ArrayDin GameList);

void LISTGAME(ArrayDin GameBNMO);

void DELETEGAME (ArrayDin *GameBNMO, Queue Q, ArrayMap *ScoreBoard);

void PLAYGAME(Queue *QueueBNMO, Stack *HistoryBNMO, ArrayMap *ScoreBoard, ArrayDin *GameBNMO);

void SKIPGAME(Queue *QueueBNMO, int n, Stack *HistoryBNMO, ArrayMap *ScoreBoard, ArrayDin *GameBNMO);

void SCOREBOARD(ArrayMap ScoreBoard, ArrayDin GameBNMO);

void RESETSCOREBOARD(ArrayMap *ScoreBoard ,ArrayDin *GameBNMO);

void HISTORY(Stack HistoryBNMO, int n);

void RESETHISTORY(Stack *HistoryBNMO);

void COMMANDLAIN ();

void RNG(Map *MapRNG);

void HELP();

void QUIT();
