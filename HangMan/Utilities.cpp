#include <string.h>
#include "Header.h"
int isMatch(int letter1, int letter2)//окремі випадки, щоб введення малих літер і,ї,є також вважались правильними
{
	if (letter1 == 'і' && letter2 == 'І')
		return 1;
	else if (letter1 == 'ї' && letter2 == 'Ї')
		return 1;
	else if (letter1 == 'є' && letter2 == 'Є')
		return 1;
	return 0;
}

void decrypt(char* key, char* string)
{
	int i, string_length = strlen(string), key_length = strlen(key);
	for (i = 0; i < string_length; i++)
	{
		string[i] = string[i] ^ key[i % key_length];
	}
}

int GamesComparer(PlayStats* game1, PlayStats* game2) {
	if (game1->LifesUsed == game2->LifesUsed) {
		return game2->SecondsWasted-game1->SecondsWasted;
	}
	return game2->LifesUsed-game1->LifesUsed;
}