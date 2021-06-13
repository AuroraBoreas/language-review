
#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

#include <ctime>
#include <cstdlib>
#include <thread>
#include <cctype>
#include <random>
#include <chrono>
//#include <execution>

#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <algorithm>
#include <numeric>
#include <memory>

namespace TS
{
    unsigned w = 35;
    char b = ' ';
    auto print = [](const std::string& c, const auto& v)->void{
        std::cout << std::setw(w) << std::setfill(b) << c;
        for(const auto& e : v) std::cout << e << b;
        std::cout << std::endl;
    };

    inline void func(int const& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << "thread " << i << " ended" << std::endl;
    };

    inline void out(const std::string& msg)
    {
        std::cout << "\n=== " << msg << " ===\n";
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
