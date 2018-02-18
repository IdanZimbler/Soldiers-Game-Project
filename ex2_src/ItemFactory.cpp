#include "ItemFactory.h"

// Function that creates and returns the object you asked to make
AItem * ItemFactory::makeItem(string * newItemType, string * newSubItemType, Point & pos, double defense, int width, int height)
{
	if (newItemType == nullptr) return nullptr;
	if (newItemType->compare("weapon") == 0) 
	{
		WeaponFactory factory;
		return factory.makeWeapon(newSubItemType,pos);
	}
	else if (newItemType->compare("Armor") == 0)
	{
		ArmorFactory factory;
		return factory.makeArmor(newSubItemType, defense, pos);
	}
	else if (newItemType->compare("solid") == 0)
	{
		SolidItemFactory factory;
		return factory.makeSolidItem(newSubItemType,pos,height,width);
	}
	else throw invalid_argument("bad object arguments");;
}
