#include "algo.h"


void TS::algo_permutation_heap(void)
{
    std::vector<int> v {3, 1, 2, 99, 99, 99, 0, -1, 99, 1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    std::print("std::make_heap, v-> ", v);
    
    std::pop_heap(v.begin(), v.end(), std::less<>{});
    std::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::less<>{});
    std::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    std::print("std::sort_heap, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v {3, 1, 2, 99, 99, 99, 0, -1, 99, 1};

}

void TS::algo_structure_changer(void)
{

}

void TS::algo_mover(void)
{

}

void TS::algo_value_modifier(void)
{

}

void TS::algo_set(void)
{

}

void TS::algo_query_property(void)
{

}

void TS::algo_query_value(void)
{

}

void TS::algo_raw_memory(void)
{

}

void TS::algo_secret_rune(void)
{

}

void TS::algo_lone_island(void)
{

}

