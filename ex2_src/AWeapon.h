#pragma once
#include "ACollectableItem.h"
#include <ctime>
// Abstract class that represents a weapon in the game
class AWeapon : public ACollectableItem
{
public:
	// _________ Ctors & Dtors ___________
	AWeapon();
	AWeapon(Point& pos, int numOfShots);
	AWeapon(const AWeapon& other);
	virtual ~AWeapon();
	virtual AWeapon* clone() const = 0;

	// _________ Getters & Setters ___________
	virtual double getWeaponPower() const = 0;
	size_t getNumOfShots() const;

	// _________ Methods ___________
	AWeapon& operator=(const AWeapon& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	bool shoot(double chanceOfHit) const;
	virtual string toString() = 0;
	
protected:
	// _________ Protected methods ___________
	virtual void copyVal(const AWeapon& other);
	
	// _________ Members ___________
	size_t numOfShots;

private:
	// _________ Private members ___________
	static size_t seed;
};

