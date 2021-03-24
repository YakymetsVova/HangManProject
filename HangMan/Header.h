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
	int Checked[16];
	int SuccesGuessed;
	char WordToGuess[16];
} GameData;

void ShowGeneralData(int);
int GamesComparer(PlayStats*, PlayStats*);
void WelcomeUser(GameData*);
void ChooseWordToGuess(GameData*);
void ShowHangman(int);
void PrintCurrentStatus(char[], GameData*);
void UpdateCurrentStatus(char[], GameData*);
void SetLevel(GameData*);
void decrypt(char*, char*);
int isMatch(int, int);
clock_t SetZero(void);
int SuccesfulGames(GameData*);
#endif