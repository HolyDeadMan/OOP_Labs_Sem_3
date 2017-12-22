#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon :
	public Figure
{
public:
	Pentagon();
	Pentagon(size_t side_a);
	Pentagon(std::istream &is);
	Pentagon(const Pentagon& orig);

	double Square() override;
	void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Pentagon& right);

	virtual ~Pentagon();
private:
	size_t side_a;
	size_t side_b;
};
#endif 
