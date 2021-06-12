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

    std::vector<int> v { 3, 2, 1, 99, 99, -1, 0, 99, 1 };
    TS::print("original, v-> ", v);

    std::make_heap(std::begin(v), std::end(v), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::greater<>());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(69);
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
    - partial_sort
    - partial_sum (belongs to query value)

    - rotate
    - shuffle
    - prev_permutation
    - next_permutation
    ===
    */

    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end(), std::less<>{});
    TS::print("std::sort, des, v-> ", v);

    std::sort(v.begin(), v.end(), std::greater<>());
    TS::print("std::sort, asc, v-> ", v);

    std::partition(std::begin(v), std::end(v), [](const int& e){
                        return e%2==0;
                   });
    TS::print("std::partition, v-> ", v);

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    std::prev_permutation(v.begin(), v.end(), std::less<>{});
    TS::print("std::prev_permutation, v-> ", v);
    std::next_permutation(v.begin(), v.end(), std::less<>());
    TS::print("std::next_permutation, v-> ", v);
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

    std::vector<int> v { 3, 2, 4, 1, 99, 99, 99, 0, -1, 99 };
    TS::print("original, v-> ", v);
    v.erase(std::remove(v.begin(), v.end(), 99), std::end(v));
    TS::print("std::remove, v-> ", v);

    v = { 3, 2, 4, 1, 99, 99, 99, 0, -1, 99 };
    v.erase(std::unique(v.begin(), v.end()));
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
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
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
                    return std::rand()%20;
                  });
    TS::print("original, v-> ", v);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    for(auto& t : lt) t.join();

    using container = std::vector<std::string>;
    container c1 = { "tang", "sai" };
    container c2 = { "zhang", "liang" };
    TS::print("original, c1-> ", c1);
    TS::print("original, c2-> ", c2);
    std::move_backward(c1.begin(), c1.end(), c2.end());
    TS::print("std::move_backward, c1-> ", c1);
    TS::print("std::move_backward, c2-> ", c2);

    c1 = { "tang", "sai" };
    c2 = { "zhang", "liang" };
    TS::print("original, c3-> ", c1);
    TS::print("original, c4-> ", c2);
    std::swap_ranges(c1.begin(), c1.end(), c2.begin());
    TS::print("swap_ranges, c3-> ", c1);
    TS::print("swap_ranges, c4-> ", c2);
}

void TS::algo_value_modifier(void)
{
    /*
    @ value modifier
    ===
    - fill
    - generate
    - iota
    - replace
    ===
    */

    using container = std::vector<int>;

    container v(10);
    std::fill(v.begin(), v.end(), 69);
    TS::print("std::fill, v-> ", v);

    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%10; });
    TS::print("std::generate, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    container w { 42, 42, 69, 3, 1, 2, 99, 99, 1 };
    TS::print("original, w-> ", w);
    std::replace(w.begin(), w.end(), 42, 69);
    TS::print("std::replace, w-> ", w);
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

    using container = std::vector<int>;
    container A { 1, 2, 3, 4, 5 };
    container B { 4, 5, 6, 7, 8 };
    container C;
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));
    TS::print("std::set_union, C-> ", C);

    C.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));
    TS::print("std::set_intersection, C-> ", C);

    C.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));
    TS::print("std::set_difference, C-> ", C);

    C.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));
    TS::print("std::set_symmetric_difference, C-> ", C);

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    (rv)
        ? std::cout << "set A includes set B :)" << std::endl
        : std::cout << "set A not includes set B :O" << std::endl;

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

    - is_*_until
        ~ is_sorted_until
        ~ is_heap_unitil

    - minmax
        ~ min_element
        ~ max_element
        ~ minmax_element

    - scan
        ~ inclusive_scan
        ~ exclusive_scan

    -
    ===
    */

    std::vector<int> v { 4, 3, 1, 2, 5 };
    TS::print("original, v-> ", v);

    bool rv = std::is_sorted(v.begin(), v.end(), std::less<>{});
    (rv)
        ? std::cout << "v is sorted, des" << std::endl
        : std::cout << "v is not sorted, des" << std::endl;

    rv = std::is_heap(v.begin(), v.end());
    (rv)
        ? std::cout << "v is heap " << std::endl
        : std::cout << "v is not heap " << std::endl;

    rv = std::is_partitioned(v.begin(), v.end(), [](auto const& e){
                                return e%2==0;
                             });
    (rv)
        ? std::cout << "v is partitioned " << std::endl
        : std::cout << "v is not partitioned\n";

    auto it = std::is_sorted_until(v.begin(), v.end(), std::greater<>{});
    (it != std::end(v))
        ? std::cout << "v is sorted until -> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::is_heap_until(v.begin(), v.end(), std::less<>());
    (it != std::end(v))
        ? std::cout << "v is heap until -> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    auto mi = std::min_element(v.begin(), v.end());
    (mi != std::end(v))
        ? std::cout << "min_element of v -> " << *mi << std::endl
        : std::cout << "[not found]" << std::endl;

    auto ma = std::max_element(v.begin(), v.end(), std::greater<>{});
    (ma != std::end(v))
        ? std::cout << "max_element of v -> " << *ma << std::endl
        : std::cout << "[not found]" << std::endl;

    auto [pmi, pma] = std::minmax_element(v.begin(), v.end());
    std::cout << "minmax pair, min -> " << *pmi << ", max -> " << *pma << std::endl;
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
        ~ find_first_of
        ~ find_end

    - search
        ~ search
        ~ search_n
        ~ binary_search

    - match
        ~ equal
        ~ mismatch
        ~ lexicographical_compare

    ===
    */

    std::vector<int> v { 1, 99, 42, 69, 99, 99, 1, -1, 0, 99 };
    TS::print("original, v-> ", v);

    auto it = std::find(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "find 1st 99 at index of " << std::distance(std::begin(v), it) << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::find_if(v.begin(), v.end(), [](const auto& e){ return e%42==0; });
    (it != std::end(v))
        ? std::cout << "find 1st e%42 == 0 at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::find_if_not(v.begin(), v.end(), [](auto const& e){ return e%2==0; });
    (it != std::end(v))
        ? std::cout << "find 1st e%2 == 0 at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]" << std::endl;

}

void TS::algo_secret_runes(void)
{
    /*
    @ secret runes
    ===
    - stable_*
    - *_if
    - copy_*
    - is_*
    - is_*_until
    - *_n
    ===
    */

    std::cout << "nothing special, nothing biggy" << std::endl;
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
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });

    std::cout << "std::for_each, v-> ";
    std::for_each(v.begin(), v.end(), [](auto const& e)->void{ std::cout << e << " "; });
    std::cout << std::endl;

    using container = std::list<char>;
    container c1 { 't', 'a', 'n', 'g', 's', 'a', 'i' };
    container c2;
    std::transform(c1.begin(), c1.end(), std::back_inserter(c2), [](auto const& e){ return std::toupper(e); });
    TS::print("std::transform, c2 ->", c2);
}

void TS::algo_raw_memory(void)
{
    std::cout << "raw memory skipped" << std::endl;
}
