#pragma once
#include "IStrategy.h"

// Offensive strategy class derives from IStrategy
class OffensiveStrategy : public IStrategy
{
private:
	// _________ Members _________
	static int seed;
public:
	// _________ Methods _________
	queue<Point*>* generateSteps(int x , int y);
	int generateAttackRadius();
};

