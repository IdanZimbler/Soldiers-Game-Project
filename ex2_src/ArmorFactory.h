#pragma once
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "AArmor.h"
#include <stdexcept>

// Factory used to generate an armor object
class ArmorFactory
{
public:
	// _________ Methods ___________
	AArmor* makeArmor(string* newArmorType, double defence, Point& pos);
};

