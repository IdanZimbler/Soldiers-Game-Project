#include "ComputerPlayer.h"

// _________ Ctors & Dtors ___________
ComputerPlayer::ComputerPlayer(int playerID, IStrategy* strategy) :APlayer(playerID), strategy(strategy) {}
ComputerPlayer::ComputerPlayer(const ComputerPlayer & other){copyVal(other);}
ComputerPlayer::~ComputerPlayer(){delete strategy;}
ComputerPlayer * ComputerPlayer::clone() const {return new ComputerPlayer(*this);};

// _________ Methods ___________
string ComputerPlayer::toString()
{
	return "Player" + to_string(playerID) + "";
}

queue<Point*>* ComputerPlayer::executeGenerateSteps(int rows, int cols) 
{
	return strategy->generateSteps(rows , cols); // return steps vector that genrated by the matching strategy
}	

int ComputerPlayer::executeGenerateAttackR()
{
	return strategy->generateAttackRadius(); // return attack radius that genrated by the matching strategy
}
