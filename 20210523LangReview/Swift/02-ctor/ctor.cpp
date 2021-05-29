/*

[ expriment result ]
===
- it turns out that C++ doesnt suppurt ctor inheritance
===
*/ 

#include <iostream>

class Base
{
private:
    int m_x;
public:
    Base(const int& x = 0)
    : m_x(x) {}

    virtual ~Base() {}
};

class Derived: public Baes {};

int main()
{
    Derived d1{1}; // error out; 
    
    return 0;
}