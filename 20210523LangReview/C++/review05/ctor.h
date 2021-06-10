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
            std::cout << "default ctor.." << std::endl;
            this->ptr = new int;
        }

        // regular ctor
        Base(const int& i)
        {
            std::cout << "regular ctor.." << std::endl;
            this->ptr = new int(i);
        }

        // copy ctor
        Base(Base& b)
        : ptr(b.ptr)
        {
            std::cout << "copy ctor.." << std::endl;
        }

        // copy assignment ctor
        Base& operator=(Base& b)
        {
            std::cout << "copy assignment op.." << std::endl;
            std::swap(this->ptr, b.ptr);
            return *this;
        }

        // move ctor
        Base(Base&& b)
        : ptr(std::move(b.ptr))
        {
            std::cout << "move ctor.." << std::endl;
        }

        // move assignment ctor
        Base& operator=(Base&& b)
        {
            std::cout << "move assignment op.." << std::endl;
            this->ptr = std::move(b.ptr);
            return *this;
        }

        // dtor
        ~Base()
        {
            std::cout << "dtor.." << std::endl;
            delete this->ptr;
        }
    };
}

#endif // CTOR_H_INCLUDED
