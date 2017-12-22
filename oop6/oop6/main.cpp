#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "TTree.h"
#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "Pentagon.h"
#include "TTree.h"

void menu()
{
    std::cout << "List of actions:" << std::endl;
    std::cout << "1) Add Pentagon" << std::endl;
    std::cout << "2) Add octagon" << std::endl;
    std::cout << "3) Add hexagon" << std::endl;
    std::cout << "4) Remove all shapes of the same type of wood. 1)Triangle 2)Octagon 3)Hexagon" << std::endl;
    std::cout << "5) Remove the pieces of wood on the maximum side" << std::endl;
    std::cout << "6) print tree"  << std::endl;
    std::cout << "0) exit" << std::endl;
}

int main(void)
{
    int act = 0, index;
    TTree<TTree<Figure>, std::shared_ptr<Figure>> tree;
    std::shared_ptr<Figure> ptr;
    std::cout << "To access the menu, press 7" << std::endl;
    do {
        std::cin >> act;
        switch(act) {
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
                std::cin >> index;
                tree.removeByType(index);
                break;
            case 5:
                int32_t numb;
                std::cin >> numb;
                tree.removeLesser(numb);
                break;
            case 6:
                tree.inorder();
                break;
            case 7:
                menu();
                break;
            case 0:
                tree.RM();
                break;
            default:
                std::cout << "This command does not exist" << std::endl;;
                break;
        }
    } while (act);
	system("PAUSE");
    return 0;
}