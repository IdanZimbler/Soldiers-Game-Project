#pragma once
#include "ASolidItem.h"

// Tree class derives from ASolidItem and representing the tree in the game.
class Tree : public ASolidItem
{
public:
	// _________ Ctors & Dtors ___________
	Tree(Point& pos, double height, double width);
	Tree(const Tree& other);
	~Tree();
	Tree* clone() const;

	// _________ Methods ___________
	Tree& operator=(const Tree& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	string toString();
};