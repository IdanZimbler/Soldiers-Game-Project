#pragma once
#include "IStrategy.h"
#include "OffensiveStrategy.h"
#include "DefensiveStrategy.h"
#include <stdexcept>

// StrategyFactory class using Factory design pattern
// which allow us to make strategy of different types
class StrategyFactory
{
public:
	// _________ Methods ___________
	IStrategy* makeStrategy(int numOfStrategy);
};

