#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arraydinamis/arraydin.h"
#include "ADT/queue/queue.h"


boolean compareWord(Kata kata1, char *kata2);

int wordtoInt (Kata Word);

void wordtoString(Kata CurrentWord, char *string);

void STARTBNMO(ArrayDin *GameBNMO);

void LOADBNMO(ArrayDin *GameBNMO, char *filename);

void SAVE(ArrayDin *GameBNMO, char *filename);

void CREATEGAME (ArrayDin *GameBNMO);

void LISTGAME(ArrayDin GameBNMO);

void DELETEGAME (ArrayDin *GameBNMO, Queue Q);

void PLAYGAME (Queue QueueBNMO);

void COMMANDLAIN ();

void HELP();

void QUIT();
