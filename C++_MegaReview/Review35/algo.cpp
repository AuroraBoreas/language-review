#include "algo.h"

void algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
    TS::print("std::pop_heap, v-> ", v);

    int x(42);
    v.push_back(x);
    std::push_heap(v.begin(), v.end());
    TS::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    TS::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    // psr
    std::partition(v.begin(), v.end(), TS::IsEven());
    TS::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), [](const auto& e)->bool{ return e%2==0; });
    TS::oformat("std::partion_point, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), v.begin() + 3, v.end());
    TS::print("std::rotate, v-> ", v);
}

void algo_sctructure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    //  ru
    int x(99);
    v.erase(std::remove(v.begin(), v.end(), x), v.end());
    TS::print("std::remove, v-> ", v);

    v = {2,1,3,99,99,99,0,-1,99,1};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    // c m s
    TS::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    std::string m{"hello world"};
    std::string n{"zhang liang"};
    std::copy_backward(m.begin(), m.end(), n.end());
    TS::print("std::copy_backward, n-> ", n);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    TS::oformat("std::move, lt-> ");
    for(auto& t : lt) t.join();

}

void algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    /// figr
    x = 42
    std::fill(v.begin(), v.end(), x);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 42);
    TS::print("std::replace, v-> ", v);

    std::srand(std::time(NULL));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    TS::print("std::generate, v-> ", v);
}

void algo_set(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    using container = std::set<int>;
    container A{1,2,3,4,5,5};
    contianer B{4,5,6,7,8,8};
    std::vector<int> S;

    /// umdis
    S.clear();
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S))
    TS::print("std::set_union, S-> ", S);

    S.clear();
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S))
    TS::print("std::merge, S-> ", S);

    S.clear();
    std::set_differece(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S))
    TS::print("std::set_differece, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S))
    TS::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S))
    TS::print("std::set_symmetric_difference, S-> ", S);

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    TS::oformat("std::includes, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;
}

void algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    /// s e b f s
    // std::exclusive_scan; std::inclusive_scan
    std::nth_element(v.begin(), v.begin()+3, v.end());
    TS::print("std::nth_element, v-> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    TS::oformat("std::minmax_element, v-> ", v);
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    int x(42);
    auto lb = std::lower_bound(v.begin(), v.end(), x);
    TS::oformat("std::lower_bound, lb-> ");
    (lb != std::end(v))
        ? std::cout << *ln << std::endl
        : std::cout << "[not found]\n";

    auto ub = std::lower_bound(v.begin(), v.end(), x);
    TS::oformat("std::lower_bound, lb-> ");
    (ub != std::end(v))
        ? std::cout << *ub << std::endl
        : std::cout << "[not found]\n";

    auto it = std::find(v.begin(), v.end(), x);
    TS::oformat("std::find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{2,1};
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

    std::string m{"Consectetur deserunt dolor nostrud nisi minim non cillum consequat."};
    std::string n("r d");
    

}

void algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    /// cai sapr
}

void algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_fill
    - uninitialized_copy
    - uninitialized_move
    */

    TS::oformat("raw_memory, -> nothing biggy\n");
}

void algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - is_*, is_*_until
    - *_copy
    */

    TS::oformat("std::secret_rune, -> nothing biggy\n");
}

void algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);
}
