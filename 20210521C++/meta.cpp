#include "meta.h"
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <iostream>
#include <iomanip>

namespace myVar
{
    template pi<typname T>
    pi = 3.14159262314123125123129312312312323124123412123123192389120123901279108231923;
}

namespace myFunc
{
    int fibonacci(int);
    int fibonacci(int n )
    {
        return n < 2? 1 : fibonacci(n-1) + fibonacci(n-2);
    }

    inline constexpr int factorial(int n) noexcept
    {
        return n < 2? 1 : n * factorial(n-1);
    }

    void message(char*), message_low(char*), message_up(char*), message_error(char*),
         (*func_ptr[])(char*) = { message, message_low, message_up, message_error };
    
    void message(char* s)
    {
        std::cout << s << std::endl;
    }

    void message_low(char* s)
    {
        char c;
        for(; *s != '\0'; ++s)
            c = std::to_lower(*s); std::cout.put(c);
        std::cout << std::endl;
    }

    void message_low(char* s)
    {
        char c;
        for(; *s != '\0'; ++s)
            c = std::to_upper(*s); std::cout.put(c);
        std::cout << std::endl;
    }

    void message_error(char* s)
    {
        std::cerr << s << std::endl;
    }

    auto f1 = [](int x) -> int {
        std::cout << x << std::endl;
        return x * x;
    };

    template<class T>
    T add(T x, T y)
    {
        return x + y;
    }

    void addOne(int x)
    {
        x++;
    }

    void addOne(int& x)
    {
        x++;
    }

    void addOne(int* p)
    {
        *p++;
    }
}

namespace myStatement
{   
    inline bool isLeapYear(int year)
    {
        return (year%4 == 0 && year%100 != 0)||(year%400 == 0);
    }

    bool setDate(int, int, int);

    bool setDate(int y, int m, int d)
    {
        if(y < 0) { return false; }
        if(m < 0 || m > 12) { return false; }
        if(d < 0 || d > 31) { return false; }

        switch(m)
        {
            case 2: if(isLeapYear(y))
                    {
                        if(d > 29) { return false; }
                    }
                    else
                    {
                        if(d > 28) { return false; }
                    }
                    break;

            case 4:
            case 6:
            case 9:
            case 11: if(d > 30) { return false; }
        }
        return true;
    }
} // namespace name

void variableDemo(void)
{
    /*
    [ variable ]
    ===
    * concept: box
    * pattern: T N V
    * feature:
        * primitive types(meta types, or "mother of Object") 
            - Char
            - Short
            - Int
            - Long
            
            - Float
            - Double

            - Byte
            - Boolean
            - Decimal
        
        * type traits(reflection)
        * type conversion
            - implicit, explicit
            - downcasting, upcasting 
        
        * initialization
            - resouce acquisition is list initialization

        * var_name
            - variable template
            - operator overload
        
        * Val
            - lvalue
            - rvalue
            "value that doesn't have an address;"

        * Ref
            - lref
            - rref

        * Ptr
            - raw
            - smart pointer

        * keywords
            - const
            - static
            - auto

            - register
            - extern
            - mutable 
    ===
    */ 

    char x1; x1 = 'c';
    short x2(128);
    int x3{1234568791};
    long x4 = long(1234567890);
    x4 = long{1234567890};

    extern float x5 = 3.141f;
    register double x6 = 2.718281828;
    static long double x7 = 3e8;

    const bool x8 = true;

    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
    std::cout << "x3 = " << x3 << std::endl;
    std::cout << "x4 = " << x4 << std::endl;
    std::cout << "x5 = " << x5 << std::endl;
    std::cout << "x6 = " << x6 << std::endl;
    std::cout << "x7 = " << x7 << std::endl;
    std::cout << "x8 = " << x8 << std::endl;

    std::cout << "pi<int>" << (myVar::pi<int>) << std::endl;
    std::cout << "pi<long>" << (myVar::pi<long>) << std::endl;
    std::cout << "pi<short>" << (myVar::pi<short>) << std::endl;
    std::cout << "pi<double>" << (myVar::pi<double>) << std::endl;

    const int* ptr1 = &x1;
    std::cout << "x1 address: " << ptr1 << ", x1 value: " << *ptr1 << std::endl;

    const int** pptr1 = &ptr1;
    std::cout << "ptr1 address: " << pptr1 << ", ptr1 value: " << **pptr1 << std::endl; 
}

