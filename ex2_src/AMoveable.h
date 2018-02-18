#pragma once
#include "Point.h"
#include <vector>

// Abstract class that represents a moveable object
class AMoveable{

public:
	// _________ Ctors & Dtors ___________
	AMoveable();
	AMoveable(int speed);
	AMoveable(AMoveable& other);
	virtual ~AMoveable();
	// _________ Methods ___________
	virtual void move(const Point& dest) = 0;
	AMoveable& operator=(const AMoveable& other)
	{
		if (this != &other)
		{
			this->movmentSpeed = other.movmentSpeed;
		}
		return *this;
	};

protected:
	// _________ Members ___________
	int movmentSpeed;	
};

