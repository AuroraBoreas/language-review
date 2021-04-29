#include <iostream>
#include "meta.h"

int main()
{
    std::cout << "\n=== meta: variable ===" << std::endl;
    variableDemo();

    std::cout << "\n=== meta: function ===" << std::endl;
    functionDemo();

    std::cout << "\n=== meta: statement ===" << std::endl;
    statementDemo();

    std::cout << "\n=== meta: controlflow ===" << std::endl;
    controlflowDemo();

    std::cout << "\n=== meta: loop ===" << std::endl;
    loopDemo();

    std::cout << "\n=== meta: class ===" << std::endl;
    classDemo();

    std::cout << "\n=== meta: io ===" << std::endl;
    ioDemo();

    std::cout << "\n=== meta: data structure ===" << std::endl;
    datastructureDemo();

    std::cout << "\n=== meta: algorithm ===" << std::endl;
    algorithmDemo();

    return 0;
}
