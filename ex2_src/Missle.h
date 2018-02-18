#pragma once
#include "HeavyWeapon.h"
#include "Point.h"

// Missle class derives from  HeavyWeapon
class Missle : public HeavyWeapon
{
public:
	// _________ Ctors & Dtors ___________
	Missle(Point& pos);
	Missle(const Missle& other);
	virtual ~Missle();
	Missle* clone() const;

	// _________ Methods ___________
	Missle& operator=(const Missle& other)
	{
		if (this != &other)copyVal(other);
		return *this;
	};
	string toString();
};

