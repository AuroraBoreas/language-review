#include "employee.h"

Employee::Employee(std::string name, std::string id)
: m_name(name), m_id(id) {}

Employee::Employee(const Employee& other)
: m_name(other.m_name), m_id(other.m_id)
{ std::cout << "copy ctr" << std::endl; }

Employee& Employee::operator=(Employee& rhs)
{
    std::cout << "copy assignment ctr" << std::endl;
    std::swap(m_name, rhs.m_name);
    std::swap(m_id, rhs.m_id);
    return *this;
}

Employee::~Employee(){};

std::string Employee::getName(void) const
{
    return m_name;
}

std::string Employee::getId(void) const
{
    return m_id;
}
