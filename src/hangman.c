#include <stdio.h>
#include "hangman.h"
#include "ADT/arraydinamis/arraydin.h"
#include "boolean.h"

void HANGMAN ()
{
    //buat list kataTebakan
    ArrayDin KataTebakan;
    KataTebakan = MakeArrayDin();

    InsertLast(&KataTebakan, "BAJU");
    InsertLast(&KataTebakan, "MOBIL");
    InsertLast(&KataTebakan, "ALSTRUKDAT");
    InsertLast(&KataTebakan, "KUCING");
    InsertLast(&KataTebakan, "BOROBUDUR");

    srand(time(NULL));
    int r = rand()%4;
   
    char KataDitebak;
    char sebelumnya;
    KataDitebak = KataTebakan.A[r];
    char sebelumnya;
    sebelumnya = "-";

    int Length(KataDitebak);
    int kesempatan = 10;
    if (kesempatan = 10)
    {
        // Screen = [_,_,_,_]
        // print KataTebakan :
        // Screen = KataTebakan 
        //Panjangnya length
        // int i = 0
        for (int i=0; i <= Length(KataDitebak); i++)
        {
            printf("_ ");
        }
        printf("Kesempatan :  %d ", kesempatan); 
    }
    boolean berhasil = 0;
    while ((kesempatan > 0) && (berhasil == 0) )
    {
        //BAJU
        //print tebakan sebelumnu printf variabel sebelumnya
        int i;
        char screen[i];
        for (i = 0; i <= Length(KataDitebak); i++)
        printf("Kata : %s ", screen[i]); //kataTebakan : disini dia nge print screen, misal kalo udah keiisi A jadi _ A _ _
        printf("Kesempatan :  %d ", kesempatan); 
        printf("Masukkan tebakan : ");
        StartCommand();
        char KataDitebak;
        //saat kita input B

        for (int i = 0; i<= Length(KataDitebak); i++)
        {
            int i;
            if (compareWord(CurrentCommand, Length(KataDitebak)) == true)
            {
                screen[i] =  CurrentCommand.TabWord;
            }
        //BAJU
        //B A _ _
        
        sebelumnya = wordtoString(CurrentCommand); 
        if (KataTebakan.A[r] == screen)
        {
            berhasil = 1;
        }

        }
        // yang dibandingkan ada ga huruf yang = yg ada di KataTebakan sama kayak inputan user dari command
        // kalau ada Screen [idx] yang sesuai diubah
        kesempatan--;
    } 
    if (berhasil)
    {
        printf("Skor kamu adalah : %d ", Length(KataDitebak));
    }

    printf("Skor kamu adalah : %d ", Length(KataDitebak));

}