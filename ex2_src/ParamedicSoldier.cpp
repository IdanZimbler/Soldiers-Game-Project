#include "ParamedicSoldier.h"
#define MAX_HP 120
#define MOVEMENT_SPEED 4
#define ATTACK_RADIUS 1
#define HEAL_RADIUS 4

// _________ Ctors & Dtors ___________
ParamedicSoldier::ParamedicSoldier(Point & pos, int teamNum): Soldier(MOVEMENT_SPEED, 
														      MAX_HP,pos,teamNum,ATTACK_RADIUS){}
ParamedicSoldier::ParamedicSoldier(const ParamedicSoldier & other){copyVal(other);}
ParamedicSoldier::~ParamedicSoldier(){}
ParamedicSoldier * ParamedicSoldier::clone() const{return new ParamedicSoldier(*this);}

// _________ Getters & Setters ___________
int ParamedicSoldier::getMaxHP() { return MAX_HP; };
int ParamedicSoldier::getHealRadius() { return HEAL_RADIUS; }
AWeapon * ParamedicSoldier::getWeapon(){return nullptr;};
void ParamedicSoldier::setWeapon(AWeapon * weapon) {};
void ParamedicSoldier::setAttackRadius(int radius) { this->attackRadius = ATTACK_RADIUS; }

// Calculates distance to enemy and attacks only if distance equals to 1 (attack with hands)
void ParamedicSoldier::attack(Soldier & enemy){
		double d = Point::calcDistance(*this->getPosition(), *enemy.getPosition());
		if(d == 1)enemy.defend(nullptr);
}

// Calculates distance to a teammate, if distance is 4 or below, heals the teammate
void ParamedicSoldier::heal(Soldier & teammate)
{
	double d = Point::calcDistance(*this->getPosition(), *teammate.getPosition());

	if (d <= 4) 
		teammate.setHP(teammate.getMaxHP());
}

// _________ Method ___________
string ParamedicSoldier::toString()
{
	return  "ParamedicSoldier," + to_string(healthPoints) + "," + position->toString() + ",";
};

