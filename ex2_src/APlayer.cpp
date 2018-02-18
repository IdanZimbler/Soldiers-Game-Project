#include "APlayer.h"

// _________ Ctors & Dtors ___________
APlayer::APlayer(){}

APlayer::APlayer(int playerID) : playerID(playerID), numOfSoldiers(0), army(nullptr),soldierIdToAdd(0){}
APlayer::APlayer(const APlayer & other)
{
	copyVal(other);
}
APlayer::~APlayer()
{
	delete army;
}

// _________ Getters & Setters ___________
void APlayer::setNumOfSoldiers(int num)
{
	if(army==nullptr)
		army = new Soldier*[num];
	this->numOfSoldiers = num;
}
int APlayer::getNumOfSoldiers(){return numOfSoldiers;}
Soldier ** APlayer::getArmy(){return army;}

// _________ Methods ___________
void APlayer::addSoldier(Soldier * soldier)
{
	army[soldierIdToAdd++] = soldier;
}

bool APlayer::hasAliveSoldiers()
{
	for (size_t i = 0; i < (size_t)numOfSoldiers; i++)
	{
		if (army[i]->isAlive()) return true;
	}
	return false;
}

bool APlayer::hasMoreSteps()
{
	for (size_t i = 0; i < (size_t)numOfSoldiers; i++)
	{
		if (army[i]->hasSteps()) return true;
	}
	return false;
}

void APlayer::copyVal(const APlayer & other)
{
	this->playerID = other.playerID;
	this->soldierIdToAdd = 0;
	this->numOfSoldiers = other.numOfSoldiers;
	army = new Soldier*[numOfSoldiers];
	for (size_t i = 0; i < (size_t)numOfSoldiers; i++)
	{
		army[i] = other.army[i];
	}
};
