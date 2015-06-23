
#include "GameStarter.h"
#include <iostream>

using namespace std;

int main()
{
	
	// Create the game instance
	GameStarter g;

	g.init();

	int status = g.run();

	if (status)
	{
		cout << "There was an error" << endl;
	}

	return 0;
}