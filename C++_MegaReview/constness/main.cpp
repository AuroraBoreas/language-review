#include <iostream>

int main()
{

//    int x(42);
//    const int(42);
//    int const x(42);
//    std::cout << "x++, x = " << ++x << std::endl;
    int x(42);
    const int* const p = &x;
    (*p)++;
    std::cout << x << std::endl;
//    std::cout << "addr of p : " << p << std::endl;
    return 0;
}
