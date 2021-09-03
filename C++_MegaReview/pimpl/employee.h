#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>
#include <iostream>

class Employee
{
private:
    std::string m_name;
    std::string m_id;
public:
    Employee(std::string, std::string);
    Employee(const Employee& other);
    Employee& operator=(Employee& rhs);
    ~Employee();
    std::string getName(void) const;
    std::string getId(void) const;
};

#endif // EMPLOYEE_H_INCLUDED
