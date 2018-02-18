#pragma once
#include "Soldier.h"
#include <string>
#include "NormalSoldier.h"
#include "SniperSoldier.h"
#include "ParamedicSoldier.h"
#include "AWeapon.h"
#include <stdexcept>
// SoldierFactory class using Factory design pattern which allow us to make soldier types
class SoldierFactory
{
public:
	// _________ Method ___________
	Soldier* makeSoldier(string* newSoldierType, Point & pos, int teamNum, AWeapon* weapon);
};
