/*

*/

#include "meta.h"

int main()
{
    std::cout << "\n*********************";
    std::cout << "\n* C++ meta review   *";
    std::cout << "\n* @ZL, 20210607     *";
    std::cout << "\n*********************";

    std::cout << "\n\n=== permutation heap ===\n";
    TS::algo_permutation_heap();
    std::cout << "\n=== permutation sort ===\n";
    TS::algo_permutation_sort();
    std::cout << "\n=== structure changer ===\n";
    TS::algo_structure_changer();
    std::cout << "\n=== movers ===\n";
    TS::algo_movers();
    std::cout << "\n=== value modifiers ===\n";
    TS::algo_value_modifiers();
    std::cout << "\n=== algo of set ===\n";
    TS::algo_set();
    std::cout << "\n=== query property ===\n";
    TS::algo_query_property();
    std::cout << "\n=== query value ===\n";
    TS::algo_query_value();
    std::cout << "\n=== secret rune ===\n";
    TS::algo_secret_runes();
    std::cout << "\n=== lone island ===\n";
    TS::algo_lone_island();



    return 0;
}
