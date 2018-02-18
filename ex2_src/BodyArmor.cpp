#include "BodyArmor.h"

// _________ Ctors & Dtors ___________
BodyArmor::BodyArmor(Point& pos,double defense) : AArmor(pos,defense) {}
BodyArmor::BodyArmor(const BodyArmor & other){copyVal(other);}
BodyArmor::~BodyArmor(){}
BodyArmor * BodyArmor::clone() const{return new BodyArmor(*this);};

// _________ Methods ___________
string BodyArmor::toString()
{
	return "BodyArmor at " + position->toString();
};
