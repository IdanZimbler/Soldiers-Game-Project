#pragma once
#include "Soldier.h"

// Paramedic soldier class derives from Soldier
class ParamedicSoldier : public Soldier
{
public:
	// _________ Ctors & Dtors ___________
	ParamedicSoldier(Point& pos, int teamNum);
	ParamedicSoldier(const ParamedicSoldier& other);
	~ParamedicSoldier();
	ParamedicSoldier* clone() const;

	// _________ Getters & Setters ___________
	int getMaxHP();
	void setWeapon(AWeapon * weapon);
	AWeapon* getWeapon();
	void setAttackRadius(int radius);
	int getHealRadius();

	// _________ Methods ___________
	void attack(Soldier& enemy);
	void heal(Soldier& teammate);

	ParamedicSoldier& operator=(const ParamedicSoldier& other)
	{
		if (this != &other) copyVal(other);
		return *this;
	}
	string toString();

};

