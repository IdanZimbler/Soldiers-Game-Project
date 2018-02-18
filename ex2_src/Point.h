#pragma once
#include <cmath>
#include <string>
using namespace std;

// Class to represent points.
class Point {
public:
	// _________ Ctors & Dtors ___________
	Point();
	Point(double x, double y);
	Point(const Point& other);

	// _________ Methods ___________
	Point& operator=(const Point& point)
	{
		if (this != &point)
		{
			copyVal(point);
		}
		return *this;
	};
	string toString() const;
	static double calcDistance(const Point& pos1, const Point& pos2);
	static double calcAngle(const Point& pos1, const Point& pos2);

	// _________ Getters & Setters ___________
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);

private:
	// _________ Members ___________
	double x;
	double y;
	void copyVal(const Point& point);
};
