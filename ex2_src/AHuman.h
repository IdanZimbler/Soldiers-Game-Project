#pragma once
#include "AMoveable.h"
#include "Point.h"
#include <vector>


// Abstract class for all that represtnts a humans
class AHuman : public AMoveable
{
public:
	// _________ Ctors & Dtors ___________
	AHuman();
	AHuman(int speed, double hp);
	AHuman(AHuman& other);
	virtual ~AHuman();

	// _________ Getters & Setters ___________
	double getHP() const;
	void setHP(double hp);

	// _________ Methods ___________
	void increaseHP(double);
	void decreaseHP(double);
	virtual void move(const Point& dest) = 0;
	bool isAlive() const;

	AHuman& operator=(const AHuman& other)
	{
		if (this != &other)
		{
			healthPoints = other.healthPoints;
		}
		return *this;
	};

protected:
	// _________ Members ___________
	double healthPoints;
};

