#pragma once
#include "GameBoard.h"

// interface for a intialize input types
class IInitializeInput
{
public:
	// _________ Methods ___________
	 virtual GameBoard* getGameConfiguration() = 0;
};