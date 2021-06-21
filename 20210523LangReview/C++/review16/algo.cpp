#include "algo.h"

void SCY::algo_permutation_heap(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    SCY::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
    SCY::print("std::pop_heap, v-> ", v);

    v.push_back(69);
    std::push_heap(v.begin(), v.end());
    SCY::print("std::push_heap, v-> ", v);

    std::sort_heap(std::begin(v), std::end(V));
    SCY::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    SCY::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    SCY::print("std::next_permutation, v-> ", v);
}

void SCY::algo_permutation_sort(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    std::sort(v.cbegin(), v.cend(), std::greater<>());
    SCY::print("std::sort, v-> ", v);

    std::partial_sort(v.cbegin(), std::next(v.cbegin(), 3), v.cend());
    SCY::print("std::partial_sort, v-> ", v);

    class IsEven
    {
        private:
            int m_e;
        public:
            IsEven(int& e): m_e(e) {}
            bool operator()()
            { return m_e%2==0; }
    };
    std::partition(v.begin(), v.end(), IsEven::operator());
    SCY::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), IsEven::operator());
    (it != std::end(v))
        ? std::cout << "std::partition_point, it-> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    SCY::print("std::shuffle, v-> ", v);

    std::rotate(v.begin(), v.begin()+3, v.end());
    SCY::print("std::rotate, v-> ", v);
}

void SCY::algo_structure_changer(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    SCY::print("std::remove, v-> ", v);

    v = {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    v.erase(std::unique(v.begin(), v.end()));
    SCY::print("std::unique, v-> ", v);    
}

void SCY::algo_mover(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    std::list<int> l;
    std::copy(v.begin(), v.end(), std::inserter(l, l.begin()));
    SCY::print("std::copy, l-> ", l);

    l.clear();
    std::copy_backward(v.begin(), v.end(), std::front_inserter(l));
    SCY::print("std::copy_backward, l-> ", l);

    std::vector<std::this_thread> vt;
    vt.emplace_back(SCY::func, 1);
    vt.emplace_back(SCY::func, 2);
    vt.emplace_back(SCY::func, 3);

    std::list<std::this_thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    std::cout << "std::move, ->\n";
    for(auto& t : lt) t.join();

    vt.emplace_back(SCY::func, 1);
    vt.emplace_back(SCY::func, 2);
    vt.emplace_back(SCY::func, 3);
    lt.clear();
    std::move_backward(vt.begin(), vt.end(), lt.begin());
    std::cout << "std::move_backward, ->\n";
    for(auto& t : lt) t.join();

    std::vector<char> n {'s', 'c', 'y'};
    std::vector<char> m {'z', 'l'};
    std::swap_ranges(n.begin(), n.end(), m.begin());
    SCY::print("std::swap_ranges, n-> ", n);    
    SCY::print("std::swap_ranges, m-> ", m);

    std::list<char> merg;
    std::merge(n.begin(), n.end(), m.begin());
    SCY::print("std::merge, m-> ", m);
}

void SCY::algo_value_modifier(void)
{
    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 69);
    SCY::print("std::fill, v-> ", v);

    v.clear();
    std::iota(v.begin(), v.end(), 1);
    SCY::print("std::iota, v-> ", v);

    v.clear();
    std::srand(std::time(NULL));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    SCY::print("std::generate, v-> ", v);

    v.clear();
    std::replace(v.begin(), v.end(), 1, 42);
    SCY::print("std::replace, v-> ", v);
}

