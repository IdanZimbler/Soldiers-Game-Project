#pragma once
#include "AOnBoard.h"

// Abstract class that represents a item in the game
class AItem : public AOnBoard
{
public:
	// _________ Ctors & Dtors ___________
	AItem();
	AItem(Point& pos);
	AItem(const AItem& other);
	virtual ~AItem();
	virtual AItem* clone() const = 0;

	// _________ Methods ___________
	virtual string toString() = 0;
	AItem& operator=(const AItem& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
};