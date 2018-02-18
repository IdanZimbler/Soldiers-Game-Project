#include "AHuman.h"
#include "AMoveable.h"

// _________ Ctors & Dtors ___________
AHuman::AHuman(){}
AHuman::AHuman(int speed, double hp): AMoveable(speed), healthPoints(hp)  {}
AHuman::~AHuman(){}
AHuman::AHuman(AHuman & other) : AMoveable(other.movmentSpeed),healthPoints(other.healthPoints){}

// _________ Methods ___________
void AHuman::increaseHP(double value){this->healthPoints += value;}
void AHuman::decreaseHP(double value){this->healthPoints -= value;}
bool AHuman::isAlive() const
{
	return healthPoints > 0;
};

// Getters & Setters 
double AHuman::getHP() const { return healthPoints; };
void AHuman::setHP(double hp) { this->healthPoints = hp; }






