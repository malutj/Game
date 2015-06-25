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

#include "Item.h"
#include "Character.h"
#include "ExperienceLevels.h"

#include <iostream>

using namespace std;

//CONSTRUCTOR
Character::Character()
{
	// initialize variables
	currentLevel = 1;
	currentXp	 = 0;

	currentHealth = 100;
	maxHealth	  = 100;

	// initialize inventory
	inventory = new Inventory();
}


//DESCTRUCTOR
Character::~Character()
{
	// call destructor for inventory
	cout << "deleting inventory" << endl;
	//delete(inventory);
	cout << "inventory deleted" << endl;
}



//This method adds experience points for the player
void Character::addExperience(int xp)
{
	currentXp += xp;
	
	// check to see if we've gotten enough xp to level up
	if (canLevelUp())
		levelUp();
}


//This method checks to see if the character can level up
bool Character::canLevelUp()
{
	return (currentXp >= xpNeededForLevel[currentLevel +1]);
}


//This method levels the character up
void Character::levelUp()
{
	// bump up to the next level
	++currentLevel;

	// reset the experience points (roll over any extra into the new level)
	currentXp = currentXp % xpNeededForLevel[currentLevel];

    cout << "DING! Level " << currentLevel << " reached!" << endl;
}


//This method make the character use an item
void useItem(Item &item)
{
	// make sure the item is usable
    if (!item.itemType == item.Consumable)
		return;

	
}


void Character::showInventory()
{
	inventory->showContents();
}


void Character::pickUpItem(const Item &item)
{
    inventory->addToInventory(item);
}



void Character::useItem()
{
    if (inventory->isEmpty())
    {
        cout << "You don't have any items" << endl;
        return;
    }

    Item item = inventory->front();

    cout << "using " << item.name << endl;

    item.useItem(this, this);
    inventory->removeFromInventory(item);
}