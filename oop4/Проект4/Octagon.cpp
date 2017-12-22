#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "Octagon.h"

Octagon::Octagon() : Octagon(0, 0)
{
}

Octagon::Octagon(double i, double j) : side_a(i), side_b(j)
{
	//std::cout << "Octagon created: " << side_a << ", " << side_b << std::endl;
}

Octagon::Octagon(std::istream &is)
{
	is >> side_a;
	is >> side_b;
	if (side_a < 0 || side_b < 0) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		side_a = 0;
		side_b = 0;
	}
}

Octagon::Octagon(const Octagon& orig)
{
	std::cout << "Octagon copy created." << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	if (side_a < 0 || side_b < 0) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		side_a = 0;
		side_b = 0;
	}
}

size_t Octagon::Square()
{
	return 2 * side_a * side_b;
}

void Octagon::Print()
{
	std::cout << "a = " << side_a << " b = " << side_b << std::endl;
}

Octagon::~Octagon()
{
	//std::cout << "Octagon deleted." << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Octagon & right)
{
	os << "Octagon with  a = " << right.side_a << ",  b = " << right.side_b;
	return os;
}
