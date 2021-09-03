#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// make heap pop sort push
    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::less<>());
    TS::print("std::push_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print("std::pop_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    TS::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// psr

    std::partition(v.begin(), v.end(), [](const auto& e)->bool{ return e%2==0; });
    TS::print("std::partition, v-> ", v);

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    TS::print("std::partial_sort, v--> ", v);

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::random_device rd;
    std::mt19937 g{rd()};
    std::shuffle(v.begin(), v.end(), g);
    TS::print("std::shuffle, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::rotate, v-> ", v);
}

void TS::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// ru

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v={2,1,3,99,99,99,-1,0,1,99};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// cms
    TS::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    std::list<int> l;
    std::copy_backward(v.begin(), v.end(), l.end());
    TS::print("std::copy_backward, l-> ", l);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    TS::oformat("std::move, lt->\n");
    for(auto& t : lt) t.join();
    TS::newline();

    std::string m{"hello world"};
    std::string n("zhang liang");
    std::move_backward(m.begin(), m.end(), n.end());
    TS::print("std::move_backward, n-> ", n);

    m="hello world";
    n="zhang liang";
    std::swap_ranges(m.begin(), m.end(), n.begin());
    TS::print("std::swap_ranges, m-> ", m);
    TS::print("std::swap_ranges, n-> ", n);
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// figr
    std::fill(v.begin(), v.end(), 1);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 42);
    TS::print("std::replace, v-> ", v);

    std::random_device rd;
    std::mt19937 g(rd());
    std::generate(v.begin(), v.end(), g);
    TS::print("std::generate, v-> ", v);
}

void TS::algo_set(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// umdis
    std::vector<int> S;
    using container = std::set<int>;
    container A{1,2,3,4,5,5};
    container B{4,5,6,7,8,8};

    S.clear();
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.end()));
    TS::print("std::set_union, S-> ", S);

    S.clear();
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::merge, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_symmetric_differece, S-> ", S);
}

void TS::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// sebfs lem
    /// transform_exlusive_scan, transform_inclusive_scan;
    std::nth_element(v.begin(), v.begin()+3, std::end(v));
    TS::print("std::nth_element, v-> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    TS::oformat("std::minmax_element, min, max-> ");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    int const x(42);
    auto it = std::lower_bound(v.begin(), v.end(), x);
    TS::oformat("std::lower_bound, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), x);
    TS::oformat("std::upper_bound, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find(v.begin(), v.end(), x);
    TS::oformat("std:::find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{1,3};
    it = std::find_first_of(u.begin(), u.end(), v.begin(), v.end());
    TS::oformat("std::find_first_of, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find_end(u.begin(), u.end(), v.begin(), v.end());
    TS::oformat("std::find_end, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end());
    bool rv = std::binary_search(v.begin(), v.end(), 42);
    TS::oformat("std::binary_search, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    std::string m{"hello world"};
    std::string n{"o w"};
    auto iter = std::search(n.begin(), n.end(), m.begin(), m.end());
    TS::oformat("std::search, iter-> ");
    (iter != std::end(m))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";

    it = std::search_n(v.begin(), v.end(), 4, 99);
    TS::oformat("std::search, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    rv = std::equal(n.begin(), n.end(), m.begin());
    TS::oformat("std::equal, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::lexicographical_compare(n.begin(), n.end(), m.begin(), m.end());
    TS::oformat("std::lexicographical_compare, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [im, am] = std::mismatch(n.begin(), n.end(), m.begin());
    TS::oformat("std::mismatch, begend-> ");
    (im != std::end(m) && am != std::end(m))
        ? std::cout << *im << ", " << *am << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// cai sapr

    int n = std::count(v.begin(), v.end(), 99);
    TS::oformat("std::count, n-> ");
    std::cout << n << std::endl;

    double rv =std::accumulate(v.begin(), v.end(), 0.0);
    TS::oformat("std::accumulate, rv-> ");
    std::cout << rv << std::endl;

    std::vector<int> u{2,1,3,99,99,99,-1,0,1,99};
    rv = std::inner_product(u.begin(), u.end(), v.begin(), 0.0);
    TS::oformat("std::inner_product, rv-> ");
    std::cout << rv << std::endl;

    std::random_device rd;
    std::mt19937 g{rd()};
    TS::oformat("std::sample, v-> ");
    std::sample(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), 4, g);
    TS::newline();

    TS::oformat("std::adjacent_find, v-> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    TS::oformat("std::adjacent_find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    TS::oformat("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();
}

void TS::algo_raw_memory(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// raw_memory
    /**
     * uninitialized_default_construct
     * uninitialized_value_construct
     * uninitialized_fill
     * uninitialized_move
     * uninitialized_copy
    */
    TS::oformat("std::raw_memory, -> nothing biggy;");
}

void TS::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// lone_island
    /**
     * *_if
     * stable_*
     * *_n
     * *_is; *_is_until;
     * *_copy
    */
    TS::oformat("std::lone_island, -> nothing special;");
}

void TS::algo_secret_rune(void)
{
    std::vector<int> v{2,1,3,99,99,99,-1,0,1,99};
    TS::print("original, v-> ", v);
    /// ft

    TS::oformat("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](const int& e){ std::cout << e*2 << " "; });
    TS::newline();

    std::string m{"hello world"};
    std::string n;
    std::transform(m.begin(), m.end(), std::inserter(n, n.end()), [](const char& e){ return std::toupper(e); });
    TS::print("std::transform, n-> ", n);
}
