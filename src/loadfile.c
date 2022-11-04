#include <stdio.h>
#include <stdlib.h> // For exit()
#include "mesinkata.h"

void loadfile()
{
	FILE *fptr1, *fptr2;
	char filename[100], c;

	printf("Enter the save file name \n");
	scanf("%s", filename);

	// Open one file for reading
	fptr1 = fopen(filename, "r");
	while (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		printf("Enter the save file name \n");
		scanf("%s", filename);
		fptr1 = fopen(filename, "r");
	}

	fptr2 = fopen("config.txt", "w");

	// Copy contents from file
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}

	printf("\nSave file successfully loaded!");

	fclose(fptr1);
	fclose(fptr2);
}

