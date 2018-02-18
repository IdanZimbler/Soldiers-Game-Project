#include "UZI.h"
#define DAMAGE 40
#define BULLETS 3

// _________ Ctors & Dtors ___________
UZI::UZI(Point & pos) : LightWeapon(pos, DAMAGE, BULLETS) {}
UZI::UZI(const UZI & other){copyVal(other);}
UZI::~UZI(){}
UZI * UZI::clone() const{return new UZI(*this);}

// _________ Methods ___________
string UZI::toString(){return "UZI";};
