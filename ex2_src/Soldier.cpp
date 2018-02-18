#include "Soldier.h"

#define handsAttack 10

// _________ Ctors & Dtors ___________
Soldier::Soldier(){}
Soldier::Soldier(int speed, double hp, Point& pos, int teamNum,int attackRadius) :
				AHuman(speed, hp), AOnBoard(pos), teamNumber(teamNum), attackRadius(attackRadius),
				steps(nullptr), bodyArmor(nullptr) ,shieldArmor(nullptr), weapon(nullptr) {}
Soldier::Soldier(const Soldier & other){copyVal(other);}
Soldier::~Soldier()
{
	delete bodyArmor;
	delete shieldArmor;
	delete weapon;
	if (steps != nullptr)
	{
		while (!steps->empty())
		{
			delete steps->front();
			steps->pop();
		}
		delete steps;
	}
}

// _________ Getters & Setters ___________
BodyArmor * Soldier::getBodyArmor() { return bodyArmor; };
ShieldArmor * Soldier::getShieldArmor() { return shieldArmor; };
void Soldier::setBodyArmor(BodyArmor * bodyArmor) { this->bodyArmor = bodyArmor; };
void Soldier::setShieldArmor(ShieldArmor * shieldArmor) { this->shieldArmor = shieldArmor; }
void Soldier::setSteps(queue<Point*>* steps){this->steps = steps;}
int Soldier::getTeamNum(){return teamNumber;}
queue<Point*>* Soldier::getSteps() { return steps; }
void Soldier::setAttackRadius(int radius){this->attackRadius = radius;}
int Soldier::getAttackRadius(){return attackRadius;}
Point * Soldier::getNextStep()
{
	Point* step = nullptr;
	if (!steps->empty())
	{
		step = steps->front();
		steps->pop();
	}
	return step;
}

// _________ Methods ___________
bool Soldier::hasSteps() const { return !(steps->empty()); }

// Defending types depends on LightWeapon\HeavyWeapon of the attacker,
// and if there are two armors, they are multiplied for better armor.
void Soldier::defend(AWeapon* weapon) {
	double damage = weapon->getWeaponPower();

	if (weapon != nullptr) // if there is a weapon
	{
		LightWeapon* lightWeapon = nullptr;
		HeavyWeapon* heavyWeapon = nullptr;
		try {
			lightWeapon = dynamic_cast<LightWeapon*>(weapon);
			heavyWeapon = dynamic_cast<HeavyWeapon*>(weapon);
		}
		catch (...) {}
		if (heavyWeapon != nullptr)
			if (shieldArmor != nullptr) damage *= shieldArmor->getDefense();
		else if (lightWeapon != nullptr)
		{
			if (shieldArmor != nullptr && bodyArmor != nullptr)
				damage *= (shieldArmor->getDefense())*(bodyArmor->getDefense());
			else if (shieldArmor != nullptr) damage *= shieldArmor->getDefense();
			else if (bodyArmor != nullptr) damage *= bodyArmor->getDefense();
		}
	}
	else// no weapon 
	{ 		
		damage = handsAttack;
		if (shieldArmor != nullptr && bodyArmor != nullptr) 
			damage *= (shieldArmor->getDefense())*(bodyArmor->getDefense());
		else if (shieldArmor != nullptr) damage *= shieldArmor->getDefense();
		else if (bodyArmor != nullptr) damage *= bodyArmor->getDefense();
	}
	decreaseHP(damage);
}

void Soldier::copyVal(const Soldier & other)
{
	this->movmentSpeed = other.movmentSpeed;
	this->healthPoints = other.healthPoints;
	this->position = new Point(*other.position);
	this->teamNumber = other.teamNumber;
	this->attackRadius = other.attackRadius;
	this->steps = other.steps;
	this->bodyArmor = other.bodyArmor;
	this->shieldArmor = other.shieldArmor;
	this->weapon = other.weapon;
};


// Move method calculates the distance to destination, angle, new X, new Y
// And updates the new X and Y for the object.
// also moves the weapon and armors along with the soldier
void Soldier::move(const Point& dest)
{
	double distance = min(Point::calcDistance(*position, dest), (double)movmentSpeed);
	double angleInRadian = Point::calcAngle(*position, dest);
	double newX = distance * cos(angleInRadian) + position->getX();
	double newY = distance * sin(angleInRadian) + position->getY();
	this->updatePostion(newX, newY);
	if (weapon != nullptr) weapon->updatePostion(newX, newY);
	if (bodyArmor != nullptr) bodyArmor->updatePostion(newX, newY);
	if (shieldArmor != nullptr) shieldArmor->updatePostion(newX, newY);
}



