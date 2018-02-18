#pragma once
#include "AOnBoard.h"
#include "GameBoard.h"
#include "IInitializeInput.h"
#include "IPlayAble.h"
#include "RealPlayer.h"
#include "ComputerPlayer.h"
#include "FileControl.h"
#include "ASolidItem.h"
#include "ObjectClassifier.h"
#include <algorithm>
#include "IOutput.h"

// Singleton, class is designed to control the entire course of the game
class Game : public IOutput , public IPlayAble
{
public:
	// _________ Get/Release Instance ___________
	static Game* getInstance();
	static void releaseInstance();

	// _________ Public Methods ___________
	void InitializeGame(IInitializeInput * input, FileControl** realPlayerSteps);
	void play();

private:
	// _________ Ctors & Dtors ___________
	Game();
	~Game();

	// _________ Members ___________
	static Game* instance;
	static bool instanceFlag;
	static int refCounter;
	ObjectClassifier classifier;
	GameBoard* gameBoard;
	static Point* temp; // used for comparetor


	// _________ Private Methods ___________
	void InitializeSteps(FileControl** realPlayersSteps);
	bool gameIsOn();												
	void moveSoldier(Soldier* soldier, Point* dest);
	void attack(Soldier * soldier, vector<AOnBoard*>* elements);
	void collect(Soldier * soldier, vector<AOnBoard*>* elements);
	void collectWeapon(Soldier * soldier, AOnBoard * item);
	void collectArmor(Soldier * soldier, AOnBoard * item);
	void swapWeapons(Soldier* soldier, AWeapon * w1, AWeapon * w2);
	void heal(Soldier * soldier);
	vector<AOnBoard*>* getAllNearbyElements(Soldier* soldier, int radius);
	AOnBoard * getBlockingElemenet(Point * src, Point * dest, vector<AOnBoard*>* elements);
	static bool compareByDistance(AOnBoard* i, AOnBoard* j);
	void addVector(vector<AOnBoard*>* addedVector, vector<AOnBoard*>* baseVector);
	void print(ostream& os) const;
	string endOfGame();
	APlayer * getWinnner();
	static void addRef();
	static void releaseRef();



};
