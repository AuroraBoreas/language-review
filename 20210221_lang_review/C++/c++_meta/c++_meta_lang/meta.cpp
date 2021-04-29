#include "meta.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>
#include <ctime>

template<typename T>
T pi = 3.1415926887123101231234123123124124123d;

inline int fibonacci(int n)
{
    return n < 2? 1 : fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n);

int factorial(int n)
{
    return n < 2? 1: n * factorial(n-1);
}

void message(char*), message_error(char*),
     message_upper(char*), message_lower(char*);

void message(char* s)
{ std::cout << s << std::endl; }

void message_eror(char* s)
{ std::cerr << s << std::endl; }

void message_upper(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = std::toupper(*s); std::cout.put(c);
    }
    std::cout << std::endl;
}

void message_lower(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = std::tolower(*s); std::cout.put(c);
    }
    std::cout << std::endl;
}

typedef void (*func_ptr)(char*);

template<class T>
T square(T x, T y)
{
    return x * x + y * y;
}

struct Point
{
    int x = 1;
    int y = 1;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    std::string ToString(void) const
    {
        std::stringstream ss;
        ss << "Point[" << this->x << ", " << this->y << "]";
        return ss.str();
    }
};

class Date
{
private:
    unsigned year;
    unsigned month;
    unsigned day;

public:
    // ctor
    Date()
    {
        this->year = 1;
        this->month = 1;
        this->day = 1;
    }

    Date(unsigned y, unsigned m, unsigned d)
    {
        if(!setDate(y, m, d))
            year = month = day = 1;

        this->year  = y;
        this->month = m;
        this->day   = d;
    }

    bool isLeapYear(unsigned year) const
    {
        return (year%4 == 0 && year%100 !=0) || (year%400 == 0);
    }

