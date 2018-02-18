#pragma once
#include "FileControl.h"
#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

class CsvPlayerStepsInput : public FileControl
{
public:
	// _________ Ctors & Dtors ___________
	CsvPlayerStepsInput(string fileName);
	~CsvPlayerStepsInput();

	// _________ Methods ___________
	queue<Point*>* getSteps();

private:
	// _________ Members ___________
	string fileName;
	ifstream * file;
	vector<string> line;

	// _________ Private methods ___________
	Point* getPointFromString(string* point);
	vector<string> csv_read_row(string & line, char delimiter);
	vector<string> csv_read_row(std::istream & in, char delimiter);
};

