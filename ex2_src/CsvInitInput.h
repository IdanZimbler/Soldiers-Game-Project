#pragma once
#include "GameBoard.h"
#include "IInitializeInput.h"
#include <string>
#include "RealPlayer.h"
#include "ComputerPlayer.h"
#include "StrategyFactory.h"
#include "SoldierFactory.h"
#include "WeaponFactory.h"
#include "ItemFactory.h"
#include <sstream>
#include <istream>
#include <iostream>
#include <stdexcept>
using namespace std;

// Class that used to load the game configuration from a csv file
class CsvInitInput : public IInitializeInput
{
public:
	// _________ Ctors & Dtors ___________
	CsvInitInput(string  fileName);
	~CsvInitInput();

	// _________ Methods ___________
	GameBoard* getGameConfiguration();

private:
	// _________ Members ___________
	string fileName;
	ifstream * file;
	vector<string> line;

	// _________ Private methods ___________
	void battleFieldSizeLine(GameBoard* board);
	size_t playersLine(GameBoard* board);
	size_t soldiersLine(GameBoard* board);
	void playerNumLine(GameBoard* board,size_t numOfSoldiers);
	void makeSoldiersForPlayer(GameBoard * board, APlayer* player,size_t teamNum);
	void objectLine(GameBoard* board);
	Point* getPointFromString(string* point);
	vector<string> csv_read_row(string & line, char delimiter);
	vector<string> csv_read_row(std::istream & in, char delimiter);
};