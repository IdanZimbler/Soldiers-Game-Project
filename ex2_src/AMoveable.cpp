#include "AMoveable.h"

// _________ Ctors & Dtors ___________
AMoveable::AMoveable(){}
AMoveable::AMoveable(int speed):movmentSpeed(speed){}
AMoveable::AMoveable(AMoveable & other): movmentSpeed(other.movmentSpeed){}
AMoveable::~AMoveable(){}
