#include<stdio.h>
#include<stdlib.h>
#include "mesinkata.h"


int main()
{
    char string[50];
    char *temp;
    int i;
    StartWord("./data/test_mesinkata.txt");
    int x = 0;
    while (x<6)//terdapat 6 line yang ingin di print
    {
        int j = 0;

        for (j=0;j < CurrentWord.Length; j++ )
        {
            string[j] = CurrentWord.TabWord[j];
        }
        string[j] = '\0';


        temp = (char *) malloc (CurrentWord.Length * sizeof(char));
        i = 0;
        while (i <= CurrentWord.Length)
        {
            temp[i] = string[i];
            
            i += 1;
        }
        printf("%s\n", temp);
        ADVWord();
        x++;
    }
    printf("\n");
    printf("Uji Coba StartCommand() dan CopyCommand(). Setiap kata akan dipisah\n");
    printf("Ketikkan inputan : ");
    StartCommand();
    printf("Berikut kata dalam inputan\n");
    printf("%s\n", CurrentCommand);
    while(CC != ENTER)
    {
        ADVCommand();
        printf("%s\n", CurrentCommand);  
    }

    printf("\n");
    printf("Uji Coba StartGame() dan CopyGame(). 1 baris akan dianggap menjadi 1 kata\n");
    printf("Ketikkan inputan : ");
    StartGame();
    printf("Berikut kata dalam inputan : ");
    printf("%s\n", CurrentCommand);  

    printf("\n");
    printf("Uji Coba Selesai.");
}