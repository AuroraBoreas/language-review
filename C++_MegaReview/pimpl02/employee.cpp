#include "employee.h"

struct TS::Employee::Impl
{
    std::string m_name;
    std::string m_id;

    Impl(std::string name, std::string id)
    : m_name(name), m_id(id)
    {}
}; // private impl

TS::Employee::Employee(std::string name, std::string id)
: pimpl(new Impl(name, id))
{}

TS::Employee::Employee(const TS::Employee& other)
: pimpl(new Impl(*other.pimpl))
{ std::cout << "copy ctr" << std::endl; }

TS::Employee& TS::Employee::operator=(TS::Employee& rhs)
{
    std::cout << "copy assignment ctr" << std::endl;
    std::swap(pimpl, rhs.pimpl);
    return *this;
}

TS::Employee::~Employee()=default; /// required when using smart pointers to manage memory allocation;

std::string TS::Employee::getName(void) const
{
    return pimpl->m_name;
}

std::string TS::Employee::getId(void) const
{
    return pimpl->m_id;
}
