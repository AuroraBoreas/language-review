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

#include <vector>
#include <list>
#include <set>

#include <functional>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace SCY
{
    inline void o(const std::string& s) { std::cout << "\n=== " << s << " ===" << std::endl; }
    inline void newline() { std::cout << std::endl; }

    const int w  = 35;
    const char b = ' ';
    auto print = [](const std::string& c, const auto& v){
        std::cout << c;
        for(auto& e : v){
            std::cout << std::setw(SCY::w) << std::setfill(SCY::b) << e << SCY::b;
        }
        SCY::newline();
    };

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << "thread " << i << " end" << std::endl;
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
} // namespace SCY


#endif // ALGO_H_INCLUDED