#pragma once
#include <string>

using namespace std;

class Communicator
{
public:
	Communicator();

	void	promptUser(char *prompt);
	string  getInputString();
	int		getInputNumber();
};

