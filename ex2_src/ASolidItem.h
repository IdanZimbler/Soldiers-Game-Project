#pragma once
#include "AItem.h"

// Abstract class that represents a soild item in the game
class ASolidItem : public AItem
{
public:
	// _________ Ctors & Dtors ___________
	ASolidItem();
	ASolidItem(Point& pos, double h, double w);
	ASolidItem(const ASolidItem& other);
	virtual ~ASolidItem();
	virtual ASolidItem* clone() const = 0;

	// _________ Getters & Setters___________
	double getHeight();
	double getWidth();
	void setHeight(double height);
	void setWidth(double width);

	// _________ Methods ___________
	ASolidItem& operator=(const ASolidItem& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	virtual string toString() = 0;

protected:
	// _________ Protected methods ___________
	virtual void copyVal(const ASolidItem& other);
	
	// _________ Members ___________
	double height;
	double width;


};