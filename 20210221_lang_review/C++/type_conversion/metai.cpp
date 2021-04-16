#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>
#include <random>
#include <cstdlib>
#include <exception>
#include "meta.h"

template<typename T>
T pi = 3.1415926;

inline int constexpr square(int x)
{
    return x * x;
}

inline float constexpr addOne(int x)
{
    return ++x;
}

inline double constexpr mulTwo(int x)
{
    return x * 2;
}

typedef int (*func_ptr)(int x);
typedef float (*func_ptr_float)(int x);
typedef double (*funct_ptr_double)(int x);

template<class U>
inline U constexpr mul(U x, U y)
{
    return x * y;
}

inline void display(char* s)
{
    char c;
    for(; *s != '\0'; s++)
    {
        c = std::toupper(*s); std::cout.put(c);
    }
    std::cout << std::endl;
}

struct Point
{
    int x = 3;
    int y = 4;
};

struct Person
{
    std::string m_name;
    int m_age;

    Person(const std::string& name, const int age)
    {
        m_name = name; m_age = age;
    }

    std::string toString(void)
    {
        std::stringstream ss;
        ss << "\nname: " << this->m_name
            << "\nage: " << this->m_age;
        return ss.str();
    }
};

constexpr inline isLeapYear(int year) noexcept
{
    return (year%4==0 && year%100!=0) || (year%400==0);
}

class Animal
{
private:
    std::string m_name;
    std::string m_breed;
    int m_age;

public:
    // ctor
    Animal(const std::string& name,
           const std::string& breed,
           int age)
    {
        m_name = name;
        m_breed = breed;
        m_age = age;
    }
    Animal(const Animal& a)
    {
        m_name = a.Name();
        m_breed = a.Breed();
        m_age = a.Age();
    }
    Animal()
    {
        m_name = "noname";
        m_breed = "n/a";
        m_age = 0;
    }
    // dtor
    virtual ~Animal(){};
    // getter
    std::string Name(void) const
    {
        return m_name;
    }
    std::string Breed(void) const
    {
        return m_breed;
    }
    int Age(void) const
    {
        return m_age;
    }
    // setter
    void Name(const std::string& name)
    {
        m_name = name;
    }
    void Breed(const std::string& breed)
    {
        m_breed = breed;
    }
    void Age(int age)
    {
        m_age = age;
    }
    std::string toString(void) const
    {
        std::stringstream ss;
        ss << "\nname: " << m_name
           << "\nbreed: " << m_breed
           << "\nage: " << m_age;
        return ss.str();
    }
};

void variableDemo(void) noexcept
{
    std::cout << "\n--- variables demo ---\n" << std::endl;

    // primitive types; overflow, underflow;
    // pattern
    // initializer
    char a1 = 'a';
    short b1(255);
    int c1 = { 69 };
    long d1{123456789};
    float e1 = 3.1415926f;
    double f1 = 2.71828182812312512312312;
    bool g1;
    g1 = true;

    // type traits
    // reflection
    // type conversion; explicit, implicit
    char a2 = (char)b1; // c-style cast
    char* b2 = reinterpret_cast<char*>(&b1); // c++ cast
    std::cout << "b2: " << *b2 << std::endl;

    float e2 = d1;
    std::cout << "e2: " << e2 << std::endl;

    // variable template
    std::cout << (pi<int>) << std::endl;
    std::cout << (pi<float>) << std::endl;
    std::cout << (pi<double>) << std::endl;
    std::cout << (pi<long>) << std::endl;
}

void functionDemo(void) noexcept
{
    // pattern
    // regular function
    std::cout << "\n--- function demo ---\n" << std::endl;
    std::cout << "square: "<< square(2) << std::endl;
    // lambda expr
    auto f = [](int x, int y){ return x + y; };
    std::cout << "lambda: " << f(3, 4) << std::endl;
    // immediate
    int a = 3;
    float b = 2.718f;
    std::cout << "immediate: " << ([=](int x){ return (a + b)*x; })(2) << std::endl;
    // anonymous
    // function pointer
    func_ptr g1 = square;
    std::cout << "function pointer: " << g1(3) << std::endl;
    funct_ptr_double g2 = mulTwo;
    func_ptr_float g3 = addOne;

    std::cout << "function pointer(double): " << g2(3) << std::endl;
    std::cout << "function pointer(float) : " << g3(3) << std::endl;

    // function template
    std::cout << "function template<int>: " << mul<int>(3, 4) << std::endl;
    std::cout << "function template<float> : " << mul<int>(3.14, 2.718) << std::endl;
    std::cout << "function template<double>: " << mul<double>(3e8, 1) << std::endl;

    // return type: ByVal, ByRef, ByPtr;
    // args: ByVal, ByRef, ByPtr;
    char msg[] = "hello world!";
    display(msg);
}

