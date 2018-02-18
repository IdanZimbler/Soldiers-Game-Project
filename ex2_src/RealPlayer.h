#pragma once
#include "APlayer.h"

// RealPlayer class derives from APlayer and representing
// the real player in the game.
class RealPlayer : public APlayer
{
public:
	// _________ Ctors & Dtors ___________
	RealPlayer(int playerID);
	RealPlayer(const RealPlayer& other);
	~RealPlayer();
	RealPlayer* clone() const;

	// _________ Methods ___________
	RealPlayer& operator=(const RealPlayer& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	string toString();
};