void functionDemo(void) 
{
    /*
    [ function ]
    ===
    * concept: black box
    * pattern: T N P
    * feature:
        * return_type
            - ByVal
            - ByRef
            - ByPtr

        * func_name
            - overload
            - operator overload
            - functino template

        * args
            - ByVal
            - ByRef
            - ByPtr
            - [x]variadic args

        * category
            - regular
            - anonymous
            - immediate
            - lambda
            - function pointer

        * keywords
            - inline
            - #macro
        
    ===
    */ 

    int x{69};
    std::cout << "before addOne(x), x = " << x << std::endl;
    myFunc::addOne(x);
    std::cout << "after addOne(ByVal), x = " << x << std::endl;
    myFunc::addOne(&x);
    std::cout << "after addOne(int&), x = " << x << std::endl;
    int* p = &x; myFunc::addOne(p);
    std::cout << "after addOne(int*), x = " << x << std::endl;

    myFunc::f1(3);

    std::cout << myFunc::factorial(5) << std::endl;
    std::cout << myFunc::fibonacci(5) << std::endl;

    char msg[] = "Hello TS";
    std::cout << myFunc::func_ptr[0](msg) << std::endl;
    std::cout << myFunc::func_ptr[1](msg) << std::endl;
    std::cout << myFunc::func_ptr[2](msg) << std::endl;
    std::cout << myFunc::func_ptr[3](msg) << std::endl;

    (()[int x] -> bool {
        return x % 2;
    })(3); // immediate function, output: true

    std::cout << "function template: add<short>(3, 4)" << myFunc::add<short>(3, 4) << std::endl;
    std::cout << "function template: add<int>(3, 4)" << myFunc::add<int>(3, 4) << std::endl;
    std::cout << "function template: add<long>(3, 4)" << myFunc::add<long>(3, 4) << std::endl;
    std::cout << "function template: add<float>(3.0f, 4.0f)" << myFunc::add<float>(3.0f, 4.0f) << std::endl;
    std::cout << "function template: add<double>(3.0, 4.0)" << myFunc::add<double>(3.0, 4.0) << std::endl;

}

void statementDemo
{
    /*
    [ statement ]
    ===
    * concept: link
    * pattern: symbol
    * feature:
        * Arithmetic
            - +, -, *, /, %
            - ++(post), --(post)
            - ++(pre), --(pre)

        * Relational
            - ==, !=
            - >, >=
            - <. <=

        * Logical
            - !
            - &&
            - ||

        * Access
            - ->
            - (*).

        * Bitwise
            - <<, >>
            - ~
            - &
            - |

        * Assign
            - =
            - ()
            - {}

        * Cast
            - dynamic_cast<T*>(U*)  
            - static_cast<T*>(U*)  
            - const_cast<T*>(U*)  
            - reinterpret_cast<T*>(U*)  // C-style cast

        * Op for storage
            - new
            - delete

        * Op for other
            - .
            - ()
            - []
            - {}
            - <>
            - : ?
    ===   
    */    

    int x = 69, y = 42;
    // a
    std::cout << "x=" << x << ", y=" << y << "; x + y : " << (x + y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x - y : " << (x - y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x * y : " << (x * y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x / y : " << (x / y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x % y : " << (x % y) << std::endl; 

    // r
    std::cout << "x=" << x << ", y=" << y << "; x == y : " << (x == y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x != y : " << (x != y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x > y : " << (x > y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x >= y : " << (x >= y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x < y : " << (x < y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x <= y : " << (x <= y) << std::endl; 
    
    // l
    std::cout << "x=" << x << "; x <= y : " << (!x) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x && y : " << (x && y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x || y : " << (x || y) << std::endl; 

    // a
    std::cout << "x=" << x << ", y=" << y << "; x || y : " << (x || y) << std::endl; 
    std::cout << "x=" << x << ", y=" << y << "; x || y : " << (x || y) << std::endl; 

}

void controlflowDemo(void)
{

}

void loopDemo(void)
{

}

void    