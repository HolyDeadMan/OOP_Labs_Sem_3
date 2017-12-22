#include <iostream>
#include <cmath>
#include "Pentagon.h"

Pentagon::Pentagon() : Pentagon(0, 0, 0)
{
}

Pentagon::Pentagon(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k)
{
	std::cout << "Pentagon created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Pentagon::Pentagon(std::istream &is)
{
	is >> side_a;
	is >> side_b;
	is >> side_c;
}

Pentagon::Pentagon(const Pentagon& orig)
{
	std::cout << "Pentagon copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

int32_t Pentagon::Side()
{
	if (side_a >= side_b && side_a >= side_c) {
		return side_a;
	}
	else if (side_b >= side_a && side_b >= side_c) {
		return side_b;
	}
	else {
		return side_c;
	}
}

double Pentagon::Square()
{
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

std::ostream& operator<<(std::ostream& os, const Pentagon& obj)
{
	os << "a=" << obj.side_a << ", b=" << obj.side_b << ", c=" << obj.side_c << std::endl;
	return os;
}

void Pentagon::Print()
{
	std::cout << "Side_A = " << side_a << ", Side_B = " << side_b << ", Side_C = " << side_c << std::endl;
}

Pentagon::~Pentagon()
{
	//std::cout << "Pentagon deleted" << std::endl;
}

Pentagon& Pentagon::operator=(const Pentagon& right)
{
	if (this == &right) return *this;
	std::cout << "Pentagon copied" << std::endl;
	side_a = right.side_a;
	side_b = right.side_b;
	side_c = right.side_c;
	return *this;
}

Pentagon& Pentagon::operator++()
{
	side_a++;
	side_b++;
	side_c++;
	return *this;
}

Pentagon operator+(const Pentagon& left, const Pentagon& right)
{
	return Pentagon(left.side_a + right.side_a, left.side_b + right.side_b, left.side_c + right.side_c);
}

std::istream& operator >> (std::istream& is, Pentagon& obj)
{
	is >> obj.side_a;
	is >> obj.side_b;
	is >> obj.side_c;
	return is;
}

bool operator==(const Pentagon& left, const Pentagon& right)
{
	return (left.side_a == right.side_a) &&
		(left.side_b == right.side_b) &&
		(left.side_c == right.side_c);
}

bool operator>(const Pentagon& left, const Pentagon& right)
{

	return (left.side_a > right.side_a) ||
		(left.side_a == right.side_a && left.side_b > right.side_b) ||
		(left.side_a == right.side_a && left.side_b == right.side_b && left.side_c > right.side_c);
}

bool operator<(const Pentagon& left, const Pentagon& right)
{

	return (left.side_a < right.side_a) ||
		(left.side_a == right.side_a && left.side_b < right.side_b) ||
		(left.side_a == right.side_a && left.side_b == right.side_b && left.side_c < right.side_c);
}