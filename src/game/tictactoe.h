#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/map/map.h"
#include "../boolean.h"
#include "../console.h"



void printBoard();
void createBoard();
int freeSpaceRemains();
void player1move();
void player2move();
char checkWinner();
void printWinner(char);
void scoreboard(char winner, Map *MapTicTacToe );
void tictactoe(Map *MapTicTacToe);

#endif