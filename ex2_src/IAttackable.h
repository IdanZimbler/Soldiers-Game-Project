#pragma once

#include "Soldier.h"
class Soldier;

// interface represents an attackable object
class IAttackable {
public:
	// _________ Methods ___________
	virtual void attack(Soldier& enemy) = 0;

};