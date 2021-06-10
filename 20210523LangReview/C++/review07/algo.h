/*
c++, algo review

@ZL, 20210610
*/ 

#ifndef ALGO_H_INCLUCED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

#include <ctime>
#include <numeric>
#include <random>

#include <thread>

#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#include <stack>
#include <queue>
#include <map>
#include <set>

#include <unordered_map>
#include <unordered_set>

#include <iterator>
#include <functional>
#include <algorithm>

namespace TS
{
    auto print = [](const std::string& c, auto const& v){
        std::cout << c;
        for(const auto& e : v){
            std::cout << e << " ";
        }
        std::cout << std::endl;
    };

    void func(const int&);

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_property(void);
    void algo_query_value(void);
    void algo_screte_rune(void);
    void algo_lone_island(void);
    void algo_raw_memory(void);
}

#endif // ALGO_H_INCLUDED