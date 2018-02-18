#include "NormalSoldier.h"

#define MAX_HP 100
#define ATTACK_RADIUS 10
#define MOVEMENT_SPEED 2
#define RUN_SPEED 4
#define PI 3.14159265

// _________ Ctors & Dtors ___________
NormalSoldier::NormalSoldier(Point & pos, int teamNum, AWeapon* weapon)	
							: Soldier(MOVEMENT_SPEED, MAX_HP, pos, teamNum, ATTACK_RADIUS)
                            {this->weapon = weapon;};
NormalSoldier::NormalSoldier(const NormalSoldier & other){copyVal(other);}
NormalSoldier::~NormalSoldier(){}
NormalSoldier * NormalSoldier::clone() const { return new NormalSoldier(*this); };

// Attack method first calculates the distance to enemy and
// shoots many times as the weapon number of shots with probability of
// 1/distance each time
void NormalSoldier::attack(Soldier& enemy) {
	if (weapon != nullptr) {
		double d = Point::calcDistance(*this->getPosition(), *enemy.getPosition());
		for (size_t i = 0; i < (size_t)weapon->getNumOfShots(); i++)
		{
			if (weapon->shoot(1 / d)) {
				enemy.defend(weapon);
			}
		}
	}
}
// _________ Setters ___________
void NormalSoldier::setWeapon(AWeapon * weapon) { this->weapon = weapon; };
AWeapon * NormalSoldier::getWeapon() { return weapon; }


// Move method first calculates the distance to destenation
// and then checks if it's a run or walk (for normal soldier)
void NormalSoldier::move(const Point & dest)
{
	double distanceToMove = Point::calcDistance(*position, dest);
	if (distanceToMove >= movmentSpeed * 4) 
		run(dest);
	else
		Soldier::move(dest);
}

// Run method calculates the distance to destenation (won't go above run_speed),
// calculates angle, new X, new Y, and set the new position.
// also updates weapon & armors if there are any.
void NormalSoldier::run(const Point & dest)
{
	double distance = min(Point::calcDistance(*position, dest), (double)RUN_SPEED);
	double angleInRadian = Point::calcAngle(*position, dest);
	double newX = distance * cos(angleInRadian) + position->getX();
	double newY = distance * sin(angleInRadian) + position->getY();
	this->updatePostion(newX, newY);
	if (weapon != nullptr) weapon->updatePostion(newX, newY);
	if (bodyArmor != nullptr) bodyArmor->updatePostion(newX, newY);
	if (shieldArmor != nullptr) shieldArmor->updatePostion(newX, newY);
	decreaseHP(10);
}

// _________ Getters & Setters ___________
int NormalSoldier::getMaxHP(){return MAX_HP;}

// _________ Methods ___________
string NormalSoldier::toString(){return "NormalSoldier," + to_string(healthPoints)
								+ "," + position->toString() + "," + weapon->toString();};