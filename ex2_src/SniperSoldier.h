#pragma once
#include "Soldier.h"

// SniperSoldier derives from Soldier 
// and representing the sniper soldier in the game.
class SniperSoldier : public Soldier
{
public:
	// _________ Ctors & Dtors ___________
	SniperSoldier(Point& pos, int teamNum, AWeapon* weapon);
	SniperSoldier(const SniperSoldier& other);
	~SniperSoldier();
	SniperSoldier* clone() const;

	// _________ Getters & Setters ___________
	AWeapon* getWeapon();
	int getMaxHP();
	void setWeapon(AWeapon* weapon);

	// _________ Methods ___________
	void attack(Soldier& enemy);
	SniperSoldier& operator=(const SniperSoldier& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	}	
	string toString();
};

