#include "AOnBoard.h"

// _________ Ctors & Dtors ___________
AOnBoard::AOnBoard() {}
AOnBoard::AOnBoard(Point & pos) : position(&pos){}
AOnBoard::AOnBoard(AOnBoard & other)
{
	copyVal(other);
};
AOnBoard::~AOnBoard()
{
	delete position;
}

// _________ Getters & Setters ___________
Point* AOnBoard::getPosition() const {return position;}
void AOnBoard::setPosition(Point& p) {position = &p;}

// _________ Methods ___________
void AOnBoard::copyVal(const AOnBoard & other)
{
	this->position = new Point(*other.position);
}
void AOnBoard::updatePostion(double x, double y)
{
	this->position->setX(x);
	this->position->setY(y);
}


