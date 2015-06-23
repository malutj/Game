#pragma once
#include <crtdefs.h>

class Character;
struct Effect
{
	//TODO Figure out how to have an effect be used on a Character
	void (*EffectAction)(Character &user, Character &target);
	time_t duration;
};

//Raise the character's accuracy by a number of points for an amount of time
void e_boostAccuracy(Character &user, Character &target);

//Raise the character's health by a number of points
void e_raiseHealth(Character &user, Character &target);


