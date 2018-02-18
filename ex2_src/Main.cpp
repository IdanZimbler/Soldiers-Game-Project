#include <string>
#include "CsvInitInput.h"
#include "CsvPlayerStepsInput.h"
#include "FileControl.h"
#include "Game.h"
using namespace std;

int main (int argc, char* argv[]){
	if (argc > 1 && ((string)argv[1]).compare("-help") == 0)
		cout << "[initFile] [player1 player2 …]" << endl;
	else if (argc >= 2)														// valid num of arguments
	{
		string fileName(argv[1]);
		CsvInitInput* initFile = new CsvInitInput(fileName);		
		FileControl** playersSteps = new FileControl*[argc-2];

		size_t j = 0; // playerSteps index

		for (size_t i = 2; i < (size_t)argc; i++)							// initalize the palyers steps array
		{
				string temp(argv[i]);
				playersSteps[j++] = new CsvPlayerStepsInput(temp);
		}

		Game* game = Game::getInstance();	
		game->InitializeGame(initFile,playersSteps);						 // initalize the game
		game->play();														 // start the game
		game->releaseInstance();
		for (size_t i = 0; i < j; i++)
		{
			delete playersSteps[i];
		}
		delete initFile;
		delete [] playersSteps;
	}
	return 0;
}
