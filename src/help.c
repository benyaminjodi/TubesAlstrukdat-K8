#include "help.h"
#include <stdio.h>
#include <stdlib.h>

void help() {
    printf("DAFTAR COMMAND \n");
    printf("\n");
    printf("START       : memulai permainan BNMO dan menampilkan list game yang dapat dimainkan\n");
    printf("LOAD        : membuka file yang berisi game yang dapat dimainkan dan histori bermain\n");
    printf("SAVE        : menyimpan nama file yang akan disimpan di disk\n");
    printf("CREATEGAME  : menampilkan daftar game yang disediakan oleh sistem\n ");
    printf("DELETEGAME  : menghapus sebuah game dari daftar game tanpa menghapus 5 game awal pada konfigurasi atau yang sedang diqueue\n");
    printf("QUEUEGAME   : menambahkan permainan ke list game yang akan dimainkan\n");
    printf("PLAYGAME    : memainkan game yang ada di list game yang akan dimainkan\n");
    printf("SKIPGAME    : melewati permainan ke-n\n");
    printf("QUIT        : keluar dari permainan\n");
    printf("HELP        : menampilkan daftar-daftar command\n");
    
}   