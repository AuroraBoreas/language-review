/*

this module is to demonstrate interface concept in C++

@ZL, 20210526

[ conclusion ]
===
- C++ does not support interface
- but it does have a walkaround, using class
===

*/

#include <string>
#include <iostream>

struct Pack {
    virtual std::string start(void) = 0;
};

class Carton: public Pack
{
    private:
        std::string m_name;
        int m_age;

    public:
        Carton(const std::string& name, int age)
        : m_name(name), m_age(age)
        {}

        std::string start(void) override
        {
            return "class Carton says hello";
        }
};

int main()
{
    Carton* c = new Carton("TS", 30);
    std::cout << c->start() << std::endl;

    delete c;

    return 0;
}
