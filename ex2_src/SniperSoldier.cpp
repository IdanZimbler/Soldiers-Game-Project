#include "SniperSoldier.h"
#define MAX_HP 80
#define MOVEMENT_SPEED 2
#define ATTACK_RADIUS 20

// _________ Ctors & Dtors ___________
SniperSoldier::SniperSoldier(Point & pos, int teamNum, AWeapon* weapon)
							:Soldier(MOVEMENT_SPEED, MAX_HP, pos, teamNum, ATTACK_RADIUS)
							{ this->weapon = weapon; }
SniperSoldier::SniperSoldier(const SniperSoldier & other){copyVal(other);}
SniperSoldier::~SniperSoldier(){}
SniperSoldier * SniperSoldier::clone() const{return new SniperSoldier(*this);}

// _________ Getters & Setters ___________
int SniperSoldier::getMaxHP(){return MAX_HP;}
AWeapon * SniperSoldier::getWeapon() { return weapon; }
void SniperSoldier::setWeapon(AWeapon * weapon) { this->weapon = weapon; };

// Calculates the distance to enemy and shoots with (d-1)/d probability
void SniperSoldier::attack(Soldier & enemy)
{
	if (weapon != nullptr) {
		double d = Point::calcDistance(*this->getPosition(), *enemy.getPosition());
		for (size_t i = 0; i < (size_t)weapon->getNumOfShots(); i++)
		{
			if (weapon->shoot((d - 1) / d)) {
				enemy.defend(weapon);
			}
		}		
	}	
}

// _________ Method ___________
string SniperSoldier::toString(){return "SniperSoldier," + to_string(healthPoints)
								+ "," + position->toString() + "," + weapon->toString();};
