#include "AItem.h"


// _________ Ctors & Dtors ___________
AItem::AItem() {};
AItem::AItem(Point& pos) : AOnBoard(pos){}

// _________ Methods ___________
AItem::AItem(const AItem & other)
{
	copyVal(other);
}

AItem::~AItem(){}
