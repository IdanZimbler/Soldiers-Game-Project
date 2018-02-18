#include "ShieldArmor.h"

// _________ Ctors & Dtors ___________
ShieldArmor::ShieldArmor(Point & pos,double defense): AArmor(pos,defense){}
ShieldArmor::ShieldArmor(const ShieldArmor & other){copyVal(other);}
ShieldArmor::~ShieldArmor(){}
ShieldArmor * ShieldArmor::clone() const{	return new ShieldArmor(*this);}

// _________ Method ___________
string ShieldArmor::toString(){return "ShieldArmor at " + position->toString();};
