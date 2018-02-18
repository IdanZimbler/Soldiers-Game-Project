#include "HeavyWeapon.h"

// _________ Ctors & Dtors ___________
HeavyWeapon::HeavyWeapon(){}
HeavyWeapon::HeavyWeapon(Point & pos, double damage , int numOfShots) : AWeapon(pos,numOfShots) , weaponPower(damage) {}
HeavyWeapon::HeavyWeapon(const HeavyWeapon & other){copyVal(other);}
HeavyWeapon::~HeavyWeapon(){}

// _________ Getters && Setters ___________
double HeavyWeapon::getWeaponPower()const {return weaponPower;}

void HeavyWeapon::copyVal(const HeavyWeapon & other)
{
	this->position = new Point(*other.position);
	this->numOfShots = other.numOfShots;
	this->weaponPower = other.weaponPower;
};
