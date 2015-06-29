#include "Effects.h"
#include "Character.h"

#include <iostream>

void e_boostAccuracy(Character &user, Character &target)
{

}

void e_raiseHealth(Character &user, Character &target)
{
	std::cout << "Adding 10% to health" << std::endl;
	// add 10 % hp back to health, but cap at max health
    int healthToAdd = (int)(user.maxHealth * .1);
	user.currentHealth = ( user.currentHealth + healthToAdd);

    if (user.currentHealth > user.maxHealth)
        user.currentHealth = user.maxHealth;
}