#include "Game.h"
#define COLLECT_RADIUS 2

// _________ Static varibles inistalize ___________
Game* Game::instance = nullptr;
bool Game::instanceFlag = false;
Point* Game::temp = nullptr;
int Game::refCounter = 0;


// _________ Get/Release Instance ___________
Game* Game::getInstance()
{
	if (!instanceFlag)
	{
		instance = new Game();
		instanceFlag = true;
	};
	addRef();
	return instance;
}

void Game::releaseInstance()
{
	releaseRef();

	if ((0 == refCounter) && (nullptr != instance))
	{
		delete instance;
		instance = nullptr;
	}
}

// _________ Cons / Dtors ___________
Game::Game() : gameBoard(nullptr), classifier() {};
Game::~Game() 
{
	instanceFlag = false; 
	delete gameBoard;
}

// _________ Methods ___________

// public method used to initalize game from configuration input and player steps input
void Game::InitializeGame(IInitializeInput * input, FileControl** realPlayerSteps)
{
	this->gameBoard = input->getGameConfiguration();			// get the game board with all the configurations
	InitializeSteps(realPlayerSteps);							// initalize steps for all the soldiers
}


// private function used to initalize steps for all the soldiers in the game
void Game::InitializeSteps(FileControl** realPlayersSteps)
{
	size_t numOfPlayers = gameBoard->getNumOfPlayers();
	APlayer** players = gameBoard->getPlayers();
	int numOfSoldiers = players[0]->getNumOfSoldiers();
	size_t k = 0; // players Steps Index

	for (size_t i = 0; i < numOfPlayers; i++)											 // run on all players
	{
		Soldier** army = players[i]->getArmy();										
		ComputerPlayer* computerPlayer = nullptr;
		computerPlayer = computerPlayer = dynamic_cast<ComputerPlayer*>(players[i]);
		if (computerPlayer == nullptr)												 	 // case real player				
		{
			for (size_t j = 0; j < (size_t)numOfSoldiers; j++)							 // run on all the player soldiers
			{
				queue<Point*>* steps = realPlayersSteps[k]->getSteps();					 // get steps from the input provided
				army[j]->setSteps(steps);
			}
			k++;
		}
		else																			 // case computer player 
		{
			for (size_t j = 0; j < (size_t)numOfSoldiers; j++)
			{
				queue<Point*>* steps = computerPlayer->
										executeGenerateSteps((int)gameBoard->getRows(),
															 (int)gameBoard->getCols()); // get steps from the player stategy
				army[j]->setSteps(steps);
				army[j]->setAttackRadius(computerPlayer->executeGenerateAttackR());		 // get attack radius
			}
		}
	}
}

// public method that used to start the game play,
// the game will continue to run as long as the soldiers have no more turns or until there is a winner in the game
void Game::play()
{
	ofstream output;
	output.open("output.csv");
	size_t numOfPlayers = gameBoard->getNumOfPlayers();
	size_t numOfSoldiers = gameBoard->getPlayers()[0]->getNumOfSoldiers();
	APlayer** players = gameBoard->getPlayers();
	output << *this;
	while (gameIsOn()) {
		for (size_t i = 0; i < numOfPlayers; i++)												// run on all players
		{
			Soldier** army = players[i]->getArmy();
			for (size_t j = 0; j < numOfSoldiers; j++)											// run on all the soldiers
			{																					// of that player
				Soldier* soldier = army[j];
				if (soldier->isAlive() && soldier->hasSteps())
				{
					Point* step = soldier->getNextStep();
					moveSoldier(soldier, step);													// move the soldier (if can)
					vector<AOnBoard*>* nearbyElements = getAllNearbyElements(soldier,			
																	soldier->getAttackRadius());
					attack(soldier, nearbyElements);											// attack (if can)
					nearbyElements = getAllNearbyElements(soldier, COLLECT_RADIUS);	
					collect(soldier, nearbyElements);											// collect items (if can)
					if (classifier.isParamedic(soldier))										// in case of paramedic soldier
						heal(soldier);															// heal (if can)				
				}
			}
		}
		output << *this;																		// write the iteration summary
	}																							// to the output file

	output << endOfGame() << endl;																// add line representig end
																								// of the game to the output
	output.close();
}

// function that return true if their is more then 1 active players
// active player considered as a player with atleast 1 active soldier (has turns and alive)
bool Game::gameIsOn()
{
	int activePlayers = 0;
	for (size_t i = 0; i < gameBoard->getNumOfPlayers(); i++)					// run on all players
	{
		if (gameBoard->getPlayers()[i]->hasMoreSteps() &&						// checks if its active player
			gameBoard->getPlayers()[i]->hasAliveSoldiers())
		{
			activePlayers++;
		}
	}
	return activePlayers > 1;							
}

// function that get a soldier and move it as a close as possible to his destination
void Game::moveSoldier(Soldier * soldier, Point * dest)
{
	int distanceToDest = (int)Point::calcDistance(*soldier->getPosition(), *dest);
	vector<AOnBoard*>* nearbyElements = getAllNearbyElements(soldier, distanceToDest);
	AOnBoard* item = getBlockingElemenet(soldier->getPosition(), dest, nearbyElements);
	if (item != nullptr)									//	if there is blocking item 
	{
		delete dest;							
		dest = new Point(*(item->getPosition()));			// update the destination to the item's postion
	}
	double oldX = soldier->getPosition()->getX();
	double oldY = soldier->getPosition()->getY();

	// get newX/newY ,make sure its not exit from the board limits
	double newX = oldX > dest->getX() ? max(0.0, dest->getX()) : min((double)gameBoard->getCols()-1, dest->getX());
	double newY = oldY > dest->getY() ? max(0.0, dest->getY()) : min((double)gameBoard->getRows()-1, dest->getY());
	dest->setX(newX);
	dest->setY(newY);	
	soldier->move(*dest);									// tell the soldier to move to the updated destination
															// the soldier will move as much closer to the destination
															// depends on the soldier move raiuds policy
	delete dest;
	gameBoard->removeElement((size_t)oldX, (size_t)oldY, soldier);			// remove the soldiers from the board at the old postion
	gameBoard->addElement((size_t)soldier->getPosition()->getX(),	        // and replace the soldier on the board with the new postion
						  (size_t)soldier->getPosition()->getY(),
						  soldier);
	delete nearbyElements;
}  


// function the get a soldiers and try to attack the nearest enemy soldier (if there is any)
// this function get vector of all the nearby elements ordred by distance from the soldier
void Game::attack(Soldier* soldier, vector<AOnBoard*>* elements)
{
	vector<AOnBoard*>::iterator it;
	for (it = elements->begin(); it != elements->end(); ++it)
	{
		Soldier* otherSoldier = nullptr;
		try
		{
			otherSoldier = dynamic_cast<Soldier*>(*it);
		}
		catch (...) {}
		if ((otherSoldier != nullptr) &&														// the element is soldier
			(otherSoldier->getTeamNum() != soldier->getTeamNum()) &&							// at other team
			(Point::calcDistance(*soldier->getPosition(), 
								 *otherSoldier->getPosition()) <= soldier->getAttackRadius()))	// the distance match the 
		{																						// attack radius
			if (getBlockingElemenet(soldier->getPosition(), 
									otherSoldier->getPosition(), 
									elements) == nullptr)										// there is no blocking element
			{																					// between them
				soldier->attack(*otherSoldier);
			}
		}
	}
	delete elements;
}

// function the get a soldier and vector nearby elements and checks
// if its possible to collect it, and then collect the item 
void Game::collect(Soldier* soldier, vector<AOnBoard*>* elements)
{
	vector<AOnBoard*>::iterator it;

	for (it = elements->begin(); it != elements->end(); ++it)
	{
		if (classifier.isACollectAbleItem(*it) &&
			Point::calcDistance(*soldier->getPosition(), 
								*(*it)->getPosition()) <= COLLECT_RADIUS)		// the item distance matches the collect radius
		{																		
			if (classifier.isAArmor(*it)) collectArmor(soldier, *it);			// case armor - collect armor
			else if (classifier.isAWeapon(*it)) collectWeapon(soldier, *it);	// case weapon - collect weapon
		}
	}
	delete elements;
}

