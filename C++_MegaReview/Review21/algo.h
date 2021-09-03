#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cstddef>

#include <ctime>
#include <chrono>
#include <thread>
#include <random>

#include <set>
#include <vector>
#include <list>

#include <iterator>
#include <algorithm>
#include <numeric>

namespace TS
{

    inline void ot(const std::string& s)
    { std::cout << "\n=== " << s << " ===\n"; }

    inline void newline(void)
    { std::cout << std::endl; }

    const unsigned w{35};
    const char b(' ');

    inline void of(const std::string& s)
    { std::cout << std::setw(TS::w) << std::setfill(TS::b) << s; }

    inline void print(const std::string& c, auto const& v)
    {
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << c;
        for(auto& e : v)
            std::cout << e << TS::b;
        TS::newline();
    }

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << "thread " << i << " ended" << std::endl;
    }

    class IsEven
    {
    public:
        bool operator()(const int& e)
        { return e%2==0; }
    };

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_property(void);
    void algo_query_value(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);
}

#endif // ALGO_H_INCLUDED
