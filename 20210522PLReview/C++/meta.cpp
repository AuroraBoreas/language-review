/*
C++, meta review

@ZL, 20210522
*/ 

#include "meta.h"

namespace VarNS
{
    char x1 = 'c';
    int x2 = int(42);
    int x3 = int{42};
    int x4(42);
    int x5{42};

    static float x6 = 3e8f;
    auto x7 = 69;
    int x8 = 3.14;
    int x9 = int(3.14);
    
    const double e = double{2.718281828};
    extern bool b = true;

    template<typename T>
    T pi = 3.1415926231639126471623786127836182736789126378916;

    int* x5ptr = &x5;

} // namespace VarNS

namespace FuncNS
{
    // regular
    int fibonacci(int n)
    { return n < 2? 1 : fibonacci(n-1) + fibonacci(n-2); }

    int factorial(int n)
    { return n < 2? 1 : n * factorial(n-1); }

    // lambda
    auto lambda = [](int x)->int{
        return x * x;
    };

    // immediate

    // function pointer, delegate in C#
    typedef void (*func_ptr)(char*);
    void message(char*), message_err(char*),
         message_low(char*), message_up(char*);

    void message(char* s)
    {
        std::cout << s << std::endl;
    }

    void message_err(char* s)
    {
        std::cerr << s << std::endl;
    }

    void message_low(char* s)
    {
        char c;
        for(; *s != '\0'; ++s)
        {
            c = std::tolower(*s); std::cout.put(c);
        }
        std::cout << std::endl;
    }

    void message_up(char* s)
    {
        char c;
        for(; *s != '\0'; ++s)
        {
            c = std::toupper(*s); std::cout.put(c);
        }
        std::cout << std::endl;
    }

    // ByVal
    inline void addOne(int x)
    {
        x++;
    }   
    // ByRef, overload
    inline constexpr void addOne(int& x)
    {
        ++x;
    }
    // ByPtr, overload
    inline constexpr void addOne(const int* x) noexcept
    {
        *x++;
    }


    // funtion template
    template<class T, class U>
    T sum(T x, U y)
    {
        return x + (T)y;
    }

} // namespace FuncNS

namespace StatementNS
{
    int x = 69, y = 42;

