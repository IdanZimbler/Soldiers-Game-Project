#pragma once
#include "Soldier.h"

//Abstract class that represents player in the game
class APlayer
{
public:
	// _________ Ctors & Dtors ___________
	APlayer();
	APlayer(int playerID);
	APlayer(const APlayer& other);
	virtual ~APlayer();
	virtual APlayer* clone() const = 0;

	// _________ Getters & Setters ___________
	void setNumOfSoldiers(int num);
	int getNumOfSoldiers();
	Soldier** getArmy();

	// _________ Methods ___________
	APlayer& operator=(const APlayer& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	void addSoldier(Soldier* soldier);
	bool hasAliveSoldiers();
	bool hasMoreSteps();
	virtual string toString() = 0;

protected:
	virtual void copyVal(const APlayer& other);

	// _________ Members ___________
	int playerID;
	int numOfSoldiers;
	Soldier** army;	// _________ Ctors & Dtors ___________

	size_t soldierIdToAdd;
};

