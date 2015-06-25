#pragma once

#include "Consumable.h"
#include "Weapon.h"
#include "Ammunition.h"
#include "Effects.h"

#include <iostream>

// CONSUMABLES
class Medkit : public Consumable
{
public:

	Effect e1;


	Medkit()
	{
		name = "Medkit";
		isEquippable = false;
		effectList = new std::list<Effect>();

		// create the effect
		e1.EffectAction = e_raiseHealth;
		e1.duration = -1;

		// add to the effect list
		effectList->push_front(e1);
	}

	~Medkit()
	{
		cout << "Medkit being destructed" << endl;
	};
};


// WEAPONS
class Glock23 : public Weapon
{
};


// AMMUNITION
class Ammo_40_Cal : public Ammunition
{

};