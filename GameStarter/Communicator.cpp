#include "Communicator.h"

#include <iostream>

Communicator::Communicator()
{

}

void Communicator::promptUser(char *prompt)
{
	cout << prompt << endl;
}


string Communicator::getInputString()
{
	string input;

	cin >> input;

	return input;
}


int Communicator::getInputNumber()
{
	int input;
	
	cin >> input;

	return input;
}