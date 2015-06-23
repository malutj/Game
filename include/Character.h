/*************************************************************************************
Copyright (C) 2015 PolarFrog

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

DON'T BE A DICK PUBLIC LICENSE TERMS AND CONDITIONS FOR
COPYING, DISTRIBUTION AND MODIFICATION

Do whatever you like with the original work, just don't be a dick.

Being a dick includes - but is not limited to - the following instances:

1a. Outright copyright infringement - Don't just copy this and change the name.
1b. Selling the unmodified original with no work done what-so-ever.
1c. Modifying the original work to contain hidden harmful content.

If you become rich through modifications, related works/services,
or supporting the original work, share the love. Only a dick would make
loads off this work and not buy the original works creator(s) a beer.

Code is provided with no warranty. Using somebody else's code and bitching
when it goes wrong makes you a DONKEY dick. Fix the problem yourself.

www.dbad-license.org
*************************************************************************************/
#pragma once
#include "Inventory.h"
#include <string>

using std::string;

class Item;
class Character
{
public:
	Character();
	~Character();

	void addExperience(int xp);
	void showInventory();

	//public members
	string	name;
	int		currentLevel;
	int		currentXp;
	void    useItem(Item &item);
	int		currentHealth;
	int		maxHealth;

	Inventory *inventory;


private:
	bool canLevelUp();
	void levelUp();
};