#include "GameStarter.h"
#include "Communicator.h"
#include "ItemDatabase.h"

#include <iostream>
#include <list>
#include <d2d1.h>
#include <WinBase.h>

#pragma comment(lib, "d2d1")

int xpNeededForLevel[];

enum MainMenu {
	CHARACTER = 1,
	INVENTORY,
	ITEMS,
	QUIT
};

ID2D1Factory *gfx;
HWND hwndMain;
HINSTANCE hinst;

GameStarter::GameStarter()
{
	com = new Communicator();
	toon = new Character();
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &gfx);
}


GameStarter::~GameStarter()
{
	delete(com);
	delete(toon);
	delete(gfx);
}

void GameStarter::drawFrame()
{
	RECT rc;
	GetClientRect(hwndMain, &rc);

	// create a Direct 2D render target
	ID2D1HwndRenderTarget *pRT;
	HRESULT hr = gfx->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
		hwndMain, D2D1::SizeU(
		rc.bottom - rc.left,
		rc.bottom - rc.top)
		),
		&pRT);

	// create a brush
	ID2D1SolidColorBrush *pBlackBrush = NULL;
	if (SUCCEEDED(hr))
	{
		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Black),
			&pBlackBrush
			);
	}

	if (!pBlackBrush)
		return;

	// draw the rectangle
	pRT->BeginDraw();

	pRT->DrawRectangle(
		D2D1::RectF(
		rc.left + 100.0f,
		rc.top + 100.0f,
		rc.right - 100.0f,
		rc.bottom - 100.0f),
		pBlackBrush);

	hr = pRT->EndDraw();

}
int GameStarter::run()
{
	// show the window
	showWindow();

	// obtain size of the drawing area
	while (true)
	{
		drawFrame();
	}
	

	//showMenu();

	return 0;
}

void GameStarter::showWindow()
{
	//WNDCLASS Wclass;
	//Wclass.lpszClassName = L"GameStarter";
	//hwndMain = CreateWindowEx(
	//	0,                      // no extended styles           
	//	L"GameStarter",           // class name                   
	//	L"Main Window",          // window name                  
	//	WS_OVERLAPPEDWINDOW |   // overlapped window            
	//	WS_HSCROLL |			// horizontal scroll bar        
	//	WS_VSCROLL,				// vertical scroll bar          
	//	CW_USEDEFAULT,          // default horizontal position  
	//	CW_USEDEFAULT,          // default vertical position    
	//	CW_USEDEFAULT,          // default width                
	//	CW_USEDEFAULT,          // default height               
	//	(HWND)NULL,            // no parent or owner window    
	//	(HMENU)NULL,           // class menu used              
	//	hinst,              // instance handle              
	//	NULL);                  // no window creation data      

	//if (!hwndMain)
	//{
	//	cout << "unable to create a window" << endl;
	//	return;
	//}
		

	// Show the window using the flag specified by the program 
	// that started the application, and send the application 
	// a WM_PAINT message. 

	//ShowWindow(hwndMain, SW_SHOWDEFAULT);
	//UpdateWindow(hwndMain);
}

void GameStarter::init()
{
	/*com->promptUser("What would you like to name your character?");
	toon->name = com->getInputString();*/
}

void GameStarter::showMenu()
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



void GameStarter::createItem()
{
	// create the item
	Medkit *mk = new Medkit();
	toon->inventory->addToInventory(*mk);
}


void GameStarter::showInventory()
{
	toon->showInventory();
}



void GameStarter::showCharacterMenu()
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


void GameStarter::showInventoryMenu()
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


void GameStarter::showItemMenu()
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