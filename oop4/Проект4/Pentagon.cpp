#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "Pentagon.h"


Pentagon::Pentagon():Pentagon(0)
{
}

Pentagon::Pentagon(size_t i) : side_a(i)
{
	//std::cout << "Pentagon created: " << side_a  << std::endl;
 	if (side_a < 0 ) {
 		std::cerr << "Error: sides must be >= 0." << std::endl;
 		side_a = 0;
 	}
}

Pentagon::Pentagon(std::istream& is)
{
	is >> side_a;
	if (side_a < 0 ) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		side_a = 0;
	}
}

Pentagon::Pentagon(const Pentagon& orig)
{
	side_a = orig.side_a;
	std::cout << "Pentagon copy created." << std::endl;
}

size_t Pentagon::Square()
{
	return (5 / 2) * side_a * side_a * sin(72);
}

void Pentagon::Print()
{
	std::cout << "a = " << side_a  << std::endl;
}

Pentagon::~Pentagon()
{
	//std::cout << "Pentagon deleted." << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Pentagon & right)
{
	os << "Pentagon with side a = " << right.side_a ;
	return os;
}
