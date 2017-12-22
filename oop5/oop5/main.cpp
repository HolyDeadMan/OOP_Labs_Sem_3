#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "Pentagon.h"
#include "TBinaryTree.h"

void menu()
{
	std::cout << "List of operation:" << std::endl;
	std::cout << "1) Add Pentagon" << std::endl;
	std::cout << "2) Add Octagon" << std::endl;
	std::cout << "3) Add Hexagon" << std::endl;
	std::cout << "4) Remove the pieces of wood on the maximum side" << std::endl;
	std::cout << "5) Print tree" << std::endl;
	std::cout << "6) Print tree with iterator" << std::endl;
	std::cout << "0) exit" << std::endl;
}

int main(void)
{
	int act = 0;
	TBinaryTree<Figure> tree;
	std::shared_ptr<Figure> ptr;
	std::cout << "To access the menu, press 7" << std::endl;
	do {
		std::cin >> act;
		switch (act) {
		case 1:
			ptr = std::make_shared<Pentagon>(std::cin);
			tree.insert(ptr);
			break;
		case 2:
			ptr = std::make_shared<Octagon>(std::cin);
			tree.insert(ptr);
			break;
		case 3:
			ptr = std::make_shared<Hexagon>(std::cin);
			tree.insert(ptr);
			break;
		case 4:

			if (tree.empty()) {
				std::cout << "Tree is empty" << std::endl;
			}
			else {
				int32_t numb;
				std::cin >> numb;
				tree.remove(numb);
			}
			break;
		case 5:
			if (tree.empty()) {
				std::cout << "Tree is empty" << std::endl;
			}
			else {
				std::cout << tree << std::endl;
			}
			break;
		case 6:
			if (tree.empty()) {
				std::cout << "Tree is empty" << std::endl;
			}
			else {
				for (auto i : tree) {
					i->Print();
				}
				std::cout << std::endl;
				//tree.kek();
			}
			break;
		case 7:
			menu();
			break;
		case 0:
			tree.gg();
			break;
		default:
			std::cout << "This command does not exist" << std::endl;;
			break;
		}
	} while (act);
	system("PAUSE");
	return 0;
}