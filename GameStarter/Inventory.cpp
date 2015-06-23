#include "Inventory.h"

#include <iostream>
#include <list>

using namespace std;

//list<Item> *inventory;
int maxSize;
int currentSize;


//CONSTRUCTOR
Inventory::Inventory()
{
	//inventory = new list<Item>();
	maxSize = 5;
	currentSize = 0;
}


//DESTRUCTOR
Inventory::~Inventory()
{
	// delete inventory
	cout << "deleting list inside inventory" << endl;
	//delete(inventory);
	cout << "inventory list deleted" << endl;
}


//This method removes an item from the inventory
void Inventory::removeFromInventory(const Item &item)
{
	if (this->size() == 0)
	{
		cout << "Inventory is empty" << endl;
		return;
	}
	--currentSize;
	this->remove(item);

	cout << item.name << " removed from inventory" << endl;
}



//This method attempts to add an item to the inventory
void Inventory::addToInventory(const Item &item)
{
	// if our inventory is full, return false
	if (isFull())
	{
		cout << "Inventory is already full" << endl;
		return;
	}
		

	// add the item to the back of the inventory list
	this->push_back(item);
	++currentSize;

	cout << item.name << " added to inventory" << endl;
}


//This method returns TRUE if the inventory is full
bool Inventory::isFull()
{
	return currentSize == maxSize;
}


//This method increments the current size of the inventory
void incrementSize(const Item &item)
{
	//TODO Determine the way that the inventory size is incremented
	++currentSize;
}


//This method increments the current size of the inventory
void decrementSize(const Item &item)
{
	//TODO Determine the way that the inventory size is decremented
	--currentSize;
}

int Inventory::getCurrentSize()
{
	return currentSize;
}


void Inventory::showContents()
{
	if (currentSize == 0)
	{
		cout << "Inventory is empty" << endl;
		return;
	}

	for (list<Item>::iterator it = this->begin(); it != this->end(); ++it)
	{
		cout << it->name << endl;
	}
}


bool Inventory::isEmpty()
{
    return currentSize == 0;
}
