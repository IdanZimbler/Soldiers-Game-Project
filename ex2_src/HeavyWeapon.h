#pragma once
#include "AWeapon.h"
class HeavyWeapon : public AWeapon
{
public:
	// _________ Ctors & Dtors ___________
	HeavyWeapon();
	HeavyWeapon(Point& pos , double damage, int numOfShots);
	HeavyWeapon(const HeavyWeapon& other);
	virtual ~HeavyWeapon();

	// _________ Methods ___________
	HeavyWeapon& operator=(const HeavyWeapon& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	virtual string toString() = 0;

	// _________ Getters & Setters ___________
	double getWeaponPower() const;

protected:
	virtual void copyVal(const HeavyWeapon& other);

	// _________ Members ___________
	double weaponPower;
};

