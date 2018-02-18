#pragma once
#include "Point.h"
#include "LightWeapon.h"

// UZI class derives from LightWeapon and representing the UZI weapon in the game
class UZI : public LightWeapon
{
public:
	// _________ Ctors & Dtors ___________
	UZI(Point& pos);
	UZI(const UZI& other);
	virtual ~UZI();
	UZI* clone() const;

	// _________ Methods ___________
	UZI& operator=(const UZI& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	string toString();
};

