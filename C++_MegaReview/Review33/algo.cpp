#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end());
    TS::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    TS::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::partition(v.begin(), v.end(), [](const int& e){ return e%2==0; });
    TS::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), TS::IsEven());
    TS::oformat("std::partition_point, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

   std::sort(v.begin(), v.end());
   TS::print("std::sort, v-> ", v);

   std::partial_sort(v.begin(), v.begin()+3, v.end());
   TS::print("std::partial_sort, v-> ", v);

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
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    const int x(99);
    v.erase(std::remove(v.begin(), v.end(), x), v.end());
    TS::print("std::remove, v-> ", v);

    v = {2,1,3,99,99,99,0,-1,99,1};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    using container = std::vector<std::string>;
    container A{"hello", "world"};
    container B{"zhang", "liang"};
    TS::print("original, A-> ", A);
    TS::print("original, B-> ", B);

    std::copy_backward(A.begin(), A.end(), B.end());
    TS::print("std::copy_backward, B-> ", B);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    TS::oformat("std::move, v-> \n");
    for(auto& t : lt) t.join();

    A = {"hello", "world"};
    B = {"zhang", "liang"};
    std::move_backward(A.begin(), A.end(), B.end());
    TS::print("std::swap_ranges, A-> ", A);
    TS::print("std::swap_ranges, B-> ", B);

    A = {"hello", "world"};
    B = {"zhang", "liang"};
    std::swap_ranges(A.begin(), A.end(), B.begin());
    TS::print("std::swap_ranges, A-> ", A);
    TS::print("std::swap_ranges, B-> ", B);
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    const int x(42);
    std::fill(v.begin(), v.end(), x);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), x);
    TS::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), x, 69);
    TS::print("std::replace, v-> ", v);

    std::srand(std::time(NULL));
    auto mt = []()->int{ return std::rand()%30; };
    std::generate(v.begin(), v.end(), mt);
    TS::print("std::generate, v-> ", v);
}

void TS::algo_set(void)
{
    using container = std::set<int>;
    container A{1,2,3,4,5,5};
    container B{4,5,6,7,8,8};
    TS::print("original, A-> ", A);
    TS::print("original, B-> ", B);
    std::vector<int> S;

    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
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
    TS::print("std::set_symmetric_difference, S-> ", S);

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    TS::oformat("std::includes, S-> ");
    std::cout << std::boolalpha << rv << std::endl;
}

void TS::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    /// s e b f s
    // std::exclusive_scan; std::inclusive_scan;
    std::nth_element(v.begin(), v.begin()+3, v.end());
    TS::print("std::nth_element, v-> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    TS::oformat("std::minmax_element, minmax-> ");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    int x(42);
    auto lb = std::lower_bound(v.begin(), v.end(), x);
    TS::oformat("std::lower_bound, lb-> ");
    (lb != std::end(v))
        ? std::cout << *lb << std::endl
        : std::cout << "[not found]\n";

    auto ub = std::upper_bound(v.begin(), v.end(), x);
    TS::oformat("std::upper_bound, ub-> ");
    (ub != std::end(v))
        ? std::cout << *ub << std::endl
        : std::cout << "[not found]\n";

    x = -1;
    auto it = std::find(v.begin(), v.end(), x);
    TS::oformat("std::find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{3,99};
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
    it = std::search(u.begin(), u.end(), v.begin(), v.end());
    TS::oformat("std::search, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    bool rv = std::binary_search(v.begin(), v.end(), x);
    TS::oformat("std::binary_search, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    x = 99;
    it = std::search_n(v.begin(), v.end(), 4, x);
    TS::oformat("std::search_n, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    /// l e m
    std::string m("Duis elit nulla excepteur ullamco amet tempor.");
    std::string n("t nulla");

    rv = std::lexicographical_compare(n.begin(), n.end(), m.begin(), m.end());
    TS::oformat("std::lexicographical_compare, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::equal(n.begin(), n.end(), m.begin());
    TS::oformat("std::equal, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [im, am] = std::mismatch(n.begin(), n.end(), m.begin());
    TS::oformat("std::mismatch, headtail-> ");
    (im != std::end(m) && am != std::end(m))
        ? std::cout << *im << ", " << *am << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    int x(99);
    int cnt = std::count(v.begin(), v.end(), x);
    TS::oformat("std::count, cnt-> ");
    std::cout << cnt << std::endl;

    double rv = std::accumulate(v.begin(), v.end(), 0.0);
    TS::oformat("std::accumulate, rv-> ");
    std::cout << rv << std::endl;

    TS::oformat("std::adjacent_difference, v-> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    TS::oformat("std::adjacent_find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{2,1,3,99,99,99,0,-1,99,1};
    rv = std::inner_product(v.begin(), v.end(), u.begin(), 0.0);
    TS::oformat("std::inner_product, rv-> ");
    (it != std::end(v))
        ? std::cout << rv << std::endl
        : std::cout << "[not found]\n";

    TS::oformat("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    // std::reduce;
}

void TS::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_fill
    - uninitialized_move
    - uninitialized_copy
    */

    TS::oformat("std::raw_memory, -> nothing biggy\n");
}

void TS::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - is_*; is_*_until
    - *_copy
    */

    TS::oformat("std::secret_rune, -> nothing special\n");
}

void TS::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::oformat("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](const auto& e){ std::cout << e*e << " "; });
    TS::newline();

    std::string m("hello zhang liang");
    std::string n;
    std::transform(m.begin(), m.end(), std::inserter(n, n.begin()), [](const char& e){ return std::toupper(e);});
    TS::print("std::transform, n-> ", n);
}
