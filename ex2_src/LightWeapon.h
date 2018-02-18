#pragma once
#include "AWeapon.h"

// LightWeapon class derives from AWeapon
class LightWeapon :	public AWeapon
{
public:
	//_________ Ctors & Dtors ___________
	LightWeapon();
	LightWeapon(Point& pos, double damage, int numOfShots);
	LightWeapon(const LightWeapon& other);
	virtual ~LightWeapon();

	//_________ Methods ___________
	LightWeapon& operator=(const LightWeapon& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	virtual string toString() = 0;
	double getWeaponPower() const;

protected:
	//_________ Members ___________
	double weaponPower;
	virtual void copyVal(const LightWeapon& other);
};

