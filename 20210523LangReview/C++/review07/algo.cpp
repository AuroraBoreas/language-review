/*
c++, algo review

@ZL, 20210610
*/ 

#include "algo.h"

void TS::func(const int& i)
{
    std::this_thread::sleep_for(std::chrono::seconds(i));
    std::cout << "thread " << i << " ended" << std::endl;
}


void algo_permutation_heap(void)
{
    /*
    @ heap
    ===
    - make_heap
    - pop_heap
    - push_heap

    - prev_permutation
    - next_permutation
    ===    
    */

    std::vector<int> v{ 1, 99, 99, -1, 0, 99, 1, 3 };
    TS::print("origianl, v-> ", v);
    
    std::make_heap(v.begin(), v.end(), std::less<>{});
    TS::print("std::make_heap, v-> ", v);

    v.push_back(42);
    TS::print("before push_heap, v-> ", v);
    std::push_heap(v.begin(), v.end(), std::less<>{});
    TS::print("after push_heap, v-> ", v);

    std::pop_heap("std::pop_heap, v->", v);
}

void algo_permutation_sort(void)
{
    /*
    @ sort
    ===
    - sort
    - shuffle
    - rotate
    - reverse
    - partition
    ===
    */

    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    auto g = [](){ return std::rand()%20; };
    std::generate(v.begin(), v.end(), g);
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end(), std::greater<>{});
    TS::print("std::sort, v-> ", v);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), v.begin()+3, v.end());
    TS::print("std::rotate, v-> ", v);

    std::partition(v.begin(), v.end(), [](const auto& e){
        return e%2==0;
    });
    TS::print("std::partition, v-> ", v);
}

void algo_structure_changer(void)
{
    /*
    @ changer
    ===
    - remove
    - unique
    ===
    */

    std::vector<int> v{ 1, 99, 99, -1, 0, 99, 1, 3 };
    TS::print("original, v-> ", v);
    v.erase(std::remove(std::begin(v), std::end(v), 99), std::end(v));
    TS::print("std::remove, v-> ", v);

    v = { 1, 99, 99, -1, 0, 99, 1, 3 };
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v.begin(), v.end());
}

void algo_mover(void)
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

    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 1);
    std::list<int> l;
    std::copy(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::copy, l-> ", l);

    std::vector<std::thread> w;
    w.emplace_back(TS::func, 1);
    w.emplace_back(TS::func, 2);
    w.emplace_back(TS::func, 3);
    std::list<std::thread> l2;
    std::move(w.begin(), w.end(), std::back_inserter(l2));
    for(auto& t: l2) t.join();
}

void algo_value_modifier(void)
{
    /*
    @ modifier
    ===
    - fill
    - iota
    - generate
    - replace
    ===
    */

    std::vector<int> v(5);
    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);
    
    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });
    TS::print("std::generate, v-> ", v);

    v = { 42, 42, 43, 44, 45 };
    std::replace(v.begin(), v.end(), 42, 69);
    TS::print("std::replace, v-> ", v);
}

void algo_set(void)
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

    std::set<int> A { 1, 2, 3, 4, 5 };
    std::set<int> B { 4, 5, 6, 7, 8 };
    TS::print("set A -> ", A);
    TS::print("set B -> ", B);

    std::cout << "A intersection B: ";
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A union B: ";
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A difference B: ";
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A symmetric_difference B: ";
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A subset B: ";
    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    std::cout << std::boolalpha << rv << std::endl;

}

void algo_query_property(void)
{
    /*
    @ query property
    ===
    - is_*
        ~ is_sorted
        ~ is_heap
        ~ is_partition

    - is_*_until
        ~ is_sorted_until
        ~ is_heap_until
    ===
    */

    std::vector<int> v{ 1, 99, 99, -1, 0, 99, 1, 3 };
    TS::print("original, v-> ", v);

    bool rv = std::is_sorted(v.begin(), v.end(), std::greater<>{});
    std::cout << "std::is_sorted, -> " << std::boolalpha << rv;

    rv = std::is_heap(v.begin(), v.end());
    std::cout << "std::is_heap, -> << " << std::boolalpha << rv << std::endl;

    rv = std::is_partition(v.begin(), v.end(), [](const auto& e){ return e%2==0; });
    std::cout << "std::is_partition, -> " << std::boolalpha << rv << std::endl;

    auto it = std::is_sorted_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::is_sorted_until, -> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::is_heap_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::is_heap_until, -> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;
}

void algo_query_value(void)
{
    /*
    @ query value
    ===
    - find
        ~ find
        ~ adjacent_find
        ~ find_if
        ~ find_if_not
        ~ find_first_of
        ~ find_end

    - search
        ~ search
        ~ search_ranges
        ~ inner_product
        ~ partial_sum
        ~ sample

    - scan
        ~ reduce
        ~ accumulate
        ~ inclusive_scan
        ~ exclusive_scan
    
    - element
        ~ min_element
        ~ max_element
        ~ minmax_element
    
    - bound
        ~ lower_bound
        ~ upper_bound
    
    - 2-ranges
        ~ mismatch
        ~ lexicographical_compare
        ~ equal
    ===
    */

}

void algo_screte_rune(void)
{
    /*
    @ secret rune
    ===
    - *_if
    - copy_*
    - stable_*
    - *_n
    ===
    */

    std::cout << "nothing special, nothing biggy" << std::endl;

}

void algo_lone_island(void)
{
    /*
    @ lone island
    ===
    - for_each
    - transform
    ===
    */

    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });
    std::for_each(v.begin(), v.end(), [](const auto& e){ std::cout << e << " "; });
    
    std::list<int> l;
    std::transform(v.begin(), v.end(), std::back_inserter(l), [](const auto& e){
        return e * e;
    });
    TS::print("std::transform, l-> ", l);
    
}

void algo_raw_memory(void)
{
    /*
    @ raw memory
    ===
    - uninitialized_*
    - initialized_*
    ===
    */

    
}
