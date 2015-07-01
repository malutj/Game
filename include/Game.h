#pragma once
#include <Windows.h>
#include "Communicator.h"
#include "Character.h"
#include <d2d1.h>

class Game
{
public:
	Game(HWND &hwnd);
	~Game();

	void run();
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


};

