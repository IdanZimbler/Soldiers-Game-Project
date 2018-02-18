#pragma once
#include <iostream>
using namespace std;

// Interface that presents the final output of the game
class IOutput

{
public:
	//___________Dtor___________
	virtual ~IOutput();

	//___________Methods___________
	friend ostream& operator<<(ostream& out, const IOutput& o)
	{
		o.print(out);
		return out;
	}
	virtual string endOfGame() = 0;

private:
	//___________Private method___________
	virtual void print(ostream&) const = 0;
};