#include "CsvPlayerStepsInput.h"

// _________ Ctors & Dtors ___________
CsvPlayerStepsInput::CsvPlayerStepsInput(string fileName) : fileName(fileName),file(nullptr){}
CsvPlayerStepsInput::~CsvPlayerStepsInput()
{
	file->close();
	delete file;
}

// _________ Methods ___________
//function the read a single row from the csv file and return vector represnting one soldier steps
queue<Point*>* CsvPlayerStepsInput::getSteps()
{
	if(file == nullptr)
		file = new ifstream(fileName);

	queue<Point*>* steps = new queue<Point*>;
		line = csv_read_row(*file, ',');
		if(line.at(0).compare("Player")==0)						// if its the title line, read another line
			line = csv_read_row(*file, ',');

		for (size_t i = 0; i < line.size(); i++)				// run on the vector and make points
		{
			try 
			{
				Point* step = getPointFromString(&line.at(i));
				steps->push(step);									// push every point into the vector
			}
			catch (const std::invalid_argument& e)
			{
				cout << e.what() << endl;
			}
		}
		return steps;
}


// function that get a string from the format [x y] and generate point object out of that
Point * CsvPlayerStepsInput::getPointFromString(string * point)
{
	size_t delimterIndex = point->find(" ");
	size_t closerIndex = point->find("]");
	if (delimterIndex == string::npos && closerIndex == string::npos) throw invalid_argument("Wrong point arguments");
	double x = stod(point->substr(1, delimterIndex));
	double y = stod(point->substr(delimterIndex, closerIndex));
	if (x < 0 || y < 0) throw invalid_argument("Wrong point arguments");
	Point* position = new Point(x, y);
	return position;
}

// read whole row from the csv file and return vector that represent that row
vector<string> CsvPlayerStepsInput::csv_read_row(string &line, char delimiter)
{
	stringstream ss(line);
	return csv_read_row(ss, delimiter);
}

// read every char untill reach the '\n' char, and return vector represent a row
vector<string> CsvPlayerStepsInput::csv_read_row(std::istream &in, char delimiter)
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
		else if (!inquotes && (c == '\r' || c == '\n') || c == -1)
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