#include "employee.h"
#include <iostream>

int main()
{
    Employee e1("zhang liang", "001");
    Employee e2("ts", "002");

    std::cout << e1.getName() << " : " << e1.getId() << std::endl;
    e2 = e1;
    Employee e3(e1);
    std::cout << e2.getName() << " : " << e2.getId() << std::endl;

    std::cout << "\npress any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}
