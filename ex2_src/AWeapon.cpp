#include "AWeapon.h"

// used to initalize the seed for the random
size_t AWeapon::seed = (size_t)time(0); // initalize the seed from the cureent time

// _________ Ctors & Dtors ___________
AWeapon::AWeapon(){}
AWeapon::AWeapon(Point & pos, int numOfShots):ACollectableItem(pos), numOfShots(numOfShots){}
AWeapon::~AWeapon(){}
AWeapon::AWeapon(const AWeapon & other)
{
	copyVal(other);
}


// _________ Getters & Setters ___________
size_t AWeapon::getNumOfShots() const {return numOfShots;}

// _________ Methods ___________
bool AWeapon::shoot(double chanceOfHit) const
{
		srand((unsigned)(seed*=seed));								 // change the seed in order to get unique number every time the funcation called
		int randNum = rand() % 100 + 1;				   	 // generate random number from 1 to 100
		if (randNum <= chanceOfHit * 100) return true;	 // true if the shoot hit
	return false;
}

void AWeapon::copyVal(const AWeapon & other)
{
	this->position = new Point(*other.position);
	this->numOfShots = other.numOfShots;
};



