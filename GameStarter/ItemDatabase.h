#pragma once

#include "Item.h"
#include "Effects.h"

#include <iostream>

class Medkit : public Item
{
public:

	Effect e1;


	Medkit()
	{
		name = "Medkit";
		itemType = Consumable;
		isUsable = true;
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