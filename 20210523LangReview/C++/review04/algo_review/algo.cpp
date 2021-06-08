#include "algo.h"

template<class T>
void TS::print(const std::string& c,  const std::vector<T>& v)
{
    std::cout << c;
    std::for_each(std::begin(v), std::end(v), [](const T& e){
        std::cout << e << " ";
    });
    std::cout << std::endl;
}

void TS::func(const int& i)
{
    std::this_thread::sleep_for(std::chrono::seconds(i));
    std::cout << "thread " << i << " ended\n";
}

void TS::algo_permutation_heap(void)
{
    /*
    @ heap
    ===
    - make_heap
    - pop_heap
    - push_heap
    - sort_heap?

    - prev_permutation
    - next_permutation
    ===
    */

    std::vector<int> v(5);
    std::srand(std::time(nullptr));
    auto rnd = [](){ return std::rand()%20; };
    for(int i=0; i<5; ++i)
    {
        v.push_back(rnd());
    }

    v = { 3, 4, 5, 6, 1 };
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print<int>("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print<int>("std::pop_heap, v-> ", v);
    int top = v.back();
    v.pop_back();
    std::cout << "top: " << top << std::endl;

    v.push_back(rnd());
    std::push_heap(v.begin(), v.end());
    TS::print<int>("std::push_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print<int>("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print<int>("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    /*
    @ sort
    ===
    - partition
    - sort
    - shuffle
    -
    ===
    */

    std::vector<int> v(5);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
                    return std::rand()%20;
                  });
    TS::mprint("original, v-> ", v);

    std::sort(v.begin(), v.end(), std::less<>{});
    TS::mprint("std::sort, v-> ", v);

    std::partition(v.begin(), v.end(), [](const int& e){
                        return e%2 == 0;
                   });
    TS::mprint("std::partitino, v-> ", v);

    std::random_device rd;
    std::mt19937 mt(rd());

    // std::shuffle can not be used on list collection;
    std::shuffle(v.begin(), v.end(), mt);
    TS::mprint("std::shuffle, v-> ", v);
}

void TS::algo_structure_changer(void)
{
    /*
    @ changer: R U P
    ===
    - remove
    - reverse
    - rotate

    - unique
    ===
    */
    std::vector<int> v{1, 5, 3, 99, 99, 99, -1, 0, 99, 1};
    TS::mprint("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), std::end(v));
    TS::mprint("std::remove, v-> ", v);

    v = {1, 5, 3, 99, 99, 99, -1, 0, 99, 1};
    std::reverse(v.begin(), v.end());
    std::cout << "std::reverse, v-> ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    v = {1, 5, 3, 99, 99, 99, -1, 0, 99, 1};
    std::rotate(v.begin(), v.begin()+3, v.end());
    TS::mprint("std::roate, v-> ", v);

    v = {1, 5, 3, 99, 99, 99, -1, 0, 99, 1};
    v.erase(std::unique(v.begin(), v.end()), std::end(v));
    TS::mprint("std::unique, v-> ", v);
}

void TS::algo_movers(void)
{
    /*
    @ movers
    ===
    - copy
    - move
    - swap_ranges
    - move_backward
    ===
    */
    std::vector<char> v {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    TS::mprint("original, v-> ", v);
    std::list<char> w;
    std::copy(v.begin(), v.end(), std::back_inserter(w));
    TS::mprint("std::copy, w-> ", w);

//    auto f = [](const int& i){
//        std::this_thread::sleep_for(std::chrono::seconds(i));
//        std::cout << "thread " << i << " ended\n";
//    };
    // ! TIL: can't init a collecton with std::thread;
    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> l;
    std::move(vt.begin(), vt.end(), std::back_inserter(l));
    for(auto& t: l) t.join();
}

void TS::algo_value_modifiers(void)
{
    /*
    @ modifiers
    ===
    - fill
    - generate
    - iota
    - replace
    ===
    */

    std::list<int> v(10);
    std::fill(v.begin(), v.end(), 1);
    TS::mprint("std::fill, v-> ", v);
    std::iota(v.begin(), v.end(), 1);
    TS::mprint("std::iota, v-> ", v);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
                    return std::rand()%20;
                  });
    TS::mprint("std::generate, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 2);
    TS::mprint("std::replace, v-> ", v);
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

    std::set<int> A { 1, 2, 3, 4, 5 };
    TS::mprint("set A -> ", A);
    std::set<int> B { 4, 5, 6, 7, 8 };
    TS::mprint("set B -> ", B);

    std::cout << "A intersection B -> ";
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "A union B -> ";
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "A difference B -> ";
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "A symmetric_difference B -> ";
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    std::cout << "A subset B? -> " << std::boolalpha << rv << std::endl;
    std::cout << std::endl;
}

void TS::algo_query_property(void)
{
    /*
    @ query property
    ===
    - is_*
        ~ is_heap
        ~ is_sorted
        ~ is_partition

    - is_*_until
        ~ is_heap_until
        ~ is_Sorted_until
    ===
    */
    auto print_result = [](const std::string& s, const bool& b){
        std::cout << s << std::boolalpha << b << std::endl;
    };

    std::vector<int> v { 1, 2, 3, 9, 0, 11, 13 };
    TS::mprint("original, v-> ", v);

    bool rv = std::is_heap(v.begin(), v.end(), std::greater<>{});
    print_result("std::is_heap, result -> ", rv);

    rv = std::is_sorted(v.begin(), v.end(), std::less<>{});
    print_result("std::is_sorted, result -> ", rv);

    rv = std::is_partitioned(v.begin(), v.end(), [](const auto& e){
                                return e%2==0;
                             });
    print_result("std::is_partitioned, result -> ", rv);

    auto it = std::is_heap_until(v.begin(), v.end(), std::greater<>{});
    (it != std::end(v))
        ? std::cout << "std::is_heap_until, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::is_sorted_until(v.begin(), v.end(), std::less<>{});
    (it != std::end(v))
        ? std::cout << "std::is_sorted_until, -> " << *it << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_query_value(void)
{
    /*
    @ query value
    ===
    - count
    - min_element
    - max_element
    - find
    - find_if
    - find_if_not
    - search
    - binary_search
    ===
    */

    std::vector<int> v{ 3, 2, 1, 99, -1, 99, 99, 1, 2};
    TS::mprint("original, v-> ", v);
    int cnt = std::count(v.begin(), v.end(), 99);
    std::cout << "there are " << cnt << " in v.\n";

    auto it = std::min_element(v.begin(), v.end());
    std::cout << "std::min_element, -> " << *it << std::endl;

    it = std::max_element(v.begin(), v.end());
    std::cout << "std::max_element, -> " << *it << std::endl;

    int target(1);
    it = std::find(v.begin(), v.end(), target);
    (it != std::end(v))
        ? std::cout << "found " << target << " at index of " << std::distance(std::begin(v), it) << std::endl
        : std::cout << "[not found]\n";

    const std::string str = "why waste time learning, when ignorance is instantaneous?";
    std::cout << std::boolalpha << in_quote(str, "learning") << "\n"
                                << in_quote(str, "learming") << "\n";
}

void TS::algo_secret_rune(void)
{
    /*
    @ runes
    ===
    - is_*
    - *_if
    - *
    - *_n
    - stable_*
    - copy_*
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
    - tansform
    ===
    */

    std::vector<int> v(5);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
                    return std::rand()%20;
                  });

    std::cout << "std::for_each, -> ";
    std::for_each(v.begin(), v.end(), [](const auto& e){
                    std::cout << e << " ";
                  });

    std::vector<char> name {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    std::list<char> name_up;
    std::transform(name.begin(), name.end(), std::back_inserter(name_up), [](const auto& e){
                        return std::toupper(e);
                   });
    TS::mprint("\nname(upper) : ->", name_up);
}
