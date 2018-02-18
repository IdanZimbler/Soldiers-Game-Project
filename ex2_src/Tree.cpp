#include "Tree.h"


// _________ Ctors & Dtors ___________
Tree::Tree(Point& pos, double h, double w) : ASolidItem(pos, h, w) {}
Tree::Tree(const Tree & other){copyVal(other);}
Tree::~Tree(){}
Tree * Tree::clone() const{return new Tree(*this);}

// _________ Methods ___________
string Tree::toString()
{
	return "Tree " + to_string(height) + "x" + to_string(width) + " at " + position->toString();
};



