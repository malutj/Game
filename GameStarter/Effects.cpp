#include "Effects.h"
#include "Character.h"

#include <iostream>

void e_boostAccuracy(Character &user, Character &target)
{

}

void e_raiseHealth(Character &user, Character &target)
{
	std::cout << "Adding 10 points to health" << std::endl;
	// add 10 points to health, but cap at max health
	user.currentHealth = ( user.currentHealth + 10) % user.maxHealth;
}