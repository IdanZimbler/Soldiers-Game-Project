#include "OffensiveStrategy.h"


// Seed for rand function
int OffensiveStrategy::seed = (int)time(0);

// Generate random steps and returns them in a queue
queue<Point*>* OffensiveStrategy::generateSteps(int x , int y)
{
	queue<Point*>* computerPath = new queue<Point*>();
	srand(seed *= seed);

	for (size_t i = 0; i < 5; i++)
	{
		int randNum1 = rand() % x + 1;
		int randNum2 = rand() % y + 1;
		Point* p = new Point(randNum1, randNum2);
		computerPath->push(p);
	}

 	return computerPath;
}

// Generating attack radius (larger in offensive mode)
int OffensiveStrategy::generateAttackRadius()
{
	srand(seed *= seed);
	int randNum = rand() % 20 + 1;
	
	return randNum;
}
