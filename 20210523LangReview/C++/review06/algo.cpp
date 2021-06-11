#include "algo.h"

void TS::algo_permutation_heap(void)
{
    /*
    @ make heap pop
    ===
    - make_heap
    - pop_heap
    - push_heap
    ===
    */

    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    auto rnd = [](){ return std::rand()%10; };
    std::generate(v.begin(), v.end(), rnd);
    TS::print("original, v-> ", v);

    std::make_heap(std::begin(v), std::end(v), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print("std::pop_heap, v-> ", v);
    int top = v.back();
    v.pop_back();
    std::cout << "collection.top, top -> " << top << std::endl;

    v.push_back(rnd());
    std::push_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::push_heap, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    /*
    @ sort
    ===
    - sort
    - partition
    - shuffle

    - rotate
    - reverse
    - count
    ===
    */
    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 1);
    TS::print("original, v-> ", v);
    // std::random_device rd;
    // std::mt19937 mt(rd());
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.begin(), [](){
                    return std::rand()%100;
                  });

    auto pp = std::partition_point(v.begin(), v.end(), [](const auto& e){
                            return e%2==0;
                         });
    std::cout << *pp << std::endl;
    std::list<int> l;
    std::copy(v.begin(), v.end(), std::back_inserter(l));
    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
}

void TS::algo_structure_changer(void)
{
    /*
    @ changer
    ===
    - remove
    - unique
    ===
    */
}

void TS::algo_movers(void)
{
    /*
    @ mover
    ===
    - copy
    - move
    - move_backward
    - swap_ranges
    ===
    */
}

void TS::algo_value_modifiers(void)
{
    /*
    @ modifiers
    ===
    - fill
    - iota
    - generate
    - replace
    ===
    */
}

void TS::algo_set(void)
{
    /*
    @ set
    ===
    - intersection
    - union
    - difference
    - symmetric_difference
    - subset
    ===
    */
}

void TS::algo_query_property(void)
{
    /*
    @ query property
    ===
    - is_*
        ~ is_sorted
        ~ is_heap
        ~ is_partitioned
        ~ is_permutation

    - is_*_until
        ~ is_sorted_until
        ~ is_heap_until

    - *_of
        ~ none_of
        ~ all_of
        ~ any_of

    ===
    */
}

void TS::algo_query_value(void)
{
    /*
    @ query value
    ===
    - find
        ~ find
        ~ find_if
        ~ find_if_not
        ~ adjacent_find
        ~ find_first_of
        ~ find_end

    - search
        ~ search
        ~ binary_search
        ~ lower_bound
        ~ upper_bound
        ~ min_element
        ~ max_element
        ~ minmax_element

    - 2-rangers
        ~ equal
        ~ mismatch
        ~ lexicograhical_compare

    - other
        ~ inner_product
        ~ sample
        ~ accumulate
        ~ reduce
        ~ adjacent_difference
        ~ transform_reduce
        ~ partial_sum
        ~ inclusive_scan
        ~ exclusive_scan
    ===
    */
}
