#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(size_t i, size_t j, size_t k);
	Pentagon(const Pentagon& orig);

	Pentagon& operator++();
	Pentagon& operator=(const Pentagon& right);

	friend Pentagon operator+(const Pentagon& left, const Pentagon& right);
	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator >> (std::istream& is, Pentagon& obj);
	friend bool operator>(const Pentagon& left, const Pentagon& right);
	friend bool operator<(const Pentagon& left, const Pentagon& right);
	friend bool operator==(const Pentagon& left, const Pentagon& right);

	int32_t Side() override;
	double Square() override;
	void Print() override;
	virtual ~Pentagon();
private:
	size_t side_a;
	size_t side_b;
	size_t side_c;
};

#endif /* PENTAGON_H */