#include "ArmorFactory.h"

// this method will get a string that represents the armor type 
// and defence as double and Point represents the position of the armor
AArmor * ArmorFactory::makeArmor(string * newArmorType, double defence, Point & pos)
{
	if (newArmorType == nullptr) return nullptr;
	if (newArmorType->compare("BodyArmor") == 0) return new BodyArmor(pos, defence);
	else if (newArmorType->compare("ShieldArmor") == 0) return new ShieldArmor(pos, defence);
	else throw invalid_argument("bad armor arguments");
}
