#include "algo.h"

int main()
{
    TS::out("permutation");
    TS::algo_permutation_heap();
    
    TS::out("sort");
    TS::algo_permutation_sort();
    
    TS::out("structure changer");
    TS::algo_structure_changer();

    TS::out("mover");
    TS::algo_mover();
    
    TS::out("value modifier");
    TS::algo_value_modifier();

    TS::out("set");
    TS::algo_set();

    TS::out("query property");
    TS::algo_query_property();

    TS::out("query value");
    TS::algo_query_value();

    TS::out("raw memoery");
    TS::algo_raw_memory();

    TS::out("secret rune");
    TS::algo_secret_rune();

    TS::out("lone island");
    TS::algo_lone_island();

    return 0;
}