    bool setDate(unsigned y, unsigned m, unsigned d) const
    {
        if(m > 12) { return false; }
        if(d > 30) { return false; }
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

    void setDate(void)
    {
        struct tm *tm;
        time_t sec; std::time(&sec);
        tm = std::localtime(&sec);

        this->year = tm->tm_year + 1930;
        this->month = tm->tm_mon + 1;
        this->day = tm->tm_mday;
    }
    // dtor
    virtual ~Date(){}
    // getter
    unsigned Year(void) const
    { return this->year; }
    unsigned Month(void) const
    { return this->month; }
    unsigned Day(void) const
    { return this->day; }
    // setter
    void Year(unsigned y)  { this->year = y; }
    void Month(unsigned m) { this->month = m; }
    void Day(unsigned d)   { this->day = d; }
    // repr
    std::string ToString(void) const
    {
        std::stringstream ss;
        ss << std::setw(4) << std::setfill('0') << this->year << "-"
           << std::setw(2) << std::setfill('0') << this->month << "-"
           << std::setw(2) << std::setfill('0') << this->day;

        return ss.str();
    }

};


void variableDemo(void)
{
    /*
    [ variable ]
    ===
    - concept: box
    - pattern: T N V
    - feature:
        -- primitive types:
            * CSIL
            * FD
            * BBD

        -- initialization:
            * late
            * early binding
            * lvalue, lvalue reference
            * rvalue, rvalue reference
                -- extends --
                * class constructors:
                    -- default ctor
                    -- default dtor
                    -- copy ctor
                    -- copy assignment ctor
                    -- move ctor
                    -- move assignment ctor

        -- variable template
            * C++ >= 14
            * compile time
    ===
    */

    char x1 = 'a';
    short x2; x2 = 128;
    int x3 = 69;
    long x4 = 12345678910;
    float x5 = 3.14f;
    double x6 = 2.718281828d;
    bool x7 = true;

    std::cout << x1 << std::endl;
    std::cout << std::boolalpha << x7 << "\n";

    std::cout << pi<int> << std::endl;
    std::cout << pi<long> << std::endl;
    std::cout << pi<float> << std::endl;
    std::cout << pi<double> << std::endl;
    std::cout << pi<long double> << std::endl;
}

void functionDemo(void)
{
    /*

    [ function ]
    ===
    - concept: black box
    - pattern: T N P
    - feature:
        -- category:
            - [*] regular
            - [*] anonymous
            - [*] immediate
            - [*] lambda
            - [x] generator
            - [x] decorator
            - [x] function inside function
            - [x] class inside function
            - [*] function pointer
            - [*] macro
            - [*] inline
            - [*] prototype(declaration, definition)

        -- return_value:
            * ByVal
            * ByRef
            * ByPtr

        -- function name:
            * overloading
            * class method overloading

        -- args:
            * param array
            * passing args by:
                -- ByVal
                -- ByRef
                -- ByPtr

            * when passing array:
                -- array will decay into pointer;

        -- function template:
            * C++ >= 14
            * compile time
    ===
    */
    char s[] = "hello world!";
    func_ptr f1 = message;
    f1(s);
    char e[] = "error out";
    func_ptr f2 = message_eror;
    f2(e);
    func_ptr f3 = message_lower;
    f3(s);
    func_ptr f4 = message_upper;
    f4(s);
}

void statementDemo(void)
{
    /*

    [ statement ]
    ===
    - concept: connection
    - pattern: symbol
    - feature:
        -- Arithmetic
        -- Relational
        -- Logical
        -- Access
        -- Bitwise
        -- Assign
        -- Cast
            * dynamic_cast
            * static_cast
            * const_cast
            * reinterpret_cast

        -- Operator for storage

        -- Operator for other

    ===

    */

    int x(42), y = 69;

    // arithmetic
    std::cout << "x = " << x << "y = " << y  << "x + y = " << (x+y) << std::endl;

    // relational
    std::cout << std::boolalpha << (x < y) << std::endl;

    // logical
    std::cout << !x << std::endl;

    // access
    Point p1{2, 3};
    std::cout << p1.x << ", " << p1.y << std::endl;
    std::cout << p1.ToString() << std::endl;

    // bitwise
    x <<= 2;
    std::cout << "x << 2: " << x << std::endl;

    // assign
    int numbers[] = { 1, 2, 3 };
    for(int i=0; i<3; ++i)
    {
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;

    // cast
    int a = 69;
    const int *ptr = &a;

    std::cout << "the address of integer a: " << ptr << std::endl;
    std::cout << "the value of the address: " << *ptr << std::endl;

    ptr++; // error out

    // operator for storage
    Point *p2 = new Point{4, 5};
    std::cout << p2->ToString() << std::endl;
    delete p2;

    // operator for other: ternary, dot, arrow,

}

void controlflowDemo(void)
{
    /*

    [ controlflow ]
    ===
    - concept: choose
    - pattern: branch
    - feature:
        * if...else if...else;
        * switch...case...default;
        * try...catch...finally;

        * performance aspect:
            -- switch..case..default may be better;
            -- in C#, pattern match is a thing;
    ===
    */
    Date *dates[] = {
        new Date(),
        new Date(2021, 1, 1),
        new Date(2022, 10, 12),
    };

    for(int i=0; i<3; ++i)
    {
        std::cout << dates[i]->ToString() << std::endl;
    }

    delete dates;
}

void loopDemo(void)
{
    /*

    [ loop ]
    ===
    - concept: loop
    - pattern: loop
    - feature:
        * for
        * foreach
        * while
        * do...while
    ===

    */

    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(int i=0; i<10; ++i)
    {
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;

    for(auto& elem: numbers)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    int i = 9;
    while(i > 0)
    {
        std::cout << numbers[i] << ' ';
        --i;
    }
    std::cout << std::endl;

    do
    {
        std::cout << numbers[i] << ' ';
        i++;
    } while (i < 10);
    std::cout << std::endl;

}

void classDemo(void)
{
    Date dates[] = {
        Date(),
        Date(2021, 1, 1),
        Date(2021, 10, 12),
    };

    for(int i=0; i<3; ++i)
    {
        std::cout << dates[i].ToString() << std::endl;
    }
}

void ioDemo(void)
{
    /*

    [ io ]
    ===
    - concept: input and output
    - pattern: stream
    - feature:
        * iostream
        * sstream
        * bytestream
        * buffer
    ===

    */
}

void datastructureDemo(void)
{
    /*
    [ data structure ]
    ===
    - concept: container
    - pattern: T N V
    - feature:
        * compiler interpret: onion
        * seq
            -- std::array
            -- std::list
            -- std::forward_list
            -- std::dequeue

        * adapter
            -- std::stack
            -- std::queue
            -- std::priority_queue

        * associative
            -- std::map
            -- std::multimap
            -- std::set
            -- std::multiset
    ===

    */
}

void algorithmDemo(void)
{
    /*

    [ algorithm ]
    ===
    - concept: algorithm
    - pattern: algorithm
    - feature:
        * Iterator, const_iterator
        * Capacity
        * Access
        * Modifier
        * List observation
        * Bucket
        * Hash policy
    ===
    */
}
