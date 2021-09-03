#include "employee.h"

struct Employee::Impl
{
    std::string m_name;
    std::string m_id;

    Impl(const std::string& name, const std::string& id)
    : m_name(name), m_id(id){}
}; // struct

Employee::Employee(const std::string& name, const std::string& id)
: pimpl(new Impl(name, id)){}

Employee::Employee(const Employee& other)
: pimpl(new Impl(*other.pimpl))
{
    std::cout << "copy ctr" << std::endl;
}

Employee& Employee::operator=(Employee& rhs)
{
    std::cout << "copy assignment operator" << std::endl;
    std::swap(pimpl, rhs.pimpl);
    return *this;
}

Employee::~Employee()=default;

std::string Employee::getName(void) const
{
    return pimpl->m_name;
}

std::string Employee::getId(void) const
{
    return pimpl->m_id;
}
