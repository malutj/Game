#pragma once
#include "Communicator.h"
#include "Character.h"

class GameStarter
{
public:
	GameStarter();
	~GameStarter();

	int run();
	void init();

private:
	Communicator *com;
	Character *toon;
	void showMenu();

	// menu options
	void createItem();
	void showInventory();
	void showCharacterMenu();
	void showInventoryMenu();
	void showItemMenu();
	void drawFrame();
	void showWindow();
};

