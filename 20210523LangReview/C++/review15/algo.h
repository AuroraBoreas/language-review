#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#include <random>
#include <ctime>
#include <chrono>
#include <thread>

#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <algorithm>
#include <numeric>

namespace TS
{
    inline void o(std::string const& t)
    { std::cout << "\n=== " << t  << "===" << std::endl; }

    inline void newline(void)
    { std::cout << std::endl; }

    const int w = 35;
    const std::string  b = " ";

    auto print = [](std::string const& c, const auto& v){
        std::cout << c;
        for(auto& e : v){
            std::cout << std::setw(TS::w) << std::setfill(' ') << e << TS::b;
        }
        TS::newline();
    };

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << "thread " << i << " ended" << std::endl;
    }

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_value(void);
    void algo_query_property(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);
}

#endif // ALGO_H_INCLUDED
