#pragma once
#include "Item.h"
#include <list>

//TODO should the inventory be a vector instead of a list??
class Inventory : public std::list<Item>
{
public:
	Inventory();
	~Inventory();

	void removeFromInventory(const Item &item);
	void addToInventory(const Item &item);
	int  getCurrentSize();
	int  getCapacity();
	void showContents();
    bool isEmpty();
    bool isFull();

private:
	
	void incrementSize(const Item &item);
	void decrementSize(const Item &item);
};

