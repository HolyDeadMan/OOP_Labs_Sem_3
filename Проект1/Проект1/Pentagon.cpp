#include <iostream>
#include <cmath>
#include "Pentagon.h"

Pentagon::Pentagon() : Pentagon(0)
{
}

Pentagon::Pentagon(size_t i) : side_a(i)
{
	std::cout << "Pentagon created: " << side_a <<  std::endl; 
}

Pentagon::Pentagon(std::istream &is)
{
	is >> side_a;
	std::cout << "Pentagon created: " << std::endl;
}

Pentagon::Pentagon(const Pentagon& orig)
{
	std::cout << "Pentagon copy created." << std::endl;
	side_a = orig.side_a;
}

double Pentagon::Square() 
{
	std::cout << "sq = ";
	return (5 / 2) * side_a * side_a * sin(72);
}

void Pentagon::Print()
{
	std::cout << "a = " << side_a  << std::endl;
}

Pentagon::~Pentagon()
{
	std::cout << "Pentagon deleted." << std::endl;
}
