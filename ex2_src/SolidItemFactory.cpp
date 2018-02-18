#include "SolidItemFactory.h"

// Making Solid item depends on which item is requested 
// (at the moment Tree is the only solid item)
ASolidItem * SolidItemFactory::makeSolidItem(string * newSolidItemType, Point & pos, double h, double w)
{
	if (newSolidItemType == nullptr) return nullptr;
	if (newSolidItemType->compare("Tree") == 0) return new Tree(pos,h,w);
	else throw invalid_argument("bad solid item arguments");
}
