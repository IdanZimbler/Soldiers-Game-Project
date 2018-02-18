#include "LightWeapon.h"

//_________ Ctors & Dtors ___________
LightWeapon::LightWeapon(){}
LightWeapon::LightWeapon(Point & pos, double damage, int numOfShots) : AWeapon(pos,numOfShots) ,weaponPower(damage) {}
LightWeapon::LightWeapon(const LightWeapon & other)
{
	copyVal(other);
}
LightWeapon::~LightWeapon(){}

//___________ Getter ___________
double LightWeapon::getWeaponPower() const
{
	return weaponPower;
}

//___________ Method ___________
void LightWeapon::copyVal(const LightWeapon& other)
{
	this->position = new Point(*other.position);
	this->numOfShots = other.numOfShots;
	this->weaponPower = other.weaponPower;
};


