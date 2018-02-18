
#include "ASolidItem.h"

// _________ Ctors & Dtors ___________
ASolidItem::ASolidItem(){}
ASolidItem::ASolidItem(Point& pos, double h, double w) : AItem(pos), height(h), width(w){}
ASolidItem::~ASolidItem(){}
ASolidItem::ASolidItem(const ASolidItem & other)
{
	copyVal(other);
}

// _________ Getters & Setters ___________
double ASolidItem::getHeight() { return height; }
double ASolidItem::getWidth() { return width; }
void ASolidItem::setHeight(double height) { this->height = height; }
void ASolidItem::setWidth(double width) { this->width = width; }

// _________ Methods ___________
void ASolidItem::copyVal(const ASolidItem & other)
{
	this->position = new Point(*other.position);
	this->height = other.height;
	this->width = other.width;
}
