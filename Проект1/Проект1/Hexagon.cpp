#include <iostream>
#include <cmath>
#include "Hexagon.h"

Hexagon::Hexagon() : Hexagon(0)
{
}

Hexagon::Hexagon(size_t i) : side_a(i)
{
	std::cout << "Hexagon created: " << side_a << std::endl;
}

Hexagon::Hexagon(std::istream &is)
{
	is >> side_a;
	std::cout << "Hexagon created: " << std::endl;
}

Hexagon::Hexagon(const Hexagon& orig)
{
	std::cout << "Hexagon copy created." << std::endl;
	side_a = orig.side_a;
}

double Hexagon::Square()
{
	std::cout << "sq = ";
	return  (3* sqrt(3) * side_a * side_a) / 2;
}

void Hexagon::Print()
{
	std::cout << "a = " << side_a << std::endl;
}

Hexagon::~Hexagon()
{
	std::cout << "Hexagon deleted." << std::endl;
}
