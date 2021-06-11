#include "algo.h"

void TS::algo_permutation_heap(void)
{
    /*
    @ heap
    ===
    - make_heap
    - pop_heap
    - push_heap
    ===
    */

    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    
    auto rnd = [](){
        return std::rand()%30;
    };

    std::generate(v.begin(), v.end(), rnd);
    TS::print("original, v-> ", v);
    
    TS::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);
    
    TS::pop_heap("std::pop_heap, v-> ", v);
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(rnd());
    std::push_heap(v.begin(), v.end(), std::greater<>());
    TS::print("std::push_heap, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    /*
    @ sort
    ===
    - partition
    - partition_point
    - sort
    - partial_sort

    - prev_permutation
    - next_permutation
    ===    
    */

    std::vector<int> v { 3, 2, 99, 99, -1, 0, 99, 1, 2 };
    TS::print("original, v-> ", v);
    std::partition(v.begin(), v.end(), [](const auto& e){
        return e%2==0;
    });
    TS::print("std::partition, v-> ", v);
    
    auto it = std::partition_point(v.begin(), v.end(), [](const auto& e){
        return e%2==0;
    });
    (it != std::end(v))
        ? std::cout << "partition point, pp-> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;    
}

void TS::algo_structure_changer(void)
{
    /*
    @ structure changer
    ===
    - remove
    - unique
    ===
    */

    std::vector<int> v { 3, 2, 99, 99, -1, 0, 99, 1, 2 };
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v = { 3, 2, 99, 99, -1, 0, 99, 1, 2 };
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);

}

void TS::algo_movers(void)
{
    /*
    @ movers
    ===
    - copy
    - move
    - move_backward
    - swap_ranges
    - shuffle
    - rotate
    - reverse
    ===
    */

    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
        return std::rand()%20;
    });
    TS::print("original, v-> ", v);

    std::list<int> l;
    std::copy(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::copy, l-> ", l);

    std::vector<std::thread> threads;
    std::list<std::thread> tl;
    
    threads.emplace_back(TS::func, 1);
    threads.emplace_back(TS::func, 2);
    threads.emplace_back(TS::func, 3);

    std::move(threads.begin(), threads.end(), std::back_inserter(tl));
    for(auto t : tl) t.join();

    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    std::rotate(v.begin(), v.begin()+3, v.end());
    TS::print("std::rotate, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);

    std::vector<char> n = {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    std::list<char>   m = {'1', '2', '3', '4', '5', '6', '7'};
    TS::print("before swap_ranges, n-> ", n);
    TS::print("m-> ", m);

    std::swap_ranges(std::begin(n), std::begin(n)+3, m.begin());
    TS::print("after swap_ranges, n-> ", n);
    TS::print("m-> ", m);

}


void TS::algo_value_modifiers(void)
{
    /*
    @ value modifiers
    ===
    - fill
    - iota
    - generate
    - replace
    ===    
    */

    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
        return std::rand()%20;
    });
    TS::print("std::generate, v-> ", v);

    std::replace(v.begin(), v.end(), 42, 69);
    TS::print("std::replace, v-> ", v);

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
    ===
    */

    std::set<int> A { 1, 2, 3, 4, 5 };
    std::set<int> B { 4, 5, 6, 7, 8 };
    
    std::cout << "A⋂B, -> ";
    std::set_intersection(A.begin(), A.end(), 
                        B.begin(), B.end(), 
                        std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A⋃B, -> ";
    std::set_union(A.begin(), A.end(),
                B.begin(), B.end(),
                std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A-B, -> ";
    std::set_difference(A.begin(), A.end(),
                    B.begin(), B.end(),
                    std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "A⊖B, -> ";
    std::set_symmetric_difference(A.begin(), A.end(),
                            B.begin(), B.end(),
                            std::ostream_iterator<int>(std::cout, " "));
    
    bool rv = std::includes(A.begin(), A.end(),
                        B.begin(), B.end());
    std::cout << "A⊆B, -> " << std::boolalpha << rv << std::endl;
                
}

void TS::algo_query_property(void)
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
        ~ is_partition_until

    - count
    
    ===    
    */

    std::vector<int> v { 1, 2, 8, 5, 99, 99, -1, 99, 1};
    TS::print("original, v-> ", v);

    bool rv = std::is_sorted(v.begin(), v.end(), [](const auto& e){
        return e%2==0;
    });

    std::cout << "v is_sorted, -> " << rv << std::endl;

    rv = std::is_heap(v.begin(), v.end(), std::greater<>{});
    std::cout << "v is_heap, -> " << rv << std::endl;
    
    rv = std::is_partitioned(v.begin(), v.end(), [](const auto& e){
        return e%2==0;
    });
    std::cout << "v is_partitioned, -> " << rv << std::endl;

    auto it = std::is_sorted_until(v.begin(), v.end(), std::less<>{});
    (it != std::endl(v))
        ? std::cout << "v is_sorted_until -> " << *it << std::endl;
        : std::cout << "[not found]" << std::endl;

    it = std::is_partitioned_until(v.begin(), v.end(), [](const auto& e){
        return e%2==0;
    });
    (it != std::end(v))
        ? std::cout << "v is partitioned_until -> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;
}

void TS::algo_query_values(void)
{
    /*
    @ query valeus
    ===
    - find
        ~ find
        ~ find_if
        ~ find_if_not
        ~ find_first_of
        ~ find_end
        ~ 

    - search
        ~ search
        ~ 

    - 2-ranges
        ~ equal
        ~ mismatch
        ~ lexicographic_compare

    - scan
        ~ inclusive_scan
        ~ exclusive_scan

    - minmax
        ~ min_element
        ~ max_element
        ~ minmax_element
    ===
    */

        
}

void TS::algo_secret_runes(void)
{
    /*
    @ secret runes
    ===
    - stable_*
    - *_if
    - copy_*
    - sort_*
    - 
    ===
    */
}

void TS::algo_lone_island(void)
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
    std::generate(v.begin(), v.end(), [](){
        return std::rand()%30;
    });

    std::cout << "std::for_each, -> ";    
    std::for_each(v.begin(), v.end(), [](const auto& e){
        std::cout << e << " ";
    });
    std::cout << std::endl;

    std::cout << "std::tansform, -> ";
    std::vector<char> name {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    std::list<char> upper;
    std::transform(v.begin(), v.end(), std::back_inserter(upper), [](const auto& c){
        return std::toupper(c)
    });

}

void TS::algo_raw_memory(void)
{
    /*
    @ raw_memory
    ===
    - uninitialized_*
    - initialized_*
    ===
    */
}