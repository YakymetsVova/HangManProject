#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

void ShowHangman(int lives)
{

	switch (lives)
	{
	case 0:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||   / %c", '\\');
		printf("\n\t||      ");
		break;
	case 1:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||     %c", '\\');
		printf("\n\t||      ");
		break;
	case 2:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 3:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 4:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO ", '\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 5:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||    O ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	}
}