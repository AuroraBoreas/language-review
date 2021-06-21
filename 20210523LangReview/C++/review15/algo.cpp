#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end());
    TS::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end(), std::less<>());
    TS::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 0, -1, 1, 99};
    TS::print("original, v-> ", v);

    std::sort(std::begin(v), std::end(v));
    TS::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::reverse(v.cbegin(), v.cend());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.rbegin(), std::next(v.rbegin(), 3), v.rend());
    TS::print("std::rotate, v-> ", v);

    auto is_even = [](const int& e){ return e%2==0; };
    std::partition(v.begin(), v.end(), is_even);
    TS::print("std::partition, v-> ", v);

    class IsEven
    {
        private:
           int m_e;

        public:
            IsEven(const int& e): m_e(e){};
            bool operator()(){ return m_e%2==0; }
    };

    auto it = std::partition_point(v.begin(), v.end(), IsEven());
    (it != std::end(v))
        ? std::cout << "std::partition_point, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

}

void TS::algo_structure_changer(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 0, -1, 1, 99};
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v = {3, 2, 1, 99, 99, 0, -1, 1, 99};
    v.erase(std::unique(v.begin(), v.end()));
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 0, -1, 1, 99};
    TS::print("original, v-> ", v);

    std::list<int> l;
    std::copy(v.begin(), v.end(), std::inserter(l, l.begin()));
    TS::print("std::copy, l-> ", l);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    for(auto& t : lt) t.join();

    l.clear();
    std::move_backward(vt.begin(), vt.end(), lt.begin());
    for(auto& t: lt) t.join();

    std::vector<char> name = {'t', 's'};
    std::list<char> uname {'z', 'l'};
    std::swap_ranges(name.begin(), name.end(), std::front_inserter(uname));
    TS::print("std::swap_ranges, uname-> ", uname);

    std::cout << "std::merge, -> ";
    std::merge(name.begin(), name.end(),
               uname.begin(), uname.end(),
               std::ostream_iterator<char>(std::cout, " "));
    TS::newline();
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v(10, 1);
    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });
    TS::print("std::generate, v-> ", v);

    v = {42, 42, 42, 1, 42, 42, 42, 42, 42, 42};
    std::replace(v.begin(), v.end(), 42, 69);
    TS::print("std::replace, v-> ", v);
}

void TS::algo_set(void)
{
    using container = std::list<int>;
    container A { 1, 2, 3, 4, 5 };
    container B { 4, 5, 6, 7, 8 };
    TS::print("orignal A-> ", A);
    TS::print("orignal B-> ", B);

    container S;
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::front_inserter(S));
    TS::print("std::set_union, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::front_inserter(S));
    TS::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::front_inserter(S));
    TS::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::front_inserter(S));
    TS::print("std::set_symmetric_difference, S-> ", S);

    bool isSubset = std::includes(A.begin(), A.end(), B.begin(), B.end());
    isSubset
        ? std::cout << "std::includes, -> True " << std::endl
        : std::cout << "std::includes, -> False" << std::endl;
}

void TS::algo_query_value(void)
{
    // cai sapr
    std::vector v {3,2,1,4,5,5,6,7,8,9};
    std::vector w {3,2,1,4,5,5,6,7,8,9};
    TS::print("original, v-> ", v);

    auto it = std::find(v.begin(), v.end(), 1);
    (it != std::end(v))
        ? std::cout << "std::find, 1 at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::find_first_of(v.begin(), v.end(), w.begin(), w.end());
    (it != std::end(v))
        ? std::cout << "std::find_first_of, 5 at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::find_end(v.begin(), v.end(), w.begin(), w.end());
    (it != std::end(v))
        ? std::cout << "std::find_end, 4 at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]" << std::endl;

    std::sort(v.begin(), v.end());
    it = std::search(v.begin(), v.end(), 4);
    (it != std::end(v))
        ? std::cout << "std::search, 4 at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]" << std::endl;

    bool rv = std::binary_search(v.begin(), v.end(), 4);
    rv
        ? std::cout << "std::binary_search, -> True" << std::endl
        : std::cout << "std::binary_search, -> False" << std::endl;

    auto mi = std::min_element(v.begin(), v.end());
    std::cout << "std::min_element, mi-> " << *mi << std::endl;

    auto ma = std::max_element(v.begin(), v.end());
    std::cout << "std::max_element, ma-> " << *ma << std::endl;

    auto [mini, maxi] = std::minmax_element(v.begin(), v.end());
    std::cout << "std::minmax_element, mi-> " << *mini << ", ma-> " << *maxi << std::endl;

    int cnt = std::count(v.begin(), v.end(), 5);
    std::cout << "std::count, cnt-> " << cnt << std::endl;

    it = std::adjacent_find(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::adjacent_find, it-> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    double result = std::inner_product(v.begin(), v.end(), w.begin(), 0.0);
    std::cout << "std::inner_product, result-> " << result << std::endl;

    std::list<int> l;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::sample(v.begin(), v.end(),
                std::front_inserter(l), 3,
                mt);

    result = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << "std::accumumlate, result-> " << result << std::endl;

    std::cout << "std::inclusive_scan, -> " << std::endl;
    std::cout << "std::exclusive_scan, -> " << std::endl;

//    result = std::reduce(std::execution::par, v.begin(), v.end(), 0.0);
//    std::cout << "std::reduce, result-> " << result << std::endl;
}

void TS::algo_query_property(void)
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    TS::print("original, v-> ", v);

    bool rv = std::is_sorted(v.begin(), v.end());
    std::cout << "std::is_sorted, -> " << std::boolalpha << rv << std::endl;

    rv = std::is_heap(v.begin(), v.end());
    std::cout << "std::is_heap, -> " << std::boolalpha << rv << std::endl;

    rv = std::is_partitioned(v.begin(), v.end(), [](auto const& e){ return e%2==0; });
    std::cout << "std::is_partitioned, -> " << std::boolalpha << rv << std::endl;

    rv = std::is_permutation(v.begin(), v.end(), [](auto& e){ return e%2==0; });
    std::cout << "std::is_permutation, -> " << std::boolalpha << rv << std::endl;

    auto it = std::is_sorted_until(v.begin(), v.end());
    it = std::is_heap_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::is_sorted_until, it-> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::is_heap_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::is_heap_until, it-> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    std::list<int> l;
    std::adjacent_difference(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::adjacent_difference, l-> ", l);

    rv = std::any_of(v.begin(), v.end(), [](auto const& e){ return e%2==0; });
    std::cout << "std::any_of, -> " << std::boolalpha << rv << std::endl;

    auto f = [](auto& e){ return e%2==0; };
    rv = std::none_of(v.begin(), v.end(), f);
    std::cout << "std::none_of, -> " << std::boolalpha << rv << std::endl;

    rv = std::all_of(v.begin(), v.end(), f);
    std::cout << "std::all_of, -> " << std::boolalpha << rv << std::endl;

    it = std::lower_bound(v.begin(), v.end(), 4);
    (it != std::end(v))
        ? std::cout << "std::is_heap_until, it-> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    it = std::upper_bound(v.begin(), v.end(), 4);
    (it != std::end(v))
        ? std::cout << "std::is_heap_until, it-> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    std::cout << "std::mismatch" << std::endl;
    std::cout << "std::equal" << std::endl;
    std::cout << "std::lexicographic_compare" << std::endl;
}

void TS::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_copy
    - uninitialized_fill
    - uninitialized_move
    */

    std::cout << "raw memory: nothing biggy, nothing special" << std::endl;
}

void TS::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - is_*
    - *_copy
    */

    std::cout << "secret runes: nonthing biggy, nothing special" << std::endl;
}

void TS::algo_lone_island(void)
{
    std::vector<int> v(10, 69);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%10; });

    std::cout << "std::for_each, -> ";
    std::for_each(v.begin(), v.end(), [](const auto& e){
        std::cout << e << TS::b;
    });
    TS::newline();

    std::vector<char> name {'t', 's'};
    std::list<char> uname;
    std::transform(name.begin(), name.end(), std::back_inserter(uname), [](const auto& e){ return std::toupper(e); });
    TS::print("std::transform, -> ", uname);
}
