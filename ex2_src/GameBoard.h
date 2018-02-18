#pragma once
#include "AOnBoard.h"
#include "APlayer.h"
#include <fstream>

// this class will represents the game board with all the elements and player on it
class GameBoard
{
public:
	// _________ Ctors & Dtors ___________
	GameBoard();
	GameBoard(const GameBoard& other);
	~GameBoard();

	// _________ Getters & Setters ___________
	vector<AOnBoard*>*** getBoard() const;
	void setNumOfPlayers(size_t n);
	APlayer** getPlayers();
	size_t getNumOfPlayers();
	size_t getRows();
	size_t getCols();

	// _________ Methods ___________
	void makeBoard(size_t r, size_t c);
	void addPlayer(APlayer* player);
	void addElement(size_t i, size_t j, AOnBoard* element);
	void removeElement(size_t i, size_t j, AOnBoard * element);
	vector<AOnBoard*>* getElement(size_t i, size_t j);
	GameBoard& operator=(const GameBoard& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	}

private:
	void copyVal(const GameBoard& other);

	// _________ Members ___________
	size_t rows;
	size_t cols;
	vector<AOnBoard*>* ** board; 
	APlayer** players;
	size_t numOfPlayers;
	size_t PlayerNumToAdd;
};