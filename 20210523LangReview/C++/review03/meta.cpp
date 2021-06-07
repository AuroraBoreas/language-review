#include "meta.h"

template<class T>
void TS::print(const std::string& comment, std::vector<T>v)
{
    std::cout << comment;
    std::for_each(v.begin(), v.end(), [](const T& e){
                    std::cout << e << " ";
                  });
    std::cout << "\n";
}

void TS::func(const int& i)
{
    std::this_thread::sleep_for(std::chrono::seconds(i));
    std::cout << "thread " << i << " ended" << std::endl;
}

void TS::algo_permutation_heap(void)
{
    // make heap pop
    // make_heap
    // pop_heap
    // push_heap
    // heap_sort
    std::vector<int> v(10);
    std::iota(std::begin(v), std::end(v), 1);
    TS::mprint("original,            v-> ", v);
    std::make_heap(v.begin(), v.end());
    TS::mprint("std::make_heap(max), v-> ", v);
    // min heap
    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::mprint("std::make_heap(min), v-> ", v);
    std::pop_heap(std::begin(v), std::end(v));
    auto btm = v.back(); v.pop_back();
    std::cout << "btm -> " << btm << std::endl;
    TS::mprint("std::pop_heap,       v-> ", v);
    v.push_back(13);
    std::push_heap(v.begin(), v.end());
    TS::mprint("std::push_heap,      v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    // sort
    // partial_sort
    // partition
    // prev_permutation
    // next_permutation
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%20; });
    TS::mprint("std::fill, v-> ", v);

    std::sort(v.begin(), v.end());
    TS::mprint("std::sort, v-> ", v);
    std::partial_sort(v.begin(), v.begin()+3, v.end());
    TS::mprint("std::partial_sort, v-> ", v);

    auto is_even = [](const int& i){ return i%2==0; };
    std::partition(v.begin(), v.end(), is_even);
    TS::mprint("std::partition, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::mprint("std::prev_permutation, v-> ", v);
    std::next_permutation(v.begin(), v.end());
    TS::mprint("std::next_permutation, v-> ", v);
}

void TS::algo_structure_changer(void)
{
    // P U R
    // partition

    std::list<char> name{ 't', 'a', 'a', 'n', 'n', 'g', 's', 's','a', 'i' };
    TS::mprint("original, name-> ", name);
    // remove
    name.erase(std::remove(std::begin(name), std::end(name), 'a'), name.end());
    TS::mprint("std::remove, name-> ", name);

    // unique
    name.erase(std::unique(name.begin(), name.end()), name.end());
    TS::mprint("std::unique, name-> ", name);

}

void TS::algo_movers(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%20; });
    TS::mprint("original: v-> ", v);

    // copy
    std::list<int> w(10);
    std::copy(v.begin(), v.end(), std::back_inserter(w));
    TS::mprint("std::copy, w-> ", w);

    // move
    // some type(function, thread etc) are not copyable in C++
    // u have to std::use move instead;
    std::vector<std::thread> v1;
    v1.emplace_back(TS::func, 1);
    v1.emplace_back(TS::func, 2);
    v1.emplace_back(TS::func, 3);

    std::list<std::thread> w1;
    std::move(v1.begin(), v1.end(), std::back_inserter(w1));
    for(auto& e : w1) e.join();

    // forward
    // move_backward
}

void TS::algo_value_modifiers(void)
{
    std::vector<int> v(10, 42);
    TS::mprint("original, v-> ", v);
    // fill
    std::fill(v.begin(), v.end(), 69);
    TS::mprint("std::fill, v-> ", v);
    // iota
    std::iota(v.begin(), v.end(), 1);
    TS::mprint("std::iota, v-> ", v);
    // generate
    std::srand(std::time(nullptr));
    std::generate(std::begin(v), std::end(v), [](){ return std::rand()%20; });
    TS::mprint("std::generate, v-> ", v);
    // replace
    v = { 42, 1, 1, 2, 32, 42, 99, -1, 0, 42 };
    TS::mprint("original, v-> ", v);
    std::replace(v.begin(), v.end(), 42, 69);
    TS::mprint("std::replace, v-> ", v);
}

