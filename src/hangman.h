#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"


void HangmanFile(ArrayDin *ListHangman);

void Before(Queue *Q);

void Lowerstring(char *string);

void Upperstring(char *string);

void PrintKata(char *guess);

boolean isInQueue(Queue QueueBefore, char *temp);

void HANGMAN(Map *MapHangman);

void PlayHangman(Map *MapHangman);

void AddKataHangman();



