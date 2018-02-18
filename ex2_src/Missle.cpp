#include "Missle.h"
#define DAMAGE 100
#define BULLETS 1

// _________ Ctors & Dtors ___________

Missle::Missle(Point & pos) : HeavyWeapon(pos, DAMAGE, BULLETS) {};
Missle::Missle(const Missle & other) { copyVal(other); };
Missle::~Missle() {}
Missle * Missle::clone() const{return new Missle(*this);}

// _________ Methods ___________
string Missle::toString(){return "Missle";}