void TS::algo_set(void)
{
    // intersection
    // union
    // difference
    // symmetric_difference
    // subset?
    std::set<int> A { 1,2,3,4,5 };
    std::set<int> B { 4,5,6,7,8 };
    TS::mprint("set A -> ", A);
    TS::mprint("set B -> ", B);

    std::cout << "\nA intersection B -> ";
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nA union B -> ";
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nA difference B -> ";
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nA symmetric_difference B -> ";
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    std::cout << "\nA subset B? -> " << std::boolalpha << rv << std::endl;
}


void TS::algo_query_property(void)
{
    std::srand(std::time(nullptr));
    std::vector<int> v(10, 69);
    auto f = [](){ return std::rand()%20; };
    std::generate(v.begin(), v.end(), f);
    TS::mprint("original, v-> ", v);

    // is_sorted
    bool rv = std::is_sorted(v.begin(), v.end(), std::less<>{});
    std::cout << "v is sorted? -> " << rv << std::endl;
    // is_sorted_until
    v = { 1, 2, 3, 4, 5, 7, 6, 3, 9, 10 };
    TS::mprint("orignal, v-> ", v);
    auto it = std::is_sorted_until(v.begin(), v.end());
    std::cout << "v is sorted until -> " << *it << std::endl;

    // is_heap
    rv = std::is_heap(v.begin(), v.end(), std::greater<>());
    std::cout << "v is heap? -> " << rv << std::endl;

    // is_heap_until
    it = std::is_heap_until(v.begin(), v.end());
    (it != std::end(v))
        ? std::cout << "v is heap until -> " << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    // is_partition
    rv = std::is_partitioned(v.begin(), v.end(), [](const auto& e){ return e%2==0; });
    std::cout << "v is partitioned? -> " << rv << std::endl;
}

void TS::algo_query_value(void)
{
    std::vector<int> v { 1, 3, 2, 2, 4, 3, 1 };
    TS::mprint("original, v-> ", v);
    // count
    int i = std::count(v.begin(), v.end(), 2);
    std::cout << "there are " << i << " 2s in v" << std::endl;
    // find
    auto it = std::find(v.begin(), v.end(), 2);
    std::cout << "find the 1st 2 at index : " << std::distance(std::begin(v), it) << std::endl;
    // find_if
    it = std::find_if(v.begin(), v.end(), [](const auto& e){ return e%4==0; });
    (it != std::end(v))
        ? std::cout << "find the 1st 4 at index : " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    // binary search
    std::sort(v.begin(), v.end());
    bool rv = std::binary_search(v.begin(), v.end(), 4);
    (rv)
        ? std::cout << "find 4 in v -> \n"
        : std::cout << "[not found]";
    // binary search

}

void TS::algo_secret_runes(void)
{
    // F R C
    // find_if
    // find_if_not
    // remove_if
    // count_if
    std::cout << "nothing special, nothing biggy" << std::endl;
}

void TS::algo_lone_island(void)
{
    std::vector<char> v { 't', 'a', 'n', 'g', 's', 'a', 'i' };
    // std::srand(std::time(nullptr));
    // std::generate(v.begin(), v.end(), [](){ return std::rand()%5; });
    // for_each
    std::for_each(v.begin(), v.end(), [](const auto& e){
                    std::cout << e << " ";
                  });
    std::cout << std::endl;
    // transform
    std::list<int> w;
    std::transform(v.begin(), v.end(), std::back_inserter(w), [](const auto& e){
                    return std::toupper(e);
                   });
    std::cout << "std::transform, w-> ";
    std::copy(w.begin(), w.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << std::endl;

}
