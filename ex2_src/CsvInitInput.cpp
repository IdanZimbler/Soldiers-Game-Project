#include "CsvInitInput.h"
#define NONE 0.0 

// _________ Ctors & Dtors ___________
CsvInitInput::CsvInitInput(string fileName) : fileName(fileName){}
CsvInitInput::~CsvInitInput(){delete file;}

// _________ Methods ___________
GameBoard * CsvInitInput::getGameConfiguration()
{
	file = new ifstream(fileName);
	GameBoard* board = new GameBoard();
	size_t numOfSoldiers = 0;
	size_t numOfPlayer = 0;
	while (file->good())
	{
		line = csv_read_row(*file, ',');
		if (line.at(0).compare("battlefieldSize") == 0)
			battleFieldSizeLine(board);									// make the battle field 
		if (line.at(0).compare("players") == 0)
			numOfPlayer = playersLine(board);							// get num of players
		if (line.at(0).compare("soldiers") == 0)
			numOfSoldiers = soldiersLine(board);						// get num of soldier for each player
		if (line.at(0).at(0) == 'p' && isdigit(line.at(0).at(1)))
			for (size_t i = 0; i < (size_t)numOfPlayer; i++)
				playerNumLine(board,numOfSoldiers);						// make the player and all his soldier
		if (line.at(0).compare("Objects") == 0) {
			while(!file->eof())
				objectLine(board);										// make all kinds of objects
			file->close();
			return board;
		}
	}
	return nullptr;
}



// function the read the size of the battle field and make a board with the same size
void CsvInitInput::battleFieldSizeLine(GameBoard * board)
{
	try 
	{
		int r = stoi(line.at(1));
		int c = stoi(line.at(2));
		if (r < 0 || c < 0) throw invalid_argument("Battle filed size can receive only positive intergers");
		board->makeBoard(r, c);
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		exit(1);
	}
	line = csv_read_row(*file, ',');
}

// function the read the num of players in the game
size_t CsvInitInput::playersLine(GameBoard * board)
{
	int n = 0;
	try
	{
		n = stoi(line.at(1));
		if (n < 0) throw invalid_argument("Players num can receive only positive intergers");
		board->setNumOfPlayers(n);
		line = csv_read_row(*file, ',');
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		exit(1);
	}
	return (size_t)n;
}

// function the read the num of soldiers for every player in the game
size_t CsvInitInput::soldiersLine(GameBoard * board)
{
	int n = 0;
	try
	{
		n = stoi(line.at(1));
		if (n < 0) throw invalid_argument("Soldier num can receive only positive intergers");
		line = csv_read_row(*file, ',');
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		exit(1);
	}
	return (size_t)n;
}

// function that actually make the player and all his soldiers
void CsvInitInput::playerNumLine(GameBoard * board,size_t numOfSoldiers)
{
	try {
		if(line.at(0).at(1) < '0' || line.at(0).at(1) > '9') throw invalid_argument("p# ,can receive only positive intergers");
		size_t id = line.at(0).at(1) - '0';
		APlayer* player = nullptr;
		if (line.at(1).compare("human") == 0)
			player = new RealPlayer((int)id);									 		 // make real player
		else
		{
			int strategyNum = stoi(line.at(2));
			StrategyFactory factory;
			player = new ComputerPlayer((int)id, factory.makeStrategy(strategyNum));	// make computer soldier
		}
		player->setNumOfSoldiers((int)numOfSoldiers);										// initalize the army list in the player
		for (size_t i = 0; i < (size_t)numOfSoldiers; i++)
		{
			makeSoldiersForPlayer(board, player, id);									// make soldier for that player
		}
		board->addPlayer(player);
		line = csv_read_row(*file, ',');
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		exit(1);
	}
}