// function that get a soldier and a weapon found on the board,
// checks if the soldier can collect the weapon and if he does, swap the weapons
void Game::collectWeapon(Soldier* soldier, AOnBoard* item)
{
	AWeapon* weapon = dynamic_cast<AWeapon*>(item);
	if (classifier.isParamedic(soldier)) return;
	if (classifier.isUZI(item) && !(classifier.isUZI(soldier->getWeapon())))			// the weapon is UZI 
	{																					// and the soldier dont have UZI
		swapWeapons(soldier,soldier->getWeapon(), weapon);
		soldier->setWeapon(weapon);
	}
	else if (classifier.isM16(item) && !(classifier.isM16(soldier->getWeapon())))		// the weapon is M16
	{																					// and the soldier dont have M16
		swapWeapons(soldier,soldier->getWeapon(), weapon);
		soldier->setWeapon(weapon);
	}
	else if (classifier.isMissle(item) && !(classifier.isMissle(soldier->getWeapon()))) // the weapon is Missle
	{																					// and the soldier dont ahve Missle
		swapWeapons(soldier,soldier->getWeapon(), weapon);
		soldier->setWeapon(weapon);
	}
}

// function that get a soldier and an armor found on the board,
// checks is the soldier can collect the armor and if he does, collect the armor
void Game::collectArmor(Soldier* soldier, AOnBoard* item)
{
	if (classifier.isBodyArmor(item) && (soldier->getBodyArmor() == nullptr))					// the armor is body armor
	{																							// and the soldier dont have it
		BodyArmor* armor = dynamic_cast<BodyArmor*>(item);
		soldier->setBodyArmor(armor);
		gameBoard->removeElement((size_t)armor->getPosition()->getX(),(size_t)armor->getPosition()->getY(), armor);
		armor->updatePostion(soldier->getPosition()->getX(), soldier->getPosition()->getY());
	}
	else if (classifier.isShieldArmor(item) && (soldier->getShieldArmor() == nullptr))			// the armor is shield armor
	{																							// and the soldier dont have it
		ShieldArmor* armor = dynamic_cast<ShieldArmor*>(item);
		soldier->setShieldArmor(armor);
		gameBoard->removeElement((size_t)armor->getPosition()->getX(), (size_t)armor->getPosition()->getY(), armor);
		armor->updatePostion(soldier->getPosition()->getX(), soldier->getPosition()->getY());
	}
}

// function that get a soldier and 2 weapons, the first is the soldier's weapon and secons is a unassigned weapon
// and then swap between the weapons
void Game::swapWeapons(Soldier* soldier,AWeapon* soldierWeapon, AWeapon* newWeapon)
{
	gameBoard->addElement((size_t)soldierWeapon->getPosition()->getX(), 
						  (size_t)soldierWeapon->getPosition()->getY(), soldierWeapon);
	gameBoard->removeElement((size_t)newWeapon->getPosition()->getX(), 
							 (size_t)newWeapon->getPosition()->getY(), newWeapon);
	soldier->setWeapon(newWeapon);
	newWeapon->markAsAssigned();
	soldierWeapon->markAsUnAssigned();
	newWeapon->updatePostion(soldier->getPosition()->getX(), soldier->getPosition()->getY());
}


// function that get a paramedic soldier and checks if the soldier can heal any of his teammates
void Game::heal(Soldier* soldier)
{
	ParamedicSoldier* healer = dynamic_cast<ParamedicSoldier*>(soldier);
	if (healer == nullptr) return;																// soldeir is not healer,return
	vector<AOnBoard*>* nearbyElements = getAllNearbyElements(healer, healer->getHealRadius());  // get all nearby elements
	vector<AOnBoard*>::iterator it;

	for (it = nearbyElements->begin(); it != nearbyElements->end(); ++it)					   // run on all the elements	
	{																						   // in the vectors
		
		if (classifier.isSoldier(*it))														   // case the element is soldier												
		{
			Soldier* otherSoldier = dynamic_cast<Soldier*>(*it);							   
			if (otherSoldier != healer &&													   // if its not the soldier himslef
				otherSoldier->getTeamNum() == healer->getTeamNum() &&						   // and the same team
				(Point::calcDistance(*otherSoldier->getPosition(),							   // the distance matches
									 *healer->getPosition()) <= healer->getHealRadius()))	   // to the soldier's heal radius
			{
				healer->heal(*otherSoldier);												   // heal the other soldier
			}
		}
	}
	delete nearbyElements;
}

