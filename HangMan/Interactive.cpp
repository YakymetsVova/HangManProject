#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <Windows.h>

extern PlayStats Play;

void UpdateCurrentStatus(char wordStatus[], GameData* Game)
{
	printf("\rВведіть можливу букву із слова: ");
	char letter;
	scanf("%c", &letter);
	char* ptr = Game->WordToGuess;
	int check = 0;
	while (*ptr != '\0') {
		if ((*ptr == letter || *ptr == (letter ^ 32) || isMatch(letter, *ptr))
			&& Game->Checked[ptr - Game->WordToGuess] == 0) {
			Game->Checked[ptr - Game->WordToGuess] = 1;
			wordStatus[ptr - Game->WordToGuess] = letter;
			check += 1;
		}
		ptr++;
	}
	if (check == 0) {
		printf("Невірна відповідь :(");
		Play.LifesUsed++;
		Sleep(1500);
		rewind(stdin);
		ShowHangman(--Game->LivesRemaining);
		PrintCurrentStatus(wordStatus, Game);
	}
	else
	{
		Game->SuccesGuessed += check;
		printf("Правильно :)");
		Sleep(1500);
		rewind(stdin);
		ShowHangman(Game->LivesRemaining);
		PrintCurrentStatus(wordStatus, Game);
	}
}

void PrintCurrentStatus(char wordStatus[], GameData* Game)
{
	printf("\n\n\t\t\tУ вас залишилось %d життів", Game->LivesRemaining);
	int length = strlen(Game->WordToGuess);
	printf("\n\nСлово має %d літер:\t", length);

	for (int i = 0; i < length; i++) {
		printf("%c ", wordStatus[i]);
	}
	printf("\n");
}