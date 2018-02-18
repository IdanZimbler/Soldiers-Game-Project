#pragma once
#include "LightWeapon.h"

// M16 class derives from LightWeapon
class M16 : public LightWeapon{

public:
	// ___________ Ctors & Dtors ___________
	M16(Point& p);
	M16(const M16& other);
	~M16();
	M16* clone() const;

	// ___________ Methods ___________
	M16& operator=(const M16& other)
	{
		if (this != &other) copyVal(other);
		return *this;
	};
	string toString();
};

