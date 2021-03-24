#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

//Слова для відгадування
char words[WCNT][WLEN] = { "®ЈЄј®°Ґґ", "ЈБ ЇҐ««ґЎЎ", "ЎўЎ¦ЄЄ®ґ", "ЄБ©№Ў°", "«ё¤ЁЩЎ№·ЈЎ",
						 " Ј¤№¬¤»", "®ЈЄ©»Ў§·±Ў©¬¬", "ЈБ©®ҐЈє", "°Ўґ№Ўіёґі", "Уѕ®Є¤°ёЇ¬·Цѕ",
						  "Іў«ЄЇ«Ґ¦ Ј¤¬ѕ»", "®ЅЇШ§Ї»°Б¦Ё", "®ЈЄЇЎіё¦і¬©ѕ", "«БҐЇ» ®Јј¤®Ў" };

PlayStats BestPlay;//зберігання даних про найрезультативнішу гру
PlayStats Play;


int main()
{ 
	BestPlay.LifesUsed = 6;
	system("chcp 1251");
	int answ = 'Y', num = 0;
	while (answ == 'Y') {
		char wordStatus[WLEN] = "_______________";
		GameData Game{};
		WelcomeUser(&Game);
		ChooseWordToGuess(&Game);
		ShowHangman(Game.LivesRemaining);
		clock_t start = SetZero();
		PrintCurrentStatus(wordStatus, &Game);
		while (Game.LivesRemaining > 0 && Game.SuccesGuessed < strlen(Game.WordToGuess)) {
			UpdateCurrentStatus(wordStatus, &Game);
		}
		if (Game.LivesRemaining <= 0) {
			printf("\nНа жаль, ви програли :(\t Загаданим словом було: %s", Game.WordToGuess);
		}
		else {
			printf("\nВітаю!!! Ви виграли, та спасли людину!!!");
		}
		printf("\nСпробувати ще раз? Y/N: ");
		answ = getchar();
		clock_t end = clock();
		Play.SecondsWasted = (double)(end - start)/ CLOCKS_PER_SEC;
		if (Game.LivesRemaining > 0 && GamesComparer(&Play, &BestPlay) > 0) {
			BestPlay = Play;
		}
		num = SuccesfulGames(&Game);
	}
	if (BestPlay.LifesUsed != 6) {
		ShowGeneralData(num);
		getchar();
	}
	getchar();
}

clock_t SetZero() {
	Play.SecondsWasted = 0;
	Play.LifesUsed = 0;
	clock_t start = clock();
	return start;
}

void ShowGeneralData(int cnt)
{
	printf("\n\nВаша найкраща гра це гра №%d", BestPlay.GameNum);
	printf("\nВи потратили %d життів та %d секунд аби вгадати слово",
		BestPlay.LifesUsed, (int)round(BestPlay.SecondsWasted));
	printf("\n\nЗагалом ви відгадали %d слів", cnt);
}

int SuccesfulGames(GameData* Game) {
	static int cnt = 0;
	if (Game->LivesRemaining > 0)
		cnt++;
	return cnt;
}