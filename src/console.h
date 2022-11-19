#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arraydinamis/arraydin.h"
#include "ADT/queue/queue.h"
#include "ADT/map/map.h"
#include "ADT/queue/queueDD.h"



boolean compareWord(Kata kata1, char *kata2);

void concat(char *s1, char *s2, char *soutput);

int wordtoInt (Kata Word);

void wordtoString(Kata CurrentWord, char *string);

void STARTBNMO(ArrayDin *GameBNMO);

void LOADBNMO(ArrayDin *GameBNMO, char *filename, ArrayDin *HistoryBNMO, Map *MapSBRNG, Map *MapSBDD, Map *MapSBHANGMAN, Map *MapSBToH, Map *MapSBSoM, Map *MapSBTICTACTOE);

void SAVE(ArrayDin *GameBNMO, char *filename, ArrayDin *HistoryBNMO, Map *MapSBRNG, Map *MapSBDD, Map *MapSBHANGMAN, Map *MapSBToH, Map *MapSBSoM, Map *MapSBTICTACTOE);

void CREATEGAME (ArrayDin *GameBNMO);

void QUEUEGAME (Queue *QueueBNMO, ArrayDin GameList);

void LISTGAME(ArrayDin GameBNMO);

void DELETEGAME (ArrayDin *GameBNMO, Queue Q);

void PLAYGAME(Queue *QueueBNMO, ArrayDin *HistoryBNMO);

void SKIPGAME(Queue *QueueBNMO, int n, ArrayDin *HistoryBNMO);

void COMMANDLAIN ();

void RNG();

void HELP();

void QUIT();