// function that get a soldier and radius, and search for all elements at the grid around the soldier
// the user have to check that every element is at the right distance
// the function will return a vector of all nearby elements , ordred by the distance
vector<AOnBoard*>* Game::getAllNearbyElements(Soldier * soldier, int radius)
{
	vector<AOnBoard*>* gridElements = new vector<AOnBoard*>;
	temp = soldier->getPosition();

	// get the grid limits
	double beginX = max(soldier->getPosition()->getX()-radius, 0.0);
	double beginY = max(soldier->getPosition()->getY()-radius, 0.0);
	double endX = min(soldier->getPosition()->getX() + radius, (double)gameBoard->getRows());
	double endY = min(soldier->getPosition()->getY() + radius, (double)gameBoard->getCols());

	for (size_t i = (size_t)beginX; i < endX; i++)										 	// run on the grid
	{
		for (size_t j = (size_t)beginY; j < endY; j++)
		{
			if (gameBoard->getElement(i, j) != nullptr)							    // found vector with element\s
			{
				vector<AOnBoard*>* elements = gameBoard->getElement(i, j);
				addVector(elements, gridElements);								    // add the elements in the vector 
			}																	    // to the grid vector
		}
	}
	std::sort(gridElements->begin(), gridElements->end(), Game::compareByDistance); // sort the grid vector by distance from soldier
	return gridElements;
}

// function that get a source point, destination point and nearby elements vector 
// and check is there is any solid item between those points.
// return the item if there is any, or nullptr if there is no blocking item
AOnBoard* Game::getBlockingElemenet(Point* src, Point* dest, vector<AOnBoard*>* elements)
{
	int distanceToDest = (int)Point::calcDistance(*src, *dest);
	double angleToDest = Point::calcAngle(*src, *dest);
	vector<AOnBoard*>::iterator it;

	for (it = elements->begin(); it != elements->end(); ++it)							// run on all nearby elements
	{
		if (classifier.isASolidItem(*it))												// case solid item
		{
			int distanceToItem = (int)Point::calcDistance(*src, *(*it)->getPosition());
			double angleToItem = Point::calcAngle(*src, *(*it)->getPosition());
			if ((distanceToItem <= distanceToDest) && (angleToItem == angleToDest))		// the item is between them 
				return *it;															    // (smaller distance and same angle)
		}
	}
	return nullptr;
}

// comperator used to compare two AOnBoard objects by the distance from the temp point
bool Game::compareByDistance(AOnBoard * i, AOnBoard * j)
{
	return Point::calcDistance(*temp, *i->getPosition()) < Point::calcDistance(*temp, *j->getPosition());
}

// function that get to vector, main vector and subsidiary vector 
// and add the subsidiary vector elements to the main vector
void Game::addVector(vector<AOnBoard*>* addedVector, vector<AOnBoard*>* baseVector)
{
	vector<AOnBoard*>::iterator it;
	for (it = addedVector->begin(); it != addedVector->end(); ++it)
	{
		baseVector->push_back(*it);
	}
}

// function that print the current state of the game
void Game::print(ostream & os) const
{
	os << "Game Configurations" << endl;
	APlayer** players = gameBoard->getPlayers();
	for (size_t i = 0; i < gameBoard->getNumOfPlayers(); i++)
	{
		os << players[i]->toString() << endl;
		Soldier** army = players[i]->getArmy();
		for (size_t j = 0; j < (size_t)players[i]->getNumOfSoldiers(); j++)
		{
			os << army[j]->toString() << endl;
		}
	}
}

// function return string of the end of the game summary
string Game::endOfGame()
{
	APlayer* winner = nullptr;
	if ((winner = getWinnner()) == nullptr)
		return  "No Winner!";
	else return "Winner is " + winner->toString();
}

// function the return a winner in the game,
// if there is no winner the function will return nullptr
APlayer* Game::getWinnner()
{
	int LivePlayers = 0;
	APlayer* winner = nullptr;
	for (size_t i = 0; i < gameBoard->getNumOfPlayers(); i++)
	{
		if (gameBoard->getPlayers()[i]->hasAliveSoldiers())
		{
			LivePlayers++;
			winner = gameBoard->getPlayers()[i];
		}
	}
	return LivePlayers == 1 ? winner : nullptr ;				// if there is exactly 1 active player - he is the winner
}


// increment the reference counter
void Game::addRef()
{
	refCounter++;
}

// decrement the reference counter
void Game::releaseRef()
{
	--refCounter;
}
