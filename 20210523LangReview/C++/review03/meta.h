#ifndef META_H_INCLUDED
#define META_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

#include <ctime>
#include <random>
#include <thread>
#include <chrono>

#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<numeric>

#include <functional>
#include <iterator>
#include <algorithm>


namespace TS
{
    template<class T>
    void print(const std::string&, std::vector<T>);

    auto mprint = [](const std::string& comment, auto const& v){
        std::cout << comment;
        for(const auto& e : v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    };

    void func(const int&);

    // 排
    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    // 构
    void algo_structure_changer(void);
    // 移
    void algo_movers(void);
    // 值
    void algo_value_modifiers(void);
    // 集
    void algo_set(void);
    // 查
    void algo_query_property(void);
    void algo_query_value(void);
    // 原
    // runes
    void algo_secret_runes(void);
    // island
    void algo_lone_island(void);


}

#endif // META_H_INCLUDED
