#pragma once
#include <queue>
#include "Point.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

// Interface to implement the strategy design pattern
class IStrategy
{
public:
//___________Methods___________
	virtual queue<Point*>* generateSteps(int x, int y) = 0;
	virtual int generateAttackRadius() = 0;
};