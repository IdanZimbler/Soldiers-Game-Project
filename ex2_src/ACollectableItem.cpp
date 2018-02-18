#include "ACollectableItem.h"

// _________ Ctors & Dtors ___________
ACollectableItem::ACollectableItem() {};

ACollectableItem::ACollectableItem(Point & pos) : AItem(pos), assigned(false) {}

ACollectableItem::ACollectableItem(const ACollectableItem & other)
{
	copyVal(other); 
}

ACollectableItem::~ACollectableItem(){}

// _________ Methods ___________
bool ACollectableItem::isAssigned(){return assigned;}
void ACollectableItem::markAsAssigned(){assigned = true;}
void ACollectableItem::markAsUnAssigned() { assigned = false; }
void ACollectableItem::copyVal(const ACollectableItem & other)
{
	this->position = other.position;
	this->assigned = other.assigned;
}
;
