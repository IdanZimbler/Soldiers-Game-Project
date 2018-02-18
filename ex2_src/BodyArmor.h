#pragma once
#include "AArmor.h"

// Body armor provides protection from light weapons
class BodyArmor : public AArmor
{
public:
	// _________ Ctors & Dtors ___________
	BodyArmor(Point& pos,double defense);
	BodyArmor(const BodyArmor& other);
	~BodyArmor();
	BodyArmor* clone() const;

	// _________ Methods ___________
	BodyArmor& operator=(const BodyArmor& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	string toString();

};

