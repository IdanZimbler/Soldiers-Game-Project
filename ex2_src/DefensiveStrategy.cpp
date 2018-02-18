#include "DefensiveStrategy.h"


//Defensive mode, attack radius is shorter.

// used to initalize the seed for the random
size_t DefensiveStrategy::seed = (size_t)time(0); // initalize the seed from the cureent time

// _________ Methods ___________

// function that randomly generate steps taking into consideration the limits of the game (x,y)
queue<Point*>* DefensiveStrategy::generateSteps(int x , int y)
{
	queue<Point*>* computerPath = new queue<Point*>();
	srand((unsigned)(seed *= seed));									// change the seed in order to get unique 
															// number every time the funcation called

	for (size_t i = 0; i < 5; i++)							// generate 5 diffrents steps
	{
		int randNum1 = rand() % x + 1;
		int randNum2 = rand() % y + 1;
		Point* p = new Point(randNum1, randNum2);
		computerPath->push(p);								// push the steps into the queue
	}
	return computerPath;
}

// function that randomly getenrate defensive attack radius
int DefensiveStrategy::generateAttackRadius()			
{
	srand((unsigned)(seed *= seed));									// change the seed in order to get unique 
															// number every time the funcation called
	int randNum = rand() %10  + 1;
	return randNum;
}
