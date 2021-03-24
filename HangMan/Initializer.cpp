#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern PlayStats Play;

void SetLevel(GameData* Game)
{
	int lvl;
	printf("\n\n\nОберіть рівень складності:");
	printf("\n\nНатисніть 1, аби обрати >>простий рівень<<");
	printf("\nНатисніть 2, аби обрати >>середній рівень<<");
	printf("\nНатисніть 3, аби обрати >>складний рівень<<\n\n\t\t\tрівень:\t");
	scanf("%d", &lvl);
	if (lvl == 1) {
		printf("\n\n\t Ви обрали простий рівень!");
		Game->LivesRemaining = 5;
	}
	else if (lvl == 2) {
		printf("\n\n\t Ви обрали середній рівень!");
		Game->LivesRemaining = 3;
	}
	else {
		printf("\n\n\t Ви обрали складний рівень!");
		Game->LivesRemaining = 1;
	}
	getchar();
}

void WelcomeUser(GameData* Game)
{
	Play.GameNum++;
	system("cls");
	printf("\n\n\t !!!!!!!!!Вітаю у грі HANGMAN !!!!!!!!!!");
	SetLevel(Game);
	printf("\n\n\t Отож, поможіть чоловіку. ПОООЇХАЛИ!!");
	printf("\n\n\t Натисніть >>Enter<< щоб почати гру");
	getchar();
}

void ChooseWordToGuess(GameData* Game)
{
	char not_key[] = "asdjkakdsadasdj";
	extern char words[][WLEN];
	for (int i = 0; i < WCNT; i++) {
		if (Play.GameNum == 1)
			decrypt(not_key, words[i]);
	}
	srand(time(NULL));
	strcpy(Game->WordToGuess, words[rand() % WCNT]);
}