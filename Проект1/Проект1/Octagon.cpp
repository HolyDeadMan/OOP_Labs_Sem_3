#include <iostream>
#include <cmath>
#include "Octagon.h"


Octagon::Octagon():Octagon(0, 0)
{
}

Octagon::Octagon(size_t i, size_t j) : side_a(i), side_b(j)
{
	std::cout << "Octagon created: " << side_a << ", " << side_b  << std::endl;
}

Octagon::Octagon(std::istream& is)
{
	is >> side_a;
	is >> side_b;
	std::cout << "Octagon created: " << std::endl;
}

Octagon::Octagon(const Octagon& orig)
{
	side_a = orig.side_a;
	side_b = orig.side_b;
	std::cout << "Octagon copy created." << std::endl;
}

double Octagon::Square()
{
	std::cout << "sq = ";
	return 2 * side_a * side_b;
}

void Octagon::Print()
{
	std::cout << "a = " << side_a << " b = " << side_b << std::endl;
}

Octagon::~Octagon()
{
	std::cout << "Octagon deleted." << std::endl;
}
