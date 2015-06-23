#pragma once
#include "Item.h"
#include <list>

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

private:
	bool inventoryIsFull();
	void incrementSize(const Item &item);
	void decrementSize(const Item &item);
};

