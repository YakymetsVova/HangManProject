//#pragma once - працює лише в студії
#ifndef HEADER_H
#define HEADER_H
#include <time.h>
#define WLEN 16
#define WCNT 14

typedef struct PlayStatistics{
	int LifesUsed;
	double SecondsWasted;
	int GameNum = 0;
} PlayStats;

typedef struct {
	int LivesRemaining;
	int Checked[WLEN];
	int SuccesGuessed;
	char WordToGuess[WLEN];
} GameData;

void ShowGeneralData(int); // int - words cnt
int GamesComparer(PlayStats*, PlayStats*);
void WelcomeUser(GameData*);
void ChooseWordToGuess(GameData*);
void ShowHangman(int);//int - lives remaining
void PrintCurrentStatus(char[], GameData*); // char[] - word status
void UpdateCurrentStatus(char[], GameData*);
void SetLevel(GameData*);
void decrypt(char*, char*); // 1 - key, 2 - word
int isMatch(int, int); // 1-input letter, 2-letter from guessed word
clock_t SetZero(void);
int SuccesfulGames(GameData*);
#endif