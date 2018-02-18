#pragma once
#include "Point.h"

//Abstract class that represents all objects that can be placed on board
class AOnBoard
{
public:
	// _________ Ctors & Dtors ___________
	AOnBoard();
	AOnBoard(Point& pos);
	AOnBoard(AOnBoard& other);
	virtual AOnBoard* clone() const = 0;
	virtual ~AOnBoard();

	// _________ Getters & Setters ___________
	void setPosition(Point& p);
	Point* getPosition() const;

	// _________ Methods ___________
	void updatePostion(double x, double y);
	virtual string toString() = 0;
	AOnBoard& operator=(const AOnBoard& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};



protected:
	virtual void copyVal(const AOnBoard& other);

	// _________ Members ___________
	Point* position;
};

