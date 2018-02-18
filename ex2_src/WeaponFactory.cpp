#include "WeaponFactory.h"


// Making and returning a Weapon object depends on which weapon is requested 
AWeapon * WeaponFactory::makeWeapon(string * newWeaponType, Point & pos)
{
	if (newWeaponType == nullptr) return nullptr;
	if (newWeaponType->compare("M16") == 0) return new M16(pos);
	else if (newWeaponType->compare("UZI") == 0) return new UZI(pos);
	else if (newWeaponType->compare("Missile") == 0) return new Missle(pos);
	else throw invalid_argument("bad weapon arguments");;
}
