#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <memory>

class Employee
{
private:
    struct Impl;
    std::unique_ptr<Impl> pimpl;

public:
    Employee(const std::string& name, const std::string& id);
    Employee(const Employee& other);
    Employee& operator=(Employee& rhs);
    ~Employee();
    std::string getName(void) const;
    std::string getId(void) const;
};

#endif // EMPLOYEE_H_INCLUDED
