#include "employee.h"

inline void print(const Employee& emp)
{
    std::cout << emp.getName() << ": " << emp.getId() << std::endl;
}

int main()
{
    Employee e1("zhang liang", "001");
    Employee e2(e1); // copy ctr
    Employee e3("tang sai", "002");
    e3 = e2; // copy assignment operator

    print(e1);

    print(e2);

    return 0;
}
