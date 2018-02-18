#pragma once
#include "AOnBoard.h"
#include "Soldier.h"
#include "AItem.h"
#include "ASolidItem.h"
#include "AArmor.h"
#include "AWeapon.h"
#include "Missle.h"
#include "M16.h"
#include "UZI.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "ParamedicSoldier.h"

// Class to classify objects with boolean methods
class ObjectClassifier
{
public:
	bool isSoldier(AOnBoard* pointer);
	bool isParamedic(AOnBoard* pointer);
	bool isAItem(AOnBoard* pointer);
	bool isASolidItem(AOnBoard* pointer);
	bool isAArmor(AOnBoard* pointer);
	bool isAWeapon(AOnBoard* pointer);
	bool isMissle(AOnBoard* pointer);
	bool isM16(AOnBoard* pointer);
	bool isUZI(AOnBoard* pointer);
	bool isShieldArmor(AOnBoard* pointer);
	bool isBodyArmor(AOnBoard* pointer);
	bool isACollectAbleItem(AOnBoard * pointer);
};

