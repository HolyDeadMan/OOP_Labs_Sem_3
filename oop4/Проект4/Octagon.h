#ifndef OCTAGON_H
#define OCTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Octagon :
	public Figure
{
public:
	Octagon();
	Octagon(double side_a, double side_b);
	Octagon(std::istream &is);
	Octagon(const Octagon& orig);

	size_t  Square() override;
	void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Octagon& right);

	virtual ~Octagon();
private:
	double side_a;
	double side_b;
};
#endif // !HEXAGON.H

