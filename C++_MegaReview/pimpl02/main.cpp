#include <iostream>
#include "employee.h"

int main()
{
    TS::Employee e1{"zhang liang", "0001"};
    TS::Employee e2(e1);
    TS::Employee e3("hello world", "0002");
    e3 = e2;

    std::cout << e3.getName() << " : " << e3.getId() << std::endl;

    std::cout << "\npress any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}
