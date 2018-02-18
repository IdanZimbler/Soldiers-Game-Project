#include "SoldierFactory.h"


// Making soldier depends on which soldier of type
// normal, sniper, paramedic requested.
Soldier * SoldierFactory::makeSoldier(string* newSoldierType , Point & pos, int teamNum, AWeapon* weapon)
{
	if (newSoldierType == nullptr) return nullptr;
	if (newSoldierType->compare("normal") == 0)
		return new NormalSoldier(pos,teamNum, weapon);
	else if (newSoldierType->compare("sniper") == 0)
		return new SniperSoldier(pos, teamNum, weapon);
	else if (newSoldierType->compare("paramedic") == 0) 
		return new ParamedicSoldier(pos, teamNum);
	else throw invalid_argument("bad solider type");
}
