#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
#include "tictactoe.h"


const char char1 = 'X', char2 = 'O';
char board[3][3];

void tictactoe(Map *MapTicTacToe){
    
    //int score1,score2;
    //const char char1 = 'X', char2 = 'Y';

    char winner;
    char response = ' ';

    winner =' ';
    response =' ';
    createBoard();

    while(winner == ' ' && freeSpaceRemains() != 0){
        printBoard();

        player1move();
        winner = checkWinner();
        if(winner != ' ' || freeSpaceRemains() == 0){
            break;
        }

        player2move();
        winner = checkWinner();
        if(winner != ' ' || freeSpaceRemains()==0){
            break;
        }
    }

    printBoard();
    printWinner(winner);
    scoreboard(winner, MapTicTacToe);

    printf("Bye");
    
}

void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---+---+---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---+---+---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

void createBoard(){
    //int i,j;
    for (int i=0; i < 3; i++){
        for(int j = 0; j<3;j++ ){
            board[i][j] = ' ';
        }
    }
}

int freeSpaceRemains(){
    int i, j, free=9;
    for(i = 0; i < 3; i++){
        for(j = 0; j< 3; j++){
            if(board[i][j] != ' '){
                free = free-1;
            }
        }
    }
    return free;
}

void player1move(){
    int x;
    int y;

    do{
        printf("<Pemain 1> Enter row (1-3): ");

        StartCommand();
        x = wordtoInt(CurrentCommand);
        //StartCommand();
       // wordtoInt(CurrentCommand, x);
        x--;
        printf("<Pemain 1> Enter column (1-3): ");
        StartCommand();
        y= wordtoInt(CurrentCommand);
        y--;
        //StartCommand();
        //wordtoInt(CurrentCommand, y);
        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        }
        else{
            board[x][y] = char1;
            break;
        }
        } while (board[x][y] != ' ');
   
}
void player2move(){
    int x;
    int y;

    do{
        printf("<Pemain 2> Enter row (1-3): ");
        StartCommand();
        x = wordtoInt(CurrentCommand);
        x--;
        printf("<Pemain 2> Enter column (1-3): ");
        StartCommand();
        y= wordtoInt(CurrentCommand);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        }
        else{
            board[x][y] = char2;
            break;
        }
        } while (board[x][y] != ' ');
   
}

char checkWinner(){
    //check rows
   for(int i = 0; i < 3; i++){
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++){
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
      return board[0][2];
   }

   return ' ';
}

void printWinner(char winner){
   if(winner == char1){
      printf("Winner: Player 1\n");
   }
   else if(winner == char2){
      printf("Winner: Player 2\n");
   }
   else{
      printf("Tie\n");
   }
}

void scoreboard(char winner, Map *MapTicTacToe )
{
    char player1[50];
    char player2[50];
    char *temp;
    char *temp2;
    int i;
    int score1 = 0, score2 = 0, tie = 0;
    if (winner == char1){
        score1 += 10;
    }
    else if (winner == char2){
        score2 += 10;
    }
    else{
        tie++;
    }
    printf("Player 1 score: ");
    printf("%d\n", score1);
    printf("Player 2 score: ");
    printf("%d\n", score2);
    printf("Match tied: ");
    printf("%d\n", tie);

    printf("Player 1 Name: ");
    StartGame();
    wordtoString(CurrentCommand, player1);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    i = 0;
    while (i <= CurrentCommand.Length)
    {
        temp[i] = player1[i];
        
        i += 1;
    }
    InsertMap(MapTicTacToe, temp, score1);
    printf("Player 2 Name: ");
    StartGame();
    wordtoString(CurrentCommand, player2);
    temp2 = (char *) malloc (CurrentCommand.Length * sizeof(char));
    i = 0;
    while (i <= CurrentCommand.Length)
    {
        temp2[i] = player2[i];
        
        i += 1;
    }
    InsertMap(MapTicTacToe, temp2, score2);
    printf("\n");
}
