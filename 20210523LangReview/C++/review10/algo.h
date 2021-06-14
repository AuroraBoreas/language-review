#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>

#include <array>
#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <algorithm>
#include <numeric>
#include <execution>

namespace TS
{
    inline void out(const std::string& topic)
    {
        std::cout << "\n=== " << topic << "===\n";
    }

    const std::string b = " ";
    int const w = 35;

    auto print = [](const std::string& c, auto const& v){
        std::cout << c;
        for(auto& e : v) {
            std::cout << std:: setw(w) << std::setfill(b) << e << TS::b;
        }
        std::cout << std::endl;
    };

    void func(int const& i)
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