#pragma once
#include "Soldier.h"

#include "AWeapon.h"
#include "M16.h"
#include "UZI.h"
#include "Missle.h"
#include <stdexcept>

// WeaponFactory class using Factory design pattern
class WeaponFactory
{
public:
	// _________ Methods ___________
	AWeapon* makeWeapon(string* newWeaponType, Point & pos);

};

