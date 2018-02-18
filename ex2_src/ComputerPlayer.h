#pragma once
#include "APlayer.h"
#include "IStrategy.h"

class ComputerPlayer : public APlayer
{
public:
	// _________ Ctors & Dtors ___________
	ComputerPlayer(int playerID, IStrategy* strategy);
	ComputerPlayer(const ComputerPlayer& other);
	~ComputerPlayer();
	ComputerPlayer* clone() const;

	// _________ Methods ___________
	ComputerPlayer& operator=(const ComputerPlayer& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	string toString();
	queue<Point*>* executeGenerateSteps(int rows, int cols);
	int executeGenerateAttackR();

private:
	// _________ Members ___________
	IStrategy* strategy;
};

