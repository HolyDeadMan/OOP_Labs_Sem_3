#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "Hexagon.h"

Hexagon::Hexagon() : Hexagon(0)
{
}

Hexagon::Hexagon(size_t  i) : side_a(i)
{
	//std::cout << "Hexagon created: " << side_a  << std::endl;
}


Hexagon::Hexagon(const Hexagon& orig)
{
	//std::cout << "Hexagon copy created." << std::endl;
	side_a = orig.side_a;
}

size_t  Hexagon::Square()
{
	return  (3 * sqrt(3) * side_a * side_a) / 2;
}

void Hexagon::Print()
{
	std::cout << "a = " << side_a  << " square = " << this->Square() << std::endl;
}

Hexagon & Hexagon::operator=(const Hexagon & right)
{
	if (this == &right)
		return *this;
	//std::cout << "Hexagon copy created." << std::endl;
	side_a = right.side_a;
}

Hexagon::~Hexagon()
{
	//std::cout << "Hexagon deleted." << std::endl;
}


std::ostream & operator<<(std::ostream & os, const Hexagon & right)
{
	os << "Hexagon with a = " << right.side_a << ",  Square = " << (3 * sqrt(3) * right.side_a * right.side_a) / 2 << std::endl;
	return os;
}

std::istream & operator>>(std::istream & is, Hexagon & right)
{
	is >> right.side_a;
	if (right.side_a < 0 ) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		right.side_a = 0;
	}
	return is;
}

bool operator==(const Hexagon & left, const Hexagon & right)
{
	return (left.side_a == right.side_a );
}
