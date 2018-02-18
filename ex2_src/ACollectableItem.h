#pragma once
#include "AItem.h"


// Abstract class for all kinds of Collectable items
class ACollectableItem : public AItem{

public:
	// _________ Ctors & Dtors ___________
	ACollectableItem();
	ACollectableItem(Point& pos);
	ACollectableItem(const ACollectableItem& other);
	virtual ~ACollectableItem();
	virtual ACollectableItem* clone() const = 0;

	// _________ Methods ___________
	ACollectableItem& operator=(const ACollectableItem& other)
	{
		if (this != &other)
		{
			copyVal(other);
		}
		return *this;
	};
	virtual string toString() = 0; 
	bool isAssigned();
	void markAsAssigned();
	void markAsUnAssigned();

protected:
	virtual void copyVal(const ACollectableItem& other);

private:
	// _________ Members ___________
	bool assigned;
};

