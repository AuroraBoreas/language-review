#include "algo.h"

void algo_permutation_heap(void)
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
    TS::print("original, v-> ", v);

    std::make_heap(std::begin(v), std::end(v));
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::less<>{});
    TS::print("std::push_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void algo_permutation_sort(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
        return std::rand()%10;
    });
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end(), std::greater<>());
    TS::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::partition(v.begin(), v.end(), [](auto const& e)->bool{
        return e%2==0;
    });
    TS::print("std::partition, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937_64 mt(rd);
    std::shuffle(v.begin(), std::next(v.begin(), 3), mt);
    TS::print("std::shuffle, v-> ", v);
}

void algo_structure_changer(void)
{
    std::vector<int> v {1,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void algo_mover(void)
{
    using container = std::vector<char>;
    container c1 = {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    container c2 = {'z', 'h', 'a', 'n', 'g', 'l', 'i', 'a', 'n', 'g'};
    std::list<char> l;
    TS::print("original, c1-> ", c1);

    std::copy(c1.begin(), c1.end(), std::back_inserter(l));
    TS::print("std::copy, l-> ", l);

    std::vector<std::thread> v;
    v.emplace_back(TS::func, 1);
    v.emplace_back(TS::func, 2);
    v.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(v.begin(), v.end(), std::back_inserter(lt));
    for(auto& t : lt) t.join();

    std::move_backward(c1.begin(), c2.end(), c2.end());
    TS::print("std::move_backward, c2-> ", c2);

    c1 = {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    c2 = {'z', 'h', 'a', 'n', 'g', 'l', 'i', 'a', 'n', 'g'};
    std::swap_ranges(c1.begin(), c1.end(), c2.begin());
    TS::print("std::swap_ranges, c2-> ", c2);
}

void algo_value_modifier(void)
{
    std::vector<int> v {1,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::replace(v.begin(), v.end(), 99, 69);
    TS::print("std::replace, v-> ", v);

    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 0);
    TS::print("std::iota, v-> ", v);

    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), []()->int{ return std::rand()%30; });
    TS::print("std::generate, v-> ", v);
}

void algo_set(void)
{
    using container = std::set<int>;
    container a = { 1, 2, 3, 4, 5 };
    container b = { 4, 5, 6, 7, 8 };
    std::vector<int> s;
    TS::print("a -> ", a);
    TS::print("b -> ", b);

    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_intersection, s-> ", s);

    s.clear();
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_union, s-> ", s);

    s.clear();
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_difference, s-> ", s);

    s.clear();
    std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_symmetric_difference, s-> ", s);

    bool rv = std::includes(a.begin(), a.end(), b.begin(), b.end());
    rv? std::cout << "a includes b? -> " << std::boolalpha << rv << std::endl : std::cout << "[not found]\n";
}

void algo_query_property(void)
{
    // @ cai sap
    std::vector<int> v(10);
    std:srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%20; });
    std::cout << std::setw(TS::w) << std::setfill(TS::b) << "original, v-> ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    bool rv = std::is_sorted(v.begin(), v.end(), std::greater<>{});
    rv? std::cout << "std::is_sorted? -> " << std::boolalpha << rv << std::endl : std::cout << "[nope]\n";

    rv = std::is_partitioned(v.begin(), v.end(), std::greater<>{});
    rv? std::cout << "std::is_partitioned? -> " << std::boolalpha << rv << std::endl : std::cout << "[nope]\n";

    rv = std::is_heap(v.begin(), v.end(), std::greater<>{});
    rv? std::cout << "std::is_heap? -> " << std::boolalpha << rv << std::endl : std::cout << "[nope]\n";

    auto it = std::is_sorted_until(v.begin(), v.end(), std::less<>());
    (it != std::end(v))
        ? std::cout << "std::is_sorted_until -> " << *it << std::endl
        : std::cout << "nope\n";

    it = std::is_heap_until(v.begin(), v.end(), std::less<>());
    (it != std::end(v))
        ? std::cout << "std::is_heap_until -> " << *it << std::endl
        : std::cout << "nope\n";

    std::list<int> l;
    std::partial_sum(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::partial_sum, l-> ", l);

    l.clear();
    std::inclusive_scan(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::inclusive_scan, l-> ", l);

    l.clear();
    std::exclusive_scan(std::execution::par, v.begin(), v.end(), std::back_inserter(l), 0);
    TS::print("std::exclusive_scan, l-> ", l);

    auto begin = std::chrono::high_resolution_clock::now();
    double result = std::reduce(std::execution::par, v.cbegin(), v.cend());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = end - begin;
    std::cout << "std::reduce result " << result << ms.count() << " ms\n";

    begin = std::chrono::high_resolution_clock::now();
    result = std::accumulate(v.cbegin(), v.cend(), 0.0);
    end = std::chrono::high_resolution_clock::now();
    ms = end - begin;
    std::cout << "std::accumulate, result-> " << result << ms.count() << " ms\n";

    std::vector<double> x(10, 1.0), y(10, 1.0);
    result = std::transform_reduce(std::execution::par, x.cbegin(), x.cend(), y.begin(), 0.0);
    std::cout << "std::transform_reduce, result-> " << result << "\n";

    l.clear();
    std::adjacent_difference(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::adjacent_difference, l-> ", l);

    result = std::inner_product(x.begin(), x.end(), y.begin(), 1);
    std::cout << "std::inner_product, result-> " << result << std::endl;
}

void algo_query_value(void)
{
    std::vector<int> v{0, 2, 3, 25, 5};
    std::vector<int> t{3, 19, 10, 2};
    TS::print("original, v-> ", v);
    TS::print("original, t-> ", t);

    auto it = std::find(v.cbegin(), v.cend(), 2);
    (it != std::end(v))
        ? std::cout << "std::find, index of 1st 2 -> " << std::distance(v.cbegin(), it) << std::endl
        : std::cout << "[not found]\n";

    it = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());
    (it != std::end(v))
        ? std::cout << "std::find_first_of, equal to 3, 19, 10, 2 -> " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    it = std::find_end(v.begin(), v.end(), t.begin(), t.end());
    (it != std::end(v))
        ? std::cout << "std::find_end, equal to 3, 19, 10, 2 -> " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
}

void algo_raw_memory(void)
{
    /*
    - unintialized_default_construct
    - unintialized_value_construct
    - unintialized_fill
    - unintialized_move
    - unintialized_copy
    - destory
    */
    std::cout << "algo_raw_memory, nothing special, nothing biggy\n";
}

void algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_is
    - is_*_until
    - *_copy
    - *_n
    */
    std::cout << "secret_runes, nothing special, nothing biggy\n";
}

void algo_lone_island(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });

    std::cout << "std::for_each, v-> ";
    std::for_each(v.begin(), v.end(), [](auto const& e){
        std::cout << e << TS::b;
    });
    std::cout << std::endl;

    std::vector<char> n {'t', 'a', 'n', 'g', 's', 'a', 'i'};
    std::list<char> l;
    std::transform(v.begin(), v.end(), std::back_inserter(l), [](const auto& e){ return std::toupper(e); });
    TS::print("std::transform, l-> ", l);
}
