#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <chrono>
#include <thread>
#include <random>

#include <vector>
#include <list>

#include <iterator>
#include <algorithm>
#include <numeric>

namespace SCY
{
    inline void newline(void) { std::cout << std;:endl; }
    inline void o(const std::string& s) { std::cout << "\n=== " << s << " ===\n"; }
    const int w  = 35;
    const char b = ' ';
    auto print = [](const std::string& c, auto const& v){
        std::cout << c;
        for(auto& e : v){
            std::cout << e << SCY::b;
        }
        SCY::newline();
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
    void algo_query_property(void);
    void algo_query_value(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);
}

#endif // ALGO_H_INCLUDED