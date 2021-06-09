#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <string>
#include <random>

#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <functional>
#include <algorithm>

namespace TS
{
    auto print = [](const std::string& c, const auto& v){
        std::cout << c;
        for(const auto& e : v) std::cout << e << " ";
        std::cout << std::endl;
    };

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);

    void algo_structure_changer(void);

    void algo_movers(void);

    void algo_value_modifiers(void);

    void algo_set(void);

    void algo_query_property(void);
    void algo_query_value(void);

    void algo_secret_runes(void);
}

#endif // ALGO_H_INCLUDED
