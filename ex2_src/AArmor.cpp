#include "AArmor.h"

// _________ Ctors & Dtors ___________
AArmor::AArmor() {};

AArmor::AArmor(Point & pos, double def): ACollectableItem(pos), defense(def) {}

AArmor::~AArmor(){}

AArmor::AArmor(const AArmor & other)
{
	copyVal(other);
}


// _________ Getters & Setters ___________
double AArmor::getDefense() const { return defense; };

void AArmor::setDefense(double defense) { this->defense = defense; }

// _________ Methods ___________
void AArmor::copyVal(const AArmor & other)
{
	this->defense = other.defense;
	this->position = new Point(*other.position);
};
