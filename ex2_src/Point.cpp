#include "Point.h"

// _________ Ctors & Dtors ___________
Point::Point() {};
Point::Point(double x, double y) : x(x), y(y) {};
Point::Point(const Point& other) { copyVal(other); };

// Calculates distance between two points
double Point::calcDistance(const Point& pos1, const Point& pos2)
{
	double distanceX = std::pow((pos1.getX() - pos2.getX()),2) ;
	double distanceY = std::pow((pos1.getY() - pos2.getY()),2) ;
	return std::sqrt(distanceX + distanceY);
	
}
// Calculates angle between two points
double Point::calcAngle(const Point & p1, const Point & p2)
{
	double  rad = atan2(p2.getY() - p1.getY(), p2.getX() - p1.getX());
	double test = atan2(7, 8);
	return rad;
};


// _________ Getters & Setters ___________
double Point::getX() const { return this->x; };
double Point::getY() const { return this->y; };
void Point::setX(double value) { this->x = value; };
void Point::setY(double value) { this->y = value; };

// _________ Methods ___________
string Point::toString() const{return "[" + to_string(x) + " " + to_string(y) + "]";}
void Point::copyVal(const Point & point)
{
	this->x = point.x;
	this->y = point.y;
}



