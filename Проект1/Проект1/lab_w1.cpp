// lab_w1.cpp: определяет точку входа .
//

#include <cstdlib>
#include "Pentagon.h"
#include "Octagon.h"
#include "Hexagon.h"

// Для правильного пятиугольника задаётся радиус описанной окружности.
// Для восьмиугольника задаётся меньшая из диагоналей(ширина восьмиугольника) и сторона.
// Для правильного шестиугольника нужно задать только одну сторону.
int main(int argc, char** argv)
{	
	std::cout << "Pentagon(write radius)" << std::endl;
	Figure *pentagon = new Pentagon(std::cin);
	pentagon->Print();
	std::cout << pentagon->Square() << std::endl;
	delete pentagon;

	std::cout << "Octagon(write diag and length)" << std::endl;
	Figure *octagon = new Octagon(std::cin);
	octagon->Print();
	std::cout << octagon->Square() << std::endl;
	delete octagon;

	std::cout << "Hexagon(write length)" << std::endl;
	Figure *hexagon = new Hexagon(std::cin);
	hexagon->Print();
	std::cout << hexagon->Square() << std::endl;
	delete hexagon;

	system("PAUSE");
	return 0;

}

