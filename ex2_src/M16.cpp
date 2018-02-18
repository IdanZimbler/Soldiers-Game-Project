#include "M16.h"
#define DAMAGE 50
#define BULLETS 1

// _________ Ctors & Dtors ___________
M16::M16(Point & pos) : LightWeapon(pos, DAMAGE, BULLETS) {}
M16::M16(const M16 & other){copyVal(other);}
M16::~M16(){}
M16 * M16::clone() const{return new M16(*this);};


// _________ Method ___________
string M16::toString()
{
	return "M16";
};