void SCY::algo_set(void)
{
    std::set<int> A {1,2,3,4,5};
    std::set<int> B {4,5,6,7,8};
    std::list<int> S;

    SCY::print("set A-> ", A);
    SCY::print("set B-> ", B);
    
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    SCY::print("std::set_union, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    SCY::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    SCY::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    SCY::print("std::set_symmetric_difference, S-> ", S);

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    rv
        ? std::cout << "std::includes -> False" << std::endl
        : std::cout << "std::includes -> True" << std::endl;
}

void SCY::algo_query_property(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    // find
    auto it = std::find(v.begin(), v.end(), 2);
    (it != std::end(v))
        ? std::cout << "std::find, -> " << *it << std::endl
        : std::cout << "[not found]\n";
    
    // search: binary_search, search_n
    // 2-ranges: equal, mismatch, lexicolgraphic_compare
    // *_of
    // *_bound

    it = std::find_first_of(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std::find_first_of, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find_end(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std::find_end, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end());
    bool rv = std::binary_search(v.begin(), v.end(), 99);
    rv
        ? std::cout << "std::binary_search, 99 -> True" << std::endl
        : std::cout << "std::binary_search, 99 -> False" << std::endl;
    
    // minmax_element
    it = std::min_element(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::min_element, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::max_element(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::max_element, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::minmax_element, -> " << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    // *_bound
    it = std::lower_bound(v.begin(), v.end(), 2);
    (it != std::end(v))
        ? std::cout << "std::lower_bound, -> " << *it << std::endl
        : std::cout << "[not found]\n";
    
    it = std::upper_bound(v.begin(), v.end(), 2);
    (it != std::end(v))
        ? std::cout << "std::upper_bound, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    // *_of
    auto f = [](const int& e){ return e%2==0; };
    rv = std::any_of(v.begin(), v.end(), f);
    rv
        ? std::cout << "std::any_of, -> True" << std::endl
        : std::cout << "std::any_of, -> False" << std::endl;
        
    rv = std::all_of(v.begin(), v.end(), f);
    rv
        ? std::cout << "std::all_of, -> True" << std::endl
        : std::cout << "std::all_of, -> False" << std::endl;

    rv = std::none_of(v.begin(), v.end(), f);
    rv
        ? std::cout << "std::none_of, -> True" << std::endl
        : std::cout << "std::none_of, -> False" << std::endl;
    
    // 2-ranges
    std::string in = "Qui anim duis proident consectetur pariatur deserunt Lorem nulla ex excepteur adipisicing cillum qui.";
    std::string ou = "anim";

    rv = std::equal(in.begin(), in.end(), ou.begin());
    rv
        ? std::cout << "std::equal, -> True" << std::endl
        : std::cout << "std::equal, -> False" << std::endl;

    rv = std::lexicolgraphical_compare(in.begin(), in.end(), ou.begin());
    rv
        ? std::cout << "std::lexicolgraphical_compare, -> True" << std::endl
        : std::cout << "std::lexicolgraphical_compare, -> False" << std::endl;

    it = std::mismatch(in.begin(), in.end(), ou.begin());
    (it != std::end(in))
        ? std::cout << "std::mismatch, -> " << *it << std::endl
        : std::cout << "[not found]\n" << std::endl;
}

void SCY::algo_query_value(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    // cai sapr
    // *_scan
    // nth_element
    // equal_range
    
    int cnt = std::count(v.begin(), v.end(), 99);
    std::cout << "std::find 99s -> " << cnt << std::endl;

    auto it = std::adjancent_find(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std::adjacent_find, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    double result = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << "std::accumulate, -> " << result << std::endl;

    result = std::reduce(std::execution::par, v.begin(), v.end(), 0.0);
    std::cout << "std::reduce, -> " << result << std::endl;

    result = std::inclusive_scan(v.begin(), v.end(), 0.0);
    std::cout << "std::inclusive_scan, -> " << result << std::endl;

    result = std::exclusive_scan(v.begin(), v.end(), 0.0);
    std::cout << "std::exclusive_scan, -> " << result << std::endl;

    std::vector<int> w {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    result = std::inner_product(v.begin(), v.end(), w.begin(), 1);
    std::cout << "std::inner_product, -> " << result << std::endl;

    std::list<int> l;
    std::sample(v.begin(), v.end(), std::back_inserter(l), 3, std::mt19937{std::random_device()});
    SCY::print("std::sample, -> ", l);

    result = std::partial_sum(v.begin(), v.end());
    std::cout << "std::partial_sum, -> " << result << std::endl;

    it = std::equal_range(v.begin(), v.end(), w.begin());
    (it != std::end(v))
        ? std::cout << "std::equan_range, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::nth_element(v.begin(), std::next(v.begin(), 3), v.end(), std::greater<>{});
    SCY::print("std::nth_element, v-> ", v);
}

void SCY::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_copy
    - uninitialized_fill
    - uninitialized_move
    */
    std::cout << "raw memory -> nothing biggy, notthing special" << std::endl;
}

void SCY::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - is_*
    - is_*_until
    - *_copy
    */
    std::cout << "secret rune -> nothing biggy, nothing special" << std::endl;
}

void SCY::algo_lone_island(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, 0, -1, 99, 1};
    SCY::print("original, v-> ", v);

    std::cout << "std::for_each, ->";
    std::for_each(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    SCY::newline();

    std::list<int> l;
    std::tranform(v.begin(), v.end(), std::back_inserter(l), [](auto const& e){ return e*e; });
    SCY::print("std::transform, l-> ", l);
}
