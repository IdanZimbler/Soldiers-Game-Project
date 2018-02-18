#include "StrategyFactory.h"

// Making a strategy depends on which strategy type is requested
// 0 - Defensive strategy
// 1 - Offensive strategy
IStrategy * StrategyFactory::makeStrategy(int numOfStrategy)
{
	if (numOfStrategy == 0) return new DefensiveStrategy();
	else if (numOfStrategy == 1) return new OffensiveStrategy();
	else throw invalid_argument("Strategy num can be 0 or 1");
};