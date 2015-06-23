#pragma once
#include "Effects.h"
#include <list>
#include <string>

class Character;
class Item
{
public:

	//TODO Figure out how an item can be used with the Character class. Maybe forward declarations of methods/members in addition to the class itself?
	bool operator== (const Item &item);
	void useItem(Character *user, Character *target);

	enum ItemType
	{
		Consumable,
		Weapon,
		Ammunition
	};

	//public members
	bool isEquippable;
	bool isUsable;
	int  maxStack;
	int  itemID;
	ItemType  itemType;
	std::string name;
	std::list<Effect> *effectList;

};


