#pragma once
#include "IStrategy.h"
#include <ctime>

// Defensive startgy used for computer player
class DefensiveStrategy : public IStrategy
{
public:
	// _________ Methods ___________
	queue<Point*>* generateSteps(int x , int y);
	int generateAttackRadius();

private:
	static size_t seed;
};

