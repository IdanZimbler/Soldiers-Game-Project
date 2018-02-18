#pragma once
#include "Point.h"
#include "AOnBoard.h"
#include <queue>
#include "IAttackable.h"
#include "IDefend.h"
#include "AHuman.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "AWeapon.h"
#include <typeinfo>
#include "HeavyWeapon.h"
#include "LightWeapon.h"
#include <algorithm>
#include <math.h>
using namespace std;

// Abstract class Soldier derives from AOnBoard,AHuman,
// and implementing IDefend,IAttackable.
class Soldier : public AOnBoard, public AHuman,
				public IDefend, public IAttackable{
public:
	// _________ Ctors & Dtors ___________
	Soldier();
	Soldier(int speed, double hp, Point& pos, int teamNum,int attackRadius);
	Soldier(const Soldier& other);
	virtual ~Soldier();
	virtual Soldier* clone() const = 0;

	// _________ Getters & Setters ___________
	virtual int getMaxHP() = 0;
	virtual void setWeapon(AWeapon * weapon) = 0;
	virtual AWeapon* getWeapon() = 0;
	BodyArmor* getBodyArmor();
	ShieldArmor* getShieldArmor();
	void setBodyArmor(BodyArmor* bodyArmor);
	void setShieldArmor(ShieldArmor* shieldArmor);
	void setSteps(queue<Point*>* steps);
	int getTeamNum();
	queue<Point*>* getSteps();
	Point* getNextStep();
	virtual void setAttackRadius(int radius);
	int getAttackRadius();

	// _________ Methods ___________
	Soldier& operator=(const Soldier& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	virtual void defend(AWeapon* weapon);
	virtual void move(const Point& dest);
	virtual void attack(Soldier& enemy) = 0;
	virtual string toString() = 0;
	bool hasSteps()const;

protected:
	// _________ Members ___________
	int attackRadius;
	int teamNumber;
	queue<Point*>* steps;
	BodyArmor* bodyArmor;
	ShieldArmor* shieldArmor;		
	AWeapon* weapon;
	virtual void copyVal(const Soldier & other);
};

