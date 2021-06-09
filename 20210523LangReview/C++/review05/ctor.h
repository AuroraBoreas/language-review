#ifndef CTOR_H_INCLUDED
#define CTOR_H_INCLUDED

#include <iostream>

namespace TS
{
    struct Base
    {
    private:
        int* ptr;
    public:
        // default ctor
        Base()
        {
            std::cout << "default ctor..." << std::endl;
            this->ptr = new int;
        }
        // regular ctor
        Base(const int& i)
        {
            std::cout << "regular ctor..." << std::endl;
            this->ptr = new int(i);
        }

        // copy ctor
        Base(Base& b)
        {
            std::cout << "copy ctor..." << std::endl;
            std::swap(this->ptr, b.ptr);
            b.ptr = nullptr;
        }
        // copy assignment ctor
        Base& operator=(Base& b)
        {
            std::cout << "copy assignment ctor..." << std::endl;
            std::swap(this->ptr, b.ptr);
            b.ptr = nullptr;
            return *this;
        }

        // move ctor
        Base(Base&& b)
        {
            std::cout << "move ctor..." << std::endl;
            this->ptr = std::move(b.ptr);
            b.ptr = nullptr;
        }

        // move assignment ctor
        Base& operator=(Base&& b)
        {
            std::cout << "move assignment ctor..." << std::endl;
            this->ptr = std::move(b.ptr);
            b.ptr = nullptr;
            return *this;
        }
        // dtor
        ~Base()
        {
            std::cout << "dtor..." << std::endl;
            delete ptr;
        }
    };
}


#endif // CTOR_H_INCLUDED
