#include "meta.h"

int main()
{
    std::cout << "\n=== permutation heap ===" << std::endl;
    TS::algo_permutation_heap();

    std::cout << "\n=== permutation sort ===" << std::endl;
    TS::algo_permutation_sort();

    std::cout << "\n=== permutation partition ===" << std::endl;
    TS::algo_permutation_partition();

    std::cout << "\n=== permutation other: rotate, shuffle ===" << std::endl;
    TS::algo_permutation_other();

    std::cout << "\n=== secret runes ===" << std::endl;
    TS::algo_secret_runes();

    std::cout << "\n=== queries ===" << std::endl;
    TS::algo_queries();

    return 0;
}
