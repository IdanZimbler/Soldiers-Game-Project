#pragma once
#include "ASolidItem.h"
#include <string>
#include "Tree.h"
#include <stdexcept>

using namespace std;

// SolidItemFactory class using Factory design pattern which allow us to make solid item types
class SolidItemFactory
{
public:
	// _________ Methods ___________
	ASolidItem* makeSolidItem(string* newSolidItemType, Point & pos , double h , double w);
};

