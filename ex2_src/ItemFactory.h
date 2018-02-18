#pragma once
#include "WeaponFactory.h"
#include "SolidItemFactory.h"
#include "ArmorFactory.h"
#include <stdexcept>

// Factory design pattern for making items
class ItemFactory
{

public:
//___________Method___________
	AItem * makeItem(string* newItemType, string* newSubItemType, Point & pos,double defense = 0.0,int width = 0,int height = 0);
};

