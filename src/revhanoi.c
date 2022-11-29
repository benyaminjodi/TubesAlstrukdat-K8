
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "revhanoi.h"

void TowerOfHanoi(Map* MapTowerOfHanoi){
    int score;
    do{
        reset();
        menu();
        createTower();

        while (checkCondition()){
            draw();

            while (isEmpty(asal = fromAsal())){
                draw();
                printf("Tiang yang dipilih masih kosong.\n");
            }
            printf("\n");
        
            while (validitas(asal,tujuan = toTujuan())){
                draw();
                printf("Piringan hanya bisa diletakkan diatas piringan yang lebih besar.\n\n");
                printf("Kamu telah memilih tiang %d.\n", asal);

            }
            moved(asal, tujuan);
        }
        draw();
        printf("Kamu berhasil!\n");
        int min = (int)pow(2,tinggi) -1;
        score = 100 - moves;
        if(min < moves){
            printf("Skor yang didapatkan sebesar %d.\n", score);
        }
        else{
            printf("Kamu mendapatkan score sebesar 100!\n");
        }
    }while (replay());

    char *temp;
    char player[50];
    //printf("Skor anda adalah %d\n", score);  
    printf("Player Name: ");
    StartGame();
    wordtoString(CurrentCommand, player);
    temp = (char *) malloc (CurrentCommand.Length * sizeof(char));
    int p = 0;
    while (p <= CurrentCommand.Length)
    {
        temp[p] = player[p];
        
        p += 1;
    }
    InsertMap(MapTowerOfHanoi, temp, score);
}

void menu(){ //udah bener
    printf("Masukkan ketinggian tower (max 19) ");
	//scanf("%d", &tinggi);

	StartCommand();
    tinggi = wordtoInt(CurrentCommand);

	while (tinggi < 1 || tinggi > 20){
		printf("Masukkan ketinggian tower(max 19): ");
		StartCommand();
    	tinggi = wordtoInt(CurrentCommand);
	}

}

void createTower(){
    A = (int*)malloc(tinggi * sizeof(int));
	B = (int*)malloc(tinggi * sizeof(int));
	C = (int*)malloc(tinggi * sizeof(int));
	win = (int*)malloc(tinggi * sizeof(int));

    int i,h;

	for (h = tinggi, i = 0; h > 0; h--, i++) {
		A[i] = h;
		win[i] = h;
		
		B[i] = 0;
		C[i] = 0;
	}
}

int replay(){ //udah bener
    return 0;
}

void reset(){
    A = NULL;
    B = NULL;
    C = NULL;
    win = NULL;
    tinggi = 0;
    asal = 0;
    tujuan = 0;
    moves = 0;
    wrong = 0;
}

void moved (int asal, int tujuan){
    int* arrAsal = getArray(asal);
    int* arrTujuan = getArray(tujuan);
    int nilai = Pop(arrAsal);
    Push(arrTujuan, nilai);
    if (asal != tujuan){
        moves++;
    }
}

void drawSymbol(int code, int amount){
    char c = code;
    for (int i = 0; i < amount; i++){
        printf("%c", c);
    }
}

void drawRows(int value){
    int centerer = 0;
	int block_amount = 0;

	if (value == 0) {
		drawSymbol(BACK, 19);
		drawSymbol(TIANG, 2);
		drawSymbol(BACK, 19);
	}
	else if (value >= 0) {
		if (value == tinggi) {
			block_amount = 38;
		}
		else {
			int add = 38 / tinggi;
			block_amount = value * add;
			if (block_amount % 2 != 0) {
				block_amount++;
			}
		}
		
		centerer = (40 - block_amount) / 2;

		drawSymbol(BACK, centerer);

		if (!wrong) {
			drawSymbol(DISK, block_amount);
		}
		else {
			int separated_block_amount = (block_amount - 2) / 2;

			drawSymbol(DISK, separated_block_amount);
			if (value < 10) {
				printf("0");
				printf("%d", value);
			}
			else {
				printf("%d", value);
			}
			drawSymbol(DISK, separated_block_amount);
		}
		drawSymbol(BACK, centerer);
	}
	else if (value == PCK) {
		drawSymbol(BACK, 19);
		drawSymbol(TIANG, 2);
		drawSymbol(BACK, 19);
		drawSymbol(BACK, 19);
		drawSymbol(TIANG, 2);
		drawSymbol(BACK, 19);
		drawSymbol(BACK, 19);
		drawSymbol(TIANG, 2);
		drawSymbol(BACK, 19);
	}
	else if (value == LANTAI) {
		drawSymbol(ALAS, 120);
	}
	else if (value == BG) {
		drawSymbol(BACK, 120);
	}
	else if (value == LABELS) {
		drawSymbol(DISK, 9);

		drawSymbol(TIANG, 5);
		drawSymbol(BACK, 3);
		drawSymbol(KSG, 1);
		printf("  1  ");
		drawSymbol(KSG, 1);
		drawSymbol(BACK, 3);
		drawSymbol(TIANG, 5);

		drawSymbol(DISK, 17);

		drawSymbol(TIANG, 5);
		drawSymbol(BACK, 3);
		drawSymbol(KSG, 1);
		printf("  2  ");
		drawSymbol(KSG, 1);
		drawSymbol(BACK, 3);
		drawSymbol(TIANG, 5);

		drawSymbol(DISK, 17);

		drawSymbol(TIANG, 5);
		drawSymbol(BACK, 3);
		drawSymbol(KSG, 1);
		printf("  3  ");
		drawSymbol(KSG, 1);
		drawSymbol(BACK, 3);
		drawSymbol(TIANG, 5);

		drawSymbol(DISK, 8);
	}
	else if (value == LABELS) {
		drawSymbol(DISK, 18);
		printf("Row 1");
		drawSymbol(DISK, 35);
		printf("Row 2");
		drawSymbol(DISK, 35);
		printf("Row 3");
		drawSymbol(DISK, 17);
	}
}

void draw(){
    drawRows(BG);
    drawRows(PCK);
    for (int h = tinggi -1; h >=0; h--){
        for(int i = 0; i < 1; i++){
            drawRows(A[h]);
            drawRows(B[h]);
            drawRows(C[h]);
        }
    }
    drawRows(LANTAI);
    drawRows(LABELS);
    drawRows(LANTAI);
    printf("\n\n");

}

int* getArray(int index){
    switch (index)
	{
	case 1:
		return A;
	case 2:
		return B;
	case 3:
		return C;
	default:
		break;
	}
	return NULL;
}

int fromAsal(){
	printf("TIANG ASAL: ");
	int choice;

	//scanf("%d", &choice);

	StartCommand();
    choice = wordtoInt(CurrentCommand);
	while (choice <1||choice>3){
		printf("TIANG ASAL: ");
		StartCommand();
    	choice = wordtoInt(CurrentCommand);
	}

	return choice;
}

int toTujuan(){
	printf("TIANG TUJUAN: ");
	int choice;

	StartCommand();
    choice = wordtoInt(CurrentCommand);
	while (choice <1||choice>3){
		printf("TIANG TUJUAN: ");
		StartCommand();
    	choice = wordtoInt(CurrentCommand);
	}

	return choice;
}

int isEmpty(int index){
    int* arr = getArray(index);
    for (int i = 0; i < tinggi; i++){
        if (arr[i] > 0){
            return 0;
        }
    }
}

int validitas(int asal, int tujuan){
	if (asal == tujuan) {
		return 0;
	}

	int* arrAsal = getArray(asal);
	int* arrTujuan = getArray(tujuan);
	int nilaiAsal, nilaiTujuan;

	nilaiAsal = getTop(arrAsal);
	nilaiTujuan = getTop(arrTujuan);

	if (nilaiAsal < nilaiTujuan) {
		wrong = 0;
		return 0;
	}
	else {
		wrong = 1;
		return 1;
	}
}

int getTop(int* t){
	int index;
	for (int i = 1; i <= tinggi; i++) {
		index = tinggi - i;
		if (t[index] == 0) {
			continue;
		}
		else {
			return t[index];
		}
	}
	return tinggi+1;
}

int Pop(int* t){
	int index;
	int nilai = 0;
	for (int i = 1; i <= tinggi; i++) {
		index = tinggi - i;
		int getted = t[index];
		if (getted == 0) {
			continue;
		}
		else {
			nilai = t[index];
			t[index] = 0;
			return nilai;
		}
	}
	return nilai;
}

void Push(int* t, int value){
	for (int i = 0; i < tinggi; i++) {
		if (t[i] == 0) {
			t[i] = value;
			break;
		}
	}
}

int checkCondition(){
	int success = 0;
	for (int i = 0; i < tinggi; i++) {
		if (C[i] == win[i]) {
			success += 1;
		}
	}

	if (success == tinggi) {
		return 0;
	}

	return 1;
}
