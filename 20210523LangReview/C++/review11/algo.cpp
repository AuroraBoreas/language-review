#include "algo.h"


void SCY::algo_permutation_heap(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    SCY::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    SCY::print("std::make_heap, v-> ", v);

    std::pop_heap(std::begin(v), std::end(v), std::less<>());
    SCY::print("std::pop_heap, v-> ", v);

    v.push_back(69);
    std::push_heap(v.begin(), v.end(), std::less<>{});
    SCY::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    SCY::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    SCY::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    SCY::print("std::next_permutation, v-> ", v);
}

void SCY::algo_permutation_sort(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    SCY::print("original, v-> ", v);

    auto isEven = [](const int& e)noexcept->bool{ return e%2==0; };
    std::partition(v.begin(), v.end(), isEven);
    SCY::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), isEven);
    (it != std::end(v))
        ? std::cout << "std::partition_point -> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end(), std::greater<>{});
    SCY::print("std::sort, v-> ", v);

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    SCY::print("std::rorate, v-> ", v);

    std::shuffle(v.begin(), v.end(), std::mt19937(std::random_device{}));
    SCY::print("std::shuffle, v-> ", v);
}

void SCY::algo_structure_changer(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    SCY::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    SCY::print("std::remove, v-> ", v);

    v = {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    v.erase(std::unique(v.begin(), v.end(), 99), v.end());
    SCY::print("std::erase, v-> ", v);
}

void SCY::algo_mover(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    SCY::print("original, v-> ", v);

    std::list<int> l;
    std::copy(v.begin(), v.end(), std::back_inserter(l));
    SCY::print("std::copy, l-> ", l);

    std::copy_backward(v.begin(), v.end(), std::front_inserter(l));
    SCY::print("std::copy_backward, v-> ", v);

    std::vector<std::thread> vt;
    vt.emplace_back(SCY::func, 1);
    vt.emplace_back(SCY::func, 2);
    vt.emplace_back(SCY::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    std::cout << "std::move, l-> " << std::endl;
    for(auto& t : lt) t.join();
    SCY::newline();

    vt.emplace_back(SCY::func, 1);
    vt.emplace_back(SCY::func, 2);
    vt.emplace_back(SCY::func, 3);
    lt.clear();
    std::move_backward(vt.begin(), vt.end(), std::inserter(l, l.begin()));
    std::cout << "std::move_backward, l-> " << std::endl;
    for(auto& t : lt) t.join();
    SCY::newline();
    
    std::vector<char> name {'s', 'c', 'y'};
    std::list<char> uname;
    std::swap_ranges(name.begin(), name.end(), std::back_inserter(uname));
    SCY::print("std::swap_ranges, uname -> ", uname);
}

void SCY::algo_value_modifier(void)
{
    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 42);
    SCY::print("std::fill, v-> ", v);

    v.clear();
    std::srand(std::time(NULL));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    SCY::print("std::generate, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    SCY::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 42);
    SCY::print("std::replace, v-> ", v);
}

void SCY::algo_set(void)
{
    std::set<int> A {1,2,3,4,5};
    std::set<int> B {4,5,6,7,8};
    SCY::print("set A -> ", A);
    SCY::print("set B -> ", B);

    std::vector<int> S;
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    SCY::print("std::set_union, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    SCY::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    SCY::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    SCY::print("std::set_symmetric_difference, S-> ", S);    

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    rv
        ? std::cout << "std::includes -> true" << std::endl
        : std::cout << "std::includes -> false" << std::endl;
    SCY::newline();
}

void SCY::algo_query_property(void)
{
    // is_*
    // is_*_until
    // *_of
    // 2-ranges

    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    std::vector<int> w {1, 2, 3};
    SCY::print("original, v-> ", v);

    bool rv = std::is_sorted(v.begin(), v.end());
    std::cout << "std::is_sorted, -> " << std::boolalpha << rv << std::endl;

    rv = std::is_heap(v.begin(), v.end());
    std::cout << "std::is_heap, -> " << std::boolalpha << rv << std::endl;

    class IsEven
    {
        private:
            int m_e;
        public:
            IsEven(const int& e): m_e(e) {}
            bool operator()()
            { return this->m_e%2==0; }
    };

    rv = std::is_partitioned(v.begin(), v.end(), IsEven::operator());
    std::cout << "std::is_partitioned, -> " << std::boolalpha << rv << std::endl;

    rv = std::is_permutation(v.begin(), v.end(), w.begin());
    std::cout << "std::is_permutation, -> " << std::boolalpha << rv << std::endl;

    rv = std::any_of(v.begin(), v.end(), IsEven::operator());
    std::cout << "std::any_of, -> " << std::boolalpha << rv << std::endl;

    rv = std::all_of(v.begin(), v.end(), IsEven::operator());
    std::cout << "std::all_of, -> " << std::boolalpha << rv << std::endl;

    rv = std::none_of(v.begin(), v.end(), IsEven::operator());
    std::cout << "std::none_of, -> " << std::boolalpha << rv << std::endl;

    std::string in = "Occaecat sunt minim sint eu ut proident.";
    std::string ou = "sint";

    rv = std::equal(in.begin(), in.end(), ou.begin());
    std::cout << "std::equal" << std::boolalpha << rv << std::endl;

    auto [misa, misb] = std::mismatch(v.begin(), v.end(), v.begin());
    std::cout << "std::mismatch" << *misa << ", " << *misb << std::endl;

    rv = std::lexicographical_compare(v.begin(), v.end(), ou.begin(), ou.end());
    std::cout << "std::lexicographical_compare" << std::boolalpha << rv << std::endl;
}

void SCY::algo_query_value(void)
{
    // cai sapr
    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    SCY::print("original, v-> ", v);
    
    int n = std::count(v.begin(), v.end(), 99);
    std::cout << "std::count, n-> " << n << std::endl;
    
    auto it = std::adjacent_find(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "std:adjacent_find, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std:find, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::cout << "std::adjacent_difference, -> ";
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    SCY::newline();

    std::set<int> A {1,2,3,4,5};
    std::set<int> B {4,5,6,7,8};
    double rv = std::inner_product(A.cbegin(), A.cend(), B.cbegin(), 1);
    std::cout << "std::inner_product -> " << rv << std::endl;

    std::cout << "std::sample, -> ";
    std::sample(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), 3, std::mt19937(std::random_device{}));
    SCY::newline();

    rv = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << "std::accumulate, -> " << rv << std::endl;

    rv = std::reduce(v.begin(), v.end(), 0.0);
    std::cout << "std::reduce, -> " << rv << std::endl;

    std::cout << "std::partial_sum, -> ";
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    SCY::newline();

    auto [lb, ub] = std::equal_range(v.begin(), v.end(), 99);
    (lb != std::end(v))
        ? std::cout << "std::equal_range, -> " << *lb << ", " << *ub << std::endl
        : std::cout << "[not found]\n";
    
    it = std::lower_bound(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std::lower_bound, -> " << *it << std::endl
        : std::cout << "[not found]\n";
    
    it = std::upper_bound(v.begin(), v.end(), 99);
    (it != std::end(v))
        ? std::cout << "std::upper_bound, -> " << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end());
    rv = std::binary_search(v.begin(), v.end(), 99);
    rv
        ? std::cout << "std::binary_search, -> " << std::boolalpha << rv << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> s {2,1};
    auto iter = std::search(v.cbegin(), v.cend(), std::boyer_moore_searcher(s.begin(), s.end()));
    (iter != std::end(v))
        ? std::cout << "std::search -> " << (iter - v.begin()) << std::endl
        : std::cout << "[not found]\n";
    
    std::nth_element(v.begin(), std::next(v.begin(), 3), v.end());
    std::cout << "std::nth_element, -> " << v[3] << std::endl;

}

void SCY::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_copy
    - uninitialized_move
    - uninitialized_fill
    */
    std::cout << "raw memory -> nothing biggy, nothing special" << std::endl;  
}

void SCY::algo_secret_rune(void)
{
    /*
    - is_*
    - is_*_until
    - stable_*
    - *_n
    - *_if
    - *_copy
    */

    std::cout << "secret runes -> nothing biggy, nothing special" << std::endl;
}

void SCY::algo_lone_island(void)
{
    std::vector<int> v {3, 2, 1, 99, 99, 99, -1, 0, 99, 1};
    SCY::print("original, v-> ", v);
    
    std::cout << "std::for_each, -> ";
    std::for_each(v.begin(), v.end(), [](const auto& e){ std::cout << e << " "; });
    SCY::newline();

    std::list<char> n {'s', 'c', 'y'};
    std::vector<char> m {'z', 'l'};
    std::transform(n.begin(), n.end(), std::inserter(m, m.begin()), [](const char& e){ return std::toupper(e); });
    SCY::print("std::transform, -> ", m);
}
