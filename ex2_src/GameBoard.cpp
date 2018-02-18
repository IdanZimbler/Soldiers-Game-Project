#include "GameBoard.h"

// _________ Ctors & Dtors ___________
GameBoard::GameBoard() : board(nullptr), players(nullptr), rows(0), cols(0), numOfPlayers(0), PlayerNumToAdd(0) {}
GameBoard::GameBoard(const GameBoard & other){copyVal(other);}
GameBoard::~GameBoard()
{
	for (size_t i = 0; i < numOfPlayers; i++)										// delete the players		
	{
		delete players[i];
	}
	delete players;

	for (size_t i = 0; i < rows; i++)												// delete the board will all the			
																					// elements on it
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (board[i][j] != nullptr)
			{
				vector<AOnBoard*>::iterator it;
				for (it = board[i][j]->begin(); it != board[i][j]->end(); ++it)
				{
					delete (*it);
				}
				board[i][j]->clear();
				delete (board[i][j]);
			}
		}
		delete board[i];
	}
	delete board;
}



// _________ Getters & Setter ___________
vector<AOnBoard*>*** GameBoard::getBoard() const {return board;}
size_t GameBoard::getNumOfPlayers(){return numOfPlayers;}
APlayer ** GameBoard::getPlayers(){return players;}
size_t GameBoard::getRows(){return rows;}
size_t GameBoard::getCols(){return cols;}
void GameBoard::setNumOfPlayers(size_t n)
{
	this->numOfPlayers = n;
	this->players = new APlayer*[numOfPlayers];
}


// _________ Methods ___________

// function that initalize the board with given row/colums size
void GameBoard::makeBoard(size_t r, size_t c)
{
	this->rows = r;
	this->cols = c;
	this->board = new vector<AOnBoard*>**[r];
	for (size_t i = 0; i < r; i++)
	{
		board[i] = new vector<AOnBoard*>*[c];
		for (size_t j = 0; j < c; j++)
		{
			board[i][j] = nullptr;
		}
	}
}

// function that add element to the postion (i,j)
// the function will add the item to the matches vector or create one
// if there is no any vector at that position
void GameBoard::addElement(size_t i, size_t j, AOnBoard * element)
{
	if (board[i][j] == nullptr) 
	{
		board[i][j] = new vector<AOnBoard*>;
	}
	board[i][j]->push_back(element);
}

// function that remove an element from the board from a given position (i,j)
void GameBoard::removeElement(size_t i, size_t j, AOnBoard* element)
{
	if (board[i][j] != nullptr)
	{
		vector<AOnBoard*>*  elementVec = board[i][j];
		vector<AOnBoard*>::iterator it;
		for (it = elementVec->begin(); it != elementVec->end(); ++it)
		{
			if (element == *it)
			{
				elementVec->erase(it);
				break;
			}
		}
	}

}

// get a vector with all the elements from a give position (i,j)
vector<AOnBoard*>* GameBoard::getElement(size_t i, size_t j)
{
	return board[i][j];
}

// add new player to the players list
void GameBoard::addPlayer(APlayer* player)
{
	players[PlayerNumToAdd++] = player;
}

// copy the value from other gameboard to this gameboard
void GameBoard::copyVal(const GameBoard & other)
{
	this->rows = other.rows;
	this->cols = other.cols;
	board = new vector<AOnBoard*>**[rows];

	for (size_t i = 0; i < rows; i++)
	{
		board[i] = new vector<AOnBoard*>*[cols];
		for (size_t j = 0; j < cols; j++)
		{
				if (other.board[i][j] != nullptr)
				{
					vector<AOnBoard*>* vec = new vector<AOnBoard*>();
					vector<AOnBoard*>::iterator it;
					for (it = other.board[i][j]->begin(); it != other.board[i][j]->end(); ++it)
					{
						AOnBoard* temp = (*it)->clone();
						vec->push_back(temp);
					}
					board[i][j] = vec;
				}
				else
				{
					board[i][j] = nullptr;
				}
		}
	}
	this->numOfPlayers = other.numOfPlayers;
	this->PlayerNumToAdd = other.PlayerNumToAdd;
	players = new APlayer*[numOfPlayers];
	for (size_t i = 0; i < numOfPlayers; i++)
	{
		APlayer* player = other.players[i]->clone();
		players[i] = player;
	}
}

