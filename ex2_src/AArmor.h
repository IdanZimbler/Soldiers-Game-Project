#pragma once
#include "ACollectableItem.h"

// Abstract class for all kinds of armor
class AArmor : public ACollectableItem {
public:
	// _________ Ctors & Dtors ___________
	AArmor();
	AArmor(Point& pos, double defense);
	AArmor(const AArmor& other);
	virtual ~AArmor();
	virtual AArmor* clone() const = 0;

	// _________ Getters & Setters ___________
	double getDefense() const;
	void setDefense(double defense);

	// _________ Methods ___________
	AArmor& operator=(const AArmor& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	virtual string toString() = 0;


protected:
	// _________ Members ___________
	double defense;

	virtual void copyVal(const AArmor& other);

};