void statementDemo(void) noexcept
{
    std::cout << "\n--- statement ---\n" << std::endl;
    int x, y; x = 42; y = 69;
    // arithmetic
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;
    std::cout << "(double)x / y = " << (double(x)/y) << std::endl;
    std::cout << "x % y = " << (x%y) << std::endl;
    // relational
    std::cout << "x == y : " << (x == y) << std::endl;
    std::cout << "x != y : " << (x != y) << std::endl;
    std::cout << "x < y  : " << (x < y) << std::endl;
    std::cout << "x <= y : " << (x <= y) << std::endl;
    std::cout << "x > y  : " << (x > y) << std::endl;
    std::cout << "x >= y : " << (x >= y) << std::endl;
    // logic
    std::cout << "!x : " << (!x) << std::endl;
    std::cout << "x && y : " << (x && y) << std::endl;
    std::cout << "x || y : " << (x || y) << std::endl;
    // access
    Point p1;
    Point *p1Ptr = &p1;
    std::cout << "access(x) : " << (p1Ptr->x) << std::endl;
    std::cout << "access(y) : " << (*p1Ptr).y << std::endl;
    // bitwise; "mask"
    x = x << 2;
    std::cout << "x << 2 : " << x << std::endl; // 0010 1010; 1010 1000; 128+32+8 = 168;
    x = 42;
    std::cout << "x >> 2 : " << x << std::endl; // 0010 1010; 0000 1010; 8+2 = 10;
    x = 42;
    std::cout << "x ^ y : " << (x ^ y) << std::endl; // 0100 0101; 0110 1111; 64+32+8+4+2+1 = 111;
    std::cout << "x | y : " << (x | y) << std::endl; // 111;
    std::cout << "x & y : " << (x & y) << std::endl; // 0000 0000; 0;
    std::cout << "~x : " << (~x) << std::endl; // -x - 1; -43;
    // assign: skip
    // cast: static_cast, dynamic_cast, const_cast, reinterpret_cast; C-style cast;
    const double c = 3e8;
    double *rc = const_cast<double*>(&c);
    // c++; // error out;
    rc++;
    std::cout << "removed const c : " << *rc << std::endl;
    // dynamic_cast is used in downcasting for safety casting sake;
    // operator for storage
    Person* zl = new Person("zhang liang", 35);
    std::cout << zl->toString() << std::endl;
    delete zl;
    // operator for other
    x < 100? (std::cout << "x < 100 " << std::endl) : (std::cout << " x >= 100 " << std::endl);

}

void controlflowDemo(void) noexcept
{

    std::cout << "\n--- control flow demo ---\n" << std::endl;
    // if...else if...else;
    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';

    if(mean%2==1)
    {
        std::cout << "mean is odd" << std::endl;
    }
    else
    {
        std::cout << "mean is even" << std::endl;
    }

    // switch...case...default;
    int year(2021), month(4), day(15);
    bool res = true;
    switch(month)
    {
        case 2: if(isLeapYear(year))
                {
                    if(day > 29){ res = false; }
                }
                else
                {
                    if(day > 28){ res = false; }
                }
                break;
        case 4:
        case 6:
        case 9:
        case 11: if(day > 30){ res = false; }
    }
    std::cout << "res = " << std::boolalpha << res << std::endl;

    // try...catch...;
    int x1 = 1, y1 = 0;
    int result{0};
    try
    {
        // result = x1 / y1;
    }
    catch(const std::runtime_error& e)
    {
        // throw std::runtime_error("ZeroDivisionError");
        std::cerr << e.what() << std::endl;
        std::exit(-1);
    }
}

void loopDemo(void) noexcept
{
    std::cout << "\n--- loop demo ---\n" << std::endl;
    int numbers[3] = { 1, 2, 3 };
    std::string names[] = { "ZL", "ZZ", "SCY" };

    // for(;;)
    for(int i=0; i<3; ++i)
    {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;
    // foreach()
    for(auto &elem : numbers)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // while
    int idx = 2;
    while(idx > 0)
    {
        std::cout << numbers[idx] << " ";
        idx--;
    }
    std::cout << std::endl;
    // do...while
    idx = 2;
    do
    {
        std::cout << names[idx] << " ";
        --idx;
    } while (idx > 0);
    std::cout << std::endl;
}

void classDemo(void) noexcept
{
    std::cout << "\n--- class demo ---\n" << std::endl;
    Animal dog{"john", "dog", 5 };
    std::cout << dog.toString() << std::endl;
    Animal cat(dog);
    cat.Name("meow");
    cat.Breed("cat");
    cat.Age(3);
    std::cout << cat.toString() << std::endl;
}

void ioDemo(void) noexcept
{
    std::cout << "skip" << std::endl;
}

void datastructureDemo(void) noexcept
{
    std::cout << "maybe next time" << std::endl;
}

void algorithmDemo(void) noexcept
{
    std::cout << "upcoming soon" << std::endl;
}