// function that generate soldier for a spcefic player
void CsvInitInput::makeSoldiersForPlayer(GameBoard * board, APlayer* player, size_t teamNum)
{
	try
	{
		line = csv_read_row(*file, ',');
		string soldierType = line.at(0);
		Point* position = getPointFromString(&line.at(1));
		AWeapon* weapon = nullptr;
		if (soldierType.compare("paramedic") != 0)							// if not a paramedic soldier, make weapon
		{
			WeaponFactory wFactory;
			Point* weaponPosition = new Point(*position);
			weapon = wFactory.makeWeapon(&line.at(2), *weaponPosition);		// make weapon for the soldier
			weapon->markAsAssigned();
		}
		SoldierFactory sFactory;
		Soldier* soldier = sFactory.makeSoldier(&soldierType,				// make the soldier
			*position, (int)teamNum,
			weapon);
		int x = (int)position->getX();
		int y = (int)position->getY();
		board->addElement(x, y, soldier);
		player->addSoldier(soldier);
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		exit(1);
	}
}


// function the get string represents object in the game and generate it
void CsvInitInput::objectLine(GameBoard * board)
{
	try {
		line = csv_read_row(*file, ',');
		ItemFactory factory;
		AItem* item = nullptr;
		Point* position = nullptr;
		string itemType = line.at(0);
		if (itemType.compare("weapon") == 0)											// object type is weapon	
		{
			string subItemType = line.at(1);												// get the weapon type
			position = getPointFromString(&line.at(2));
			item = factory.makeItem(&itemType, &subItemType, *position);				// make the weapon
			int x = (int)position->getX();
			int y = (int)position->getY();
			board->addElement(x, y, item);
		}
		else if (itemType.compare("Armor") == 0)										// object type is armor
		{
			string subItemType = line.at(1);											// get the armor type
			double defese = stod(line.at(2));
			if (defese < 0.65 || defese > 1 ) throw invalid_argument("Armor defense must be between 0.65 to 1");
			position = getPointFromString(&line.at(3));
			item = factory.makeItem(&itemType, &subItemType, *position, defese);			// make the armor
			int x = (int)position->getX();
			int y = (int)position->getY();
			board->addElement(x, y, item);
		}
		else if (itemType.compare("solid") == 0)										// object type is solid item
		{
			string subItemType = line.at(1);											// get type of solid item
			int height = stoi(line.at(2));
			int width = stoi(line.at(3));
			if(height*width < 2) throw invalid_argument("Solid item size must be atleast 2 units");
			position = getPointFromString(&line.at(4));
			for (size_t j = (size_t)position->getX(); j < (size_t)(position->getX() + width); j++)
			{
				for (size_t i = (size_t)position->getY(); i < (size_t)(position->getY() + height); i++)
				{
					Point* pos = new Point((double)j, (double)i);
					item = factory.makeItem(&itemType, &subItemType,					// make the solid item
						*pos, NONE,														// in every point of the matrix
						width, height);													// depends on the item size

					board->addElement(j, i, item);
				}
			}
			delete position;
		}
		else
		{
			throw invalid_argument("bad object arguments");
		}
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
	}
}


// function that get a string from the format [x y] and generate point object out of that
Point * CsvInitInput::getPointFromString(string * point)
{	
	size_t delimterIndex = point->find(" ");
	size_t closerIndex = point->find("]");
	if(delimterIndex == string::npos && closerIndex == string::npos) throw invalid_argument("Wrong point arguments");
	double x = stod(point->substr(1, delimterIndex));
	double y = stod(point->substr(delimterIndex, closerIndex));
	if (x < 0 || y < 0) throw invalid_argument("Wrong point arguments");
	Point* position = new Point(x, y);
	return position;
}


// read whole row from the csv file and return vector that represent that row
vector<string> CsvInitInput::csv_read_row(string &line, char delimiter)
{
	stringstream ss(line);
	return csv_read_row(ss, delimiter);
}

// read every char untill reach the '\n' char, and return vector represent a row
vector<string> CsvInitInput::csv_read_row(std::istream &in, char delimiter)
{
	stringstream ss;
	bool inquotes = false;
	vector<string> row;
	while (in.good())
	{
		char c = in.get();
		if (!inquotes && c == '"')
		{
			inquotes = true;
		}
		else if (inquotes && c == '"')
		{
			if (in.peek() == '"')
			{
				ss << (char)in.get();
			}
			else 
			{
				inquotes = false;
			}
		}
		else if (!inquotes && c == delimiter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && (c == '\r' || c == '\n') || c==-1)
		{
			if (in.peek() == '\n') { in.get(); }
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}
	return row;
}
