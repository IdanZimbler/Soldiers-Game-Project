#pragma once
#include "Point.h"
#include <queue>

// Abstract class representing input method for soldiers steps
class FileControl
{
public:
	// _________ Ctors & Dtors ___________
	virtual ~FileControl() {};

	// _________ Methods ___________
	virtual queue<Point*>* getSteps() = 0;
};
