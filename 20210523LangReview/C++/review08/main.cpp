#include "algo.h"

int main()
{
    std::cout << "\n=== permutation heap ===" << std::endl;
    TS::algo_permutation_heap();

    std::cout << "\n=== permutation sort ===" << std::endl;
    TS::algo_permutation_sort();

    std::cout << "\n=== structure changer ===" << std::endl;
    TS::algo_structure_changer();

    std::cout << "\n=== value modifier ===" << std::endl;
    TS::algo_mover();

    std::cout << "\n=== movers ===" << std::endl;
    TS::algo_value_modifier();

    std::cout << "\n=== set ===" << std::endl;
    TS::algo_set();

    std::cout << "\n=== query property ===" << std::endl;
    TS::algo_query_property();

    std::cout << "\n=== query value ===" << std::endl;
    TS::algo_query_value();

    std::cout << "\n=== raw memory ===" << std::endl;
    TS::algo_raw_memory();

    std::cout << "\n=== secret runes ===" << std::endl;
    TS::algo_secret_runes();

    std::cout << "\n=== lone island ===" << std::endl;
    TS::algo_lone_island();

    return 0;
}