    void arithmetic(void)
    {
        std::cout << "x = " << x << ", y = " << y << ", x + y : " << (x + y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x - y : " << (x - y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x * y : " << (x * y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x / y : " << (x / y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x % y : " << (x % y) << std::endl;
    }

    void relational(void)
    {
        std::cout << "x = " << x << ", y = " << y << ", x == y : " << std::boolalpha << (x == y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x != y : " << std::boolalpha << (x != y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x > y : "  << std::boolalpha << (x > y)  << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x >= y : " << std::boolalpha << (x >= y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x < y : "  << std::boolalpha << (x < y)  << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x <= y : " << std::boolalpha << (x <= y) << std::endl;
    }
    
    void logic(void)
    {
        std::cout << "x = " << x << ", !x : " << (!x) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x && y : " << std::boolalpha << (x && y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x || y : " << std::boolalpha << (x || y) << std::endl;
    }

    template<class T>
    struct Point
    {
        private:
            T m_x;
            T m_y;

        public:
            Point(T x, T y)
            {
                m_x = x;
                m_y = y;
            }

            std::string toString(void)
            {
                std::stringstream ss;
                ss << "Point[" << this->m_x << ", " << this->m_y << "]";
                return ss.str();
            }
    };

    void access(void)
    {
        Point p1 = Point<int>{1, 1};
        std::cout << p1.toString() << std::endl;

        Point p2 = Point<float>(2.718f, 3.141f);
        std::cout << p2.toString() << std::endl;
    }

    void bitwise(void)
    {
        int x = 69, y = 42;
        x = x << 2; // == x * x;
        std::cout << "x = " << 69 << ", x << 2: " << x << std::endl;
        x = 69;
        x = x >> 2;
        std::cout << "x = " << 69 << ", x >> 2: " << x << std::endl;
        x = 69;
        std::cout << "x = " << 69 << ", ~x: " << ~x << std::endl;
        x = 69;
        std::cout << "x = " << x << ", y = " << y << ", x & y : " << (x & y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x | y : " << (x | y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << ", x ^ y : " << (x ^ y) << std::endl;
    }

    void assign(void)
    {
        int x = 69;
        std::cout << x << std::endl;

        int x1(69);
        std::cout << x1 << std::endl;

        int x2{69};
        std::cout << x2 << std::endl;

        int x3 = int(69);
        std::cout << x3 << std::endl;

        int x4 = int{69};
        std::cout << x4 << std::endl;
    }

    void cast(void)
    {
        std::cout << "casting is freaking amazing in c++" << std::endl;
    }

    class A
    {
        public:
            void hello(void)
            { std::cout << "class A says hello" << std::endl; }
    };

    void operatorForStorage(void)
    {
        A *a1 = new A();
        a1->hello();

        delete a1;
    }

    void operatorForOther(void)
    {
        std::string name;
        int len(2);
        len > 2? name = "SCY": name = "TS";
        std::cout << "hello " << name << std::endl;
    }

} // namespace StatementNS

namespace ControlflowNS
{
    inline bool isLeapYear(int year)
    {
        return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    }

    inline bool setDate(int y, int m, int d)
    {
        if(y < 0)           { return false; }
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

    inline void dividZero(int x, int y)
    {
        double rv;
        try
        {
            rv = (double)x / y;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            throw;
        }
    }

    
} // namespace ControlflowNS

namespace LoopNS
{    

    void arrayNotaion(std::array<int, 10> arr) noexcept
    {
        // address
        std::cout << "\n--- array address ---";
        for(const auto& elem : arr)
        {
            std::cout << elem << std::endl;
        }

        // index
        std::cout << "\n--- array index ---";
        for(int i=0; i<10; i++)
        {
            std::cout << i << " " << arr[i] << std::endl;
        }

        // pointer
        std::cout << "\n--- array pointer ---";       
        auto iter = arr.begin(); 
        for(; iter != arr.end(); ++iter)
        {
            std::cout << *iter << std::endl; 
        }
    }

    void whileloop(void) noexcept
    {
        char msg[] = "hello sugar saisai";
        char* ptr = msg;

        while(*ptr != '\0')
        {
            std::cout.put(*ptr);
            ptr++;
        }
        std::cout << std::endl;       
    }

    void dowhile(void) noexcept
    {
        int i{0};
        do
        {
            std::cout << i++ << ' ';
            if(i % 2 == 0) { continue; }
        } while (i < 10);
    }

} // namespace loopNS

namespace ClassNS
{
    class Car
    {
        private:
            unsigned m_number;
            unsigned m_seats;
            double m_weight;

        public:
            // ctor
            Car()
            {
                m_number = 0;
                m_seats = 2;
                m_weight = 10.0;
            }

            Car(unsigned number, unsigned seat, unsigned weight)
            {
                m_number = number;
                m_seats = seat;
                m_weight = weight;
            }

            // dtor
            virtual ~Car(){};

            // getter
            unsigned Number(void) const { return m_number; }
            unsigned Seats(void) const  { return m_seats; }
            double Weight(void) const { return m_weight; }
            // setter
            void Number(const unsigned val) { m_number = val; }
            void Seats(const unsigned val)  { m_seats = val; }
            void Weight(const double val)   { m_weight = val; }

            // toString
            virtual std::string ToString(void) const
            {
                std::stringstream ss;
                ss << "\nNumber: " << this->m_number
                   << "\nSeats : " << this->m_seats
                   << "\nWeight: " << this->m_weight;
                return ss.str();
            }

            // cmp
            bool operator==(const Car& car) const 
            {
                if(this->ToString() == car.ToString())
                {
                    return true;
                }
                return false;
            }

            // opol
            friend std::ostream& operator<<(std::ostream& os, const Car& car)
            {
                os << car.ToString();
                return os;
            }
    };

    class Supercar: public Car
    {
        private:
            bool m_hasSunshelter;
        public:
            Supercar(unsigned number=0, unsigned seats=1, double weight=10.0, bool hasSunshelter=true)
            : Car(number, seats, weight)
            {
                m_hasSunshelter = hasSunshelter;
            }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << Car::ToString()
                   << "\nhasSunshelter: " << m_hasSunshelter;

                return ss.str();
            }
    };
} // namespace classNS

namespace DatastructureNS
{
    void datastructure(void) noexcept
    {
        ClassNS::Car* cars[] = {
            new ClassNS::Car(),
            new ClassNS::Car(1, 4, 11.0),
            new ClassNS::Car(2, 2, 20.0),
            new ClassNS::Car(3, 1, 3.0),
        };

        for(int i=0; i<4; ++i)
        {
            cars[i]->ToString();
        }
        
        delete cars;

        std::list<ClassNS::Supercar> supercars = {
            ClassNS::Supercar(1, 4, 11.0, false),
            ClassNS::Supercar(2, 2, 20.0, true),
            ClassNS::Supercar(3, 1, 3.0, true),
        };

        auto it = supercars.begin();
        for(; it != supercars.end(); ++it)
        {
            std::cout << it->ToString() << std::endl;
        }
    }
} // namespace datastructureNS

namespace AlgorithmNS
{
    void print(std::string_view text, std::vector<int> const& v={})
    {
        std::cout << text << ": ";
        for(const auto& e : v) std::cout << e << ' ';
        std::cout << '\n';
    }

    // Max Heap
    void heaps(void)
    {
        std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        print("initially, v", v);

        std::make_heap(v.begin(), v.end());
        print("after make_heap, v", v);

        std::pop_heap(v.begin(), v.end());
        print("after pop_heap, v", v);

        auto top = v.back();
        v.pop_back();
        print("formal top element", {top});
        print("after removing the former top element, v", v);

        // add one element
        v.push_back(8.88);
        print("before push_heap, v", v);
        std::push_heap(v.begin(), v.end());
        print("after push_heap, v", v);

        // remove one element
        std::pop_heap(v.begin(), v.end());
    }

    // sort
    void sorts(void)
    {
        std::vector<int> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        print("before partial_sort, s", s);
        std::partial_sort(s.begin(), s.begin() + 3, s.end());
        print("after partial_sort, s", s);

    }
    // partitioning
    void partition(void)
    {
        std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    }
    
} // namespace algorithmNS

void variableDemo(void)
{
    /*
    [ variable ]
    ===
    * concept: box
    * pattern: T N P
    * feature:
        * primitive types
            @ Char
            @ Short
            @ Int
            @ Long

            @ Float
            @ Double
            
            @ [x]Byte
            @ Boolean
            @ [x]Decimal

        * type traits
            @ type

        * type conversion
            @ implicit vs explicit
            @ downcasting vs upcasting
              
        * initialization
            @ resource acquisition is initialization
            @ narrowing mechnim

        * value
            @ l-Value
            @ r-Value

        * reference 
            @ l-Reference
            @ r-Reference

        * pointer
            @ raw Pointer
            @ array decayed into raw pointer 
            @ smart pointers

        * variable template
            @ generalization 
        
        * keywords
            @ static
            @ register
            @ const
            @ auto
            @ mutable
            @ extern 
    ===
    */ 

    std::cout << "x1 = " << VarNS::x1 << std::endl;
    std::cout << "x2 = " << VarNS::x2 << std::endl;
    std::cout << "x3 = " << VarNS::x3 << std::endl;
    std::cout << "x4 = " << VarNS::x4 << std::endl;
    std::cout << "x5 = " << VarNS::x5 << std::endl;
    std::cout << "x6 = " << VarNS::x6 << std::endl;
    std::cout << "x7 = " << VarNS::x7 << std::endl;
    std::cout << "x8 = " << VarNS::x8 << std::endl;
    std::cout << "x9 = " << VarNS::x9 << std::endl;

    std::cout << "e = " << VarNS::e << std::endl;
    std::cout << "b = " << std::boolalpha << VarNS::b << std::endl;

    std::cout << "pi<short> = " << VarNS::pi<short> << std::endl;
    std::cout << "pi<int> = " << VarNS::pi<int> << std::endl;
    std::cout << "pi<long> = " << VarNS::pi<long> << std::endl;
    std::cout << "pi<float> = " << VarNS::pi<float> << std::endl;
    std::cout << "pi<double> = " << VarNS::pi<double> << std::endl;

    std::cout << "x5ptr, address: " << VarNS::x5ptr << ", value: " << *VarNS::x5ptr << std::endl; 
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
            @ ByVal
            @ ByRef
            @ ByPtr

        * func_name
            @ overload
            @ operator overload
            @ function template

        * args
            @ ByVal
            @ ByRef
            @ ByPtr
            @ [x] variadic args or params
        
        * category
            @ regular: prototype, definition
            @ [x]anonymous
            @ lambda
            @ immediate

            @ function pointer

            @ [x]decorator
            @ [x]generator
            @ [x]function inside function
            @ [x]class inside function
        
        * keywords
            @ inline
            @ #macro
            @ return
            @ constexpr
            @ noexcept

    ===
    */ 

    // regular
    std::cout << "fibonacci(5) = " << FuncNS::fibonacci(5) << std::endl;
    std::cout << "factorial(5) = " << FuncNS::factorial(5) << std::endl;
    // lambda
    std::cout << "lambda(5) = " << FuncNS::lambda(5) << std::endl;

    // function pointer, delegate in C#
    FuncNS::func_ptr myFuncPtr[] = {
        FuncNS::message, 
        FuncNS::message_err,
        FuncNS::message_low,
        FuncNS::message_up
    };

    myFuncPtr[0]("hello TS");

    // overload
    int x = 69, *xptr = &x;
    std::cout << "before addOne(int x), x = " << 69 << std::endl;
    FuncNS::addOne(69);
    std::cout << "after addOne(int x), x = " << x << std::endl;

    std::cout << "before addOne(int& x), x = " << x << std::endl;
    FuncNS::addOne(&x);
    std::cout << "after addOne(int& x), x = " << x << std::endl;

    std::cout << "before addOne(int* x), x = " << *xptr << std::endl;
    FuncNS::addOne(xptr);
    std::cout << "after addOne(int* x), x = " << *xptr << std::endl;

}

void statementDemo(void)
{
    /*
    [ statement ]
    ===
    * concept: link
    * pattern: symbol
    * feature:
        * Arithmetic
            @ +,-,*,/,%
            @ ++(post), --(post), ++(pre), --(pre), 

        * Relational
            @ ==, !=
            @ >, >=
            @ <, <=

        * Logic
            @ !
            @ &&
            @ ||

        * Access
            @ ->
            @ (*).

        * Bitwise
            @ <<, >>
            @ |
            @ &
            @ ^
            @ ~

        * Assign
            @ type var_name = val
            @ type()
            @ type{}
            @ var_name()
            @ var_name{}

        * Cast
            @ dynamic_cast<T*>(U*)
            @ static_cast<T*>(U*) 
            @ const_cast<T*>(U*)
            @ reinterpret_cast<T*>(U*)
            @ (type)var_name; C-style cast;

        * Op for storage
            @ new
            @ delete

        * Op for other
            @ .
            @ ()
            @ []
            @ {} 
            @ <>
            @ :?
            @ ,
            @ ;
    ===
    */ 

    StatementNS::arithmetic();
    StatementNS::relational();
    StatementNS::logic();
    StatementNS::access();
    StatementNS::bitwise();
    StatementNS::assign();
    StatementNS::cast();
    StatementNS::operatorForStorage();
    StatementNS::operatorForOther();
}

void controlflowDemo(void)
{
    /*
    [ controlflow ]
    ===
    * concept: branch/stream
    * pattern: branch
    * feature:
        * if...else if...else
        * switch...case...default
        * try...catch...finally
    ===
    */ 

    std::cout << "setDate(2021, 5, 22) is valid? " << std::boolalpha << ControlflowNS::setDate(2021, 5, 22) << std::endl;
    
    ControlflowNS::dividZero(10, 0);
}

void loopDemo(void)
{
    /*
    [ loop ]
    ===
    * concept: circle
    * pattern: circle
    * feature:
        * for(;;)
        * for(auto elem : ds)
        * while
        * do...while 
    ===
    
    */ 

    constexpr std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LoopNS::arrayNotaion(arr);
    LoopNS::whileloop();
    LoopNS::dowhile();
}

void classDemo(void)
{
    /*
    [ class ]
    ===
    * concept: sim
    * pattern: sim
    * feature:
        * default components
            @ ctor
            @ dtor
            @ copy ctor
            @ copy assignment operator
        
        * pillars
            * Abstract
                @ Entity Relationship
                @ Property (has-a)
                @ class vs object (is-a)
                @ = 0

            * Encapsulation
                @ private
                @ public
                @ friend

            * Inheritance
                @ virtual 
                @ explicit
                @ default

            * Polymorphism
                @ override
            
        * class vs struct
            * small vs large
            * simple vs complicated
            * privilage
                @ class is private by default
                @ struct is public by default

        * [x]interface
        
    * principle
        @ SRP
        @ OCP
        @ LSP
        @ ISP
        @ DIP
        @ Delimiter principle(the least known principle)

    ===

    */ 

    ClassNS::Car* mycar = new ClassNS::Car();
    std::cout << mycar->ToString() << std::endl;
    delete mycar;

    ClassNS::Supercar& mysupercar = ClassNS::Supercar();

    ClassNS::Car& newcar = dynamic_cast<ClassNS::Car&>(mysupercar);
    std::cout << newcar.ToString() << std::endl;
}

void datastructureDemo(void)
{
    /*
    [ datastructure ]
    ===
    * concept: container
    * pattern: container
    * feature:
        * seq
            @ array
            @ list
            @ forward_list
            @ dequeue

        * adapter
            @ queue
            @ priority_queue
            @ stack 

        * associative
            @ map
            @ multimap
            @ set
            @ multiset 
    ===
    */ 

    DatastructureNS::datastructure();
}

void algorithmDemo(void)
{
    /*
    [ algorithm ]
    ===
    * concept: methodology
    * pattern: n/a
    * feature:
        * iterator, const_iterator
        * capacity
        * access
        * modification
        * list observation
        * bucket
        * hash policy
    
    * 195 STL_Algorithms grouped by logical relationship
        * permutations
            * heap
                @ make_heap
                @ push_heap
                @ pop_heap
                
            * sorting
                @ sort
                @ sort_heap
                @ partial_sort
                @ nth_element
                @ inplace_merge

            * partitioning
                @ partition
                @ partition_point
            
            * other
                @ reverse
                @ rotate
                @ shuffle
                @ random_shuffle
                @ prev_permutation
                @ next_permutation

        * partitioning_sort_heap
            # stable_*
            # is_*
            # is_*_until
            # *_copy
            # *_n
            # *_if

        * queries
            * numeric algorithm 
                @ count
                @ accumulate / (transform_)reduce
                @ partial_sum
                @ (transform_)inclusive_scan
                @ (transform_)exclusive_scan
                @ inner_product
                @ adjacent_difference
                @ sample

            * querying Property
                @ all_of
                @ any_of
                @ none_of 
            
            * querying a property on 2 ranges
                @ equal
                @ lexicographic_compare
                @ mismatch
                @ is_permutation

            * search a value
                ^ not sorted 
                    @ find
                    @ adjacent_found
                ^ sorted
                    @ equal_range 
                    @ lower_bound
                    @ upper_bound
                    @ binary_search -> bool
            
            * search a range
                @ search
                @ find_end
                @ find_first_of 
            
            * search a relative value
                @ max_element
                @ min_element
                @ minmax_element

        * algos on sets
            @ set_difference (A-B)
            @ set_intersection (A⋂B)
            @ set_union (A⋃B)
            @ set_symmetric_difference (A⊖B)
            @ std::includes (A⊆B, A⊂B)
            @ std::merge (?)

        * movers
            @ std::copy(first, last, out);
            @ std::move(first, last, out);
            @ std::swap_ranges(first, last, out);
            @ std::copy_backward
            @ std::move_backward

        * value modifiers
            @ std::fill    
            @ std::generate
            @ std::iota
            @ std::replace

        * structure changers
            $ std::remove
            $ std::unique
            $ collection.erase

        * _copy
            % remove_copy
            % unique_copy
            % reverse_copy
            % rotate_copy
            % relpace_copy
            % partition_copy
            % partial_sort_copy


 
    ===
    */
}
