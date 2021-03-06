#include "Game.h"
#include "Communicator.h"
#include "ItemDatabase.h"

#include <iostream>
#include <list>

#pragma comment(lib, "d2d1")

int xpNeededForLevel[];

enum MainMenu {
	CHARACTER = 1,
	INVENTORY,
	ITEMS,
	QUIT
};

HWND hwndMain;

Game::Game(HWND &hwnd)
{
	com = new Communicator();
	toon = new Character();

}


Game::~Game()
{
	delete(com);
	delete(toon);
}

void Game::drawFrame()
{

}
void Game::run()
{
	
	drawFrame();

}
void Game::init()
{
	/*com->promptUser("What would you like to name your character?");
	toon->name = com->getInputString();*/
}

void Game::showMenu()
{
	// start game loop here
	do{
		com->promptUser("1. Character");
		com->promptUser("2. Inventory");
		com->promptUser("3. Items");
		com->promptUser("4. Quit");
		cout << endl;
		int input = com->getInputNumber();

		switch (input)
		{
		case CHARACTER:
			showCharacterMenu();
			break;
		case INVENTORY:
			showInventoryMenu();
			break;
		case ITEMS:
			showItemMenu();
			break;
		case QUIT:
			return;
		default:
			break;
		}
	} while (true);
}



void Game::createItem()
{
	// create the item
	Medkit *mk = new Medkit();
	toon->inventory->addToInventory(*mk);
}


void Game::showInventory()
{
	toon->showInventory();
}



void Game::showCharacterMenu()
{
	do
	{
		cout << "1. Rename Character" << endl;
		cout << "2. Show Health" << endl;
		cout << "3. Add Health" << endl;
		cout << "4. Remove Health" << endl;
		cout << "5. Show XP" << endl;
		cout << "6. Add XP" << endl;
		cout << "7. Show Level" << endl;
		cout << "8. Back" << endl;
		cout << endl;

		int input;
		cin >> input;
		switch (input)
		{
		case 1: // RENAME CHARACTER
			cout << "Enter character name";
			cin >> toon->name;
			cout << "Renamed: " << toon->name << endl;
			break;

		case 2: // SHOW HEALTH
			cout << "Current health: " << toon->currentHealth << "hp" << endl;
			break;
		case 3: // ADD HEALTH
			break;
		case 4: // REMOVE HEALTH
			cout << "Removing 10 hp" << endl;
			toon->currentHealth -= 10;
			break;
		case 5: // SHOW XP
			cout << "Current XP: " << toon->currentXp << "/" << xpNeededForLevel[toon->currentLevel + 1] << endl;
			break;
		case 6: // ADD XP
			cout << "Adding 100 xp" << endl;
			toon->addExperience(100);
			break;
		case 7: // SHOW LEVEL
			cout << "Current Level: " << toon->currentLevel << endl;
			break;
		default:
			return;
		}
	} while (true);

}


void Game::showInventoryMenu()
{
	do
	{
		cout << "1. Show Inventory" << endl;
		cout << "2. Use Item" << endl;
		cout << "3. Drop Item" << endl;
		cout << "4. Back" << endl;
		cout << endl;

		int input;
		cin >> input;
		switch (input)
		{
		case 1: // SHOW INVENTORY
			toon->showInventory();
			break;
		case 2: // USE ITEM
			//TODO this will need some way of accessing the actual item
			toon->useItem();
			break;
		case 3: // DROP ITEM
			break;
		default:
			return;
		}
	} while (true);
}


void Game::showItemMenu()
{
	Item *item;
	do
	{
		cout << "1. Create consumable" << endl;
		cout << "2. Create weapon" << endl;
		cout << "3. Back" << endl;
		cout << endl;

		int input;
		cin >> input;

		switch (input)
		{
		case 1: // CREATE CONSUMABLE
			item = new Medkit();
			toon->pickUpItem(*item);
			break;
		case 2: // CREATE WEAPON
			break;
		default:
			return;
		}
	} while (true);
}