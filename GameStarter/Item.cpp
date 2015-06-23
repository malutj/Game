#include "Item.h"
#include "Character.h"


bool Item::operator== (const Item &item)
{
	//TODO Fix == overload
	return this == &item;
}


void Item::useItem(Character *user, Character *target)
{
    for (std::list<Effect>::iterator it = effectList->begin(); it != effectList->end(); ++it)
    {
        it->EffectAction(*user, *user);
    }
}