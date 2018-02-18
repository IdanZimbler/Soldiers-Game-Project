#pragma once
#include "Soldier.h"

// NormalSoldier class derives from Soldier
class NormalSoldier : public Soldier
{
public:
	// _________ Ctors & Dtors ___________
	NormalSoldier(Point& pos , int teamNum, AWeapon* weapon);
	NormalSoldier(const NormalSoldier& other);
	~NormalSoldier();
	NormalSoldier* clone() const;

	// _________ Methods ___________
	NormalSoldier& operator=(const NormalSoldier& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	}
	void attack(Soldier& enemy);
	void setWeapon(AWeapon* weapon);
	AWeapon* getWeapon();
	void move(const Point& dest);
	void run(const Point & dest);
	int getMaxHP();
	string toString();
};

