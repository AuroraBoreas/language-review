#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

#include <ctime>
#include <cctype>
#include <numeric>
#include <random>
#include <chrono>
#include <thread>

#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <algorithm>

namespace TS
{
    const int width = 35;

    auto print = [](const std::string& c, auto const& v){
        std::cout << std::setw(width) << std::setfill(' ') << c;
        for(const auto& e : v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    };

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << std::setw(width) << std::setfill(' ') << "thread " << i << " ended" << std::endl;
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

    void algo_secret_runes(void);
    void algo_lone_island(void);

}

#endif // ALGO_H_INCLUDED
