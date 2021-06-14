#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v {1, 3, 5, 99, 99, 0, -1, 99};
    TS::print("original, v-> ", v);
    
    std::make_heap(v.begin(), v.end(), std::less<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::greater<>());
    TS::print("std::push_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v {1, 3, 5, 99, 99, 0, -1, 99};
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), v.begin()+3, v.end());
    TS::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);
}

void TS::algo_structure_changer(void)
{
    std::vector<int> v {1, 3, 5, 99, 99, 0, -1, 99};
    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v = {1, 3, 5, 99, 99, 0, -1, 99};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);

}

void TS::algo_mover(void)
{
    std::vector<int> v;
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });
    
    std::list<int> l;
    std::copy(l.cbegin(), l.cend(), std::back_inserter(l));
    TS::print("std::copy, l-> ", l);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.crbegin(), vt.crend(), std::back_inserter(lt));
    for(auto& t : lt) t.join();

    lt.clear();
    std::move_backward(vt.cbegin(), vt.cend(), lt.begin());
    for(auto& t: lt) t.join();

    using container = std::vector<char>;
    container a {'t', 'a', 'n', 'g', ' ', 's', 'a', 'i'};
    container b {'z', 'h', 'a', 'n', 'g', ' ', 'l', 'i', 'a', 'n', 'g'};

    std::swap_ranges(a.cbegin(), a.cend(), b.cbegin());
    TS::print("std::swap_ranges, b-> ", b);

}

void TS::algo_value_modifier(void)
{
    std::vector<int> v;
    std::fill(std::begin(v), std::end(v), 42);
    TS::print("std::fill, v-> ", v);

    v.clear();
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){
        return std::rand()%30;
    });
    TS::print("std::generate, v-> ", v);

    v.clear();
    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    v = {1, 2, 42, 42, -1, 0, 99};
    TS::print("original, v-> ", v);
    std::replace(v.begin(), v.end(), 42, 69);
    TS::print("std::replace, v-> ", v);
}

void TS::algo_set(void)
{
    using container = std::vector<int>;
    container a {1,2,3,4,5};
    container b {4,5,6,7,8};
    std::set<int> s;

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

    bool rv;
    rv = std::includes(a.begin(), a.end(), b.begin(), b.end());
    std::cout << "std::includes? rv-> " << std::boolalpha << rv << std::endl;
}

void TS::algo_query_property(void)
{
    std::vector<int> v {1, 3, 5, 99, 99, 0, -1, 99};
    std::vector<int> w {1, 3, 5, 99, 99, 0, -1, 99};
    bool rv;
    rv = std::is_sorted(v.begin(), v.end());
    std::cout << "std::is_sorted? rv-> " << std::boolalpha << rv << std::endl;

    rv = std::is_heap(v.begin(), v.end());
    std::cout << "std::is_heap? rv-> " << std::boolalpha << rv << std::endl;

    rv = std::is_partitioned(v.begin(), v.end(), [](const auto& e){ return e%2==1; });
    std::cout << "std::is_partitioned? rv-> " << std::boolalpha << rv << std::endl;

    rv = std::is_permutation(v.begin(), v.end(), w.begin());
    std::cout << "std::is_permutation? rv-> " << std::boolalpha << rv << std::endl;

    auto it = std::is_sorted_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::is_sorted_until, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    auto it = std::is_heap_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::is_heap_until, -> " << *it << std::endl
        : std::cout << "[not found]\n";
    
    int cnt = std::count(v.begin(), v.end(), 99);
    std::cout << "std::count, -> " << cnt << " 99s in v" << std::endl;

    double result = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << "std::accumulate, result-> " << result << std::endl;

    result = std::reduce(std::execution::par, v.begin(), v.end(), 0.0);
    std::cout << "std::reduce, result-> " << result << std::endl;

    result = std::inner_product(v.begin(), v.end(), w.begin(), 1);
    std::cout << "std::inner_product, result-> " << result << std::endl;

    std::random_device rd;
    std::mt19937_64 mt(rd());
    w.clear();
    std::sample(v.begin(), v.end(), w.begin(), 3, mt);
    TS::print("std::sample, w-> ", w);

    std::cout << "adjacent_difference";
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void TS::algo_query_value(void)
{
    std::vector<int> v {1, 3, 5, 99, 99, 0, -1, 99};
    
    auto it = std::find(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std::find, v-> " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    it = std::search(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std::search, v-> " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    bool rv = std::binary_search(v.begin(), v.end(), 99);
    (rv)
    ? std::cout << "std::binary_search, v-> " << std::boolalpha << rv << std::endl
    : std::cout << "[not found]\n";

    std::cout << "std::partial_sum, -> ";
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << "std::equal, -> " << std::endl;
    std::cout << "std::mismatch, -> " << std::endl;
    std::cout << "std::lexicographical_compare, ->" << std::endl;
}

void TS::algo_raw_memory(void)
{
    /*
    - unintialized_default_construct
    - unintialized_copy
    - unintialized_value_construct
    - unintialized_fill
    - unintialized_move
    */

    std::cout << "raw memory, nothing biggy" << std::endl;

}

void TS::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - *_is
    - is_*_until
    - copy_*
    */

    std::cout << "nothing special, nothing biggy" << std::endl;
}

void TS::algo_lone_island(void)
{
    std::array<int, 10> a;
    a.fill(42);

    std::cout << "std::for_each, a-> ";
    std::for_each(a.crbegin(), a.crend(), [](auto const& e){
        std::cout << e << TS::b;
    });
    std::cout << std::endl;

    std::vector<char> name {'t', 'a', 'n', 'g', ' ', 's', 'a', 'i'};
    std::list<char> upname;
    std::transform(name.begin(), name.end(), std::back_inserter(upname), [](const auto& e){
        return std::toupper(e);
    });
    TS::print("std::transform, upper-> ", upname);

}
