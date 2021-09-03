/**\Review  @ ZL, 20210729
 * \concept pimpl -- pointer to implementation;
 * \what    move private data members in a separat class and access them via opaque pointer/reference;
 * \why     merit  : [*]avoid exposure of implementation, [*]reduce binary compile time;
            demerit: [x]inheritance, [x]memory management;
 * \how     as follows;
 */

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <memory>

namespace TS
{
    class Employee
    {
    private:
        struct Impl;
        std::unique_ptr<Impl> pimpl;
    public:
        Employee(std::string, std::string);
        Employee(const Employee& other);
        Employee& operator=(Employee& rhs);
        ~Employee();
        std::string getName(void) const;
        std::string getId(void) const;
    }; // class Employee
}; // namespace TS

#endif // EMPLOYEE_H_INCLUDED
