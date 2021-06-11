#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>

#include <set>
#include <map>
#include <vector>
#include <list>

#include <iterator>
#include <algorithm>

#include <chrono>
#include <thread>

namespace TS
{

    auto print = [](const std::string& c, auto const& v){
        std::cout << c;
        for(auto e : v){
            std::cout << e << " ";
        }
        std::cout << std::endl;
    };

    void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << "thread " << i << " ended" << std::endl; 
    }
    
    void algo_permutation_heap(void);
    void algo_permutation_sort(void);

    void algo_structure_changer(void);

    void algo_movers(void);

    void algo_value_modifiers(Void);

    void algo_set(void);

    void algo_query_property(void);
    void algo_query_values(void);

    void algo_raw_memory(void);

    void algo_secret_runes(void);
    void algo_lone_island(void);

}

#endif // ALGO_H_INCLUDED
