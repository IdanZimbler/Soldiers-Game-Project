#pragma once
#include "AArmor.h"

// ShieldArmor class derives from AArmor 
// and representing the Shield armors in the game.
class ShieldArmor : public AArmor{

public:
	// _________ Ctors & Dtors ___________
	ShieldArmor(Point& pos,double defense);
	ShieldArmor(const ShieldArmor& other);
	~ShieldArmor();
	ShieldArmor* clone() const;

	// _________ Methods ___________
	ShieldArmor& operator=(const ShieldArmor& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	string toString();
};

