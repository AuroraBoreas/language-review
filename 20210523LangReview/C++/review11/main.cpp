#include "algo.h"

int main()
{
    SCY::o("permutation_heap");
    SCY::algo_permutation_heap();
    SCY::o("permutation_sort");
    SCY::algo_permutation_sort();

    SCY::o("structure_changer");
    SCY::algo_structure_changer();

    SCY::o("mover");
    SCY::algo_mover();

    SCY::o("value modifier");
    SCY::algo_value_modifier();

    SCY::o("set");
    SCY::algo_set();

    SCY::o("query_property");
    SCY::algo_query_property();

    SCY::o("query value");
    SCY::algo_query_value();
    
    SCY::o("raw_memory");
    SCY::algo_raw_memory();
    
    SCY::o("secret_rune");
    SCY::algo_secret_rune();

    SCY::o("lone_island");
    SCY::algo_lone_island();

    return 0;
}