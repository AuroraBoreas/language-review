/*
c++, algorithm review

@ZL, 20210605
*/

#include "meta.h"

template<class T>
void TS::print(const std::string& comment, std::vector<T> v)
{
    std::cout << comment;
    std::for_each(v.begin(), v.end(), [](const T& elem){ std::cout << elem << ' '; });
    std::cout << std::endl;
}

template<typename U>
void TS::print(const std::string& comment, U result)
{
    std::cout << comment;
    std::cout << std::boolalpha << result << std::endl;
}

void TS::algo_permutation_heap(void)
{
	// permutation
	// 	   "sort, partial sort, nth_element, "
	std::vector<int> v = { 8, 9, 10, 3, 2, 1, 4, 6, 7, 5 };
	TS::print<int>("original:     v -> ", v);

	std::make_heap(v.begin(), v.end());
	TS::print<int>("heapify(max): v -> ", v);

	std::make_heap(v.begin(), v.end(), std::greater<>{});
	TS::print<int>("heapify(min): v -> ", v);

    v.push_back(-1);
	TS::print<int>("add elem:     v -> ", v);

    std::push_heap(v.begin(), v.end(), std::greater<>{});
	TS::print<int>("push_heap:    v -> ", v);

    int top = v.back();
    int btm = v.front();
    std::cout << "top : " << top << std::endl;
    std::cout << "btm : " << btm << std::endl;

    std::make_heap(v.begin(), v.end());
    TS::print<int>("max heap:     v -> ", v);
    std::pop_heap(v.begin(), v.end());
    btm = v.back();
    v.pop_back();
    TS::print<int>("pop heap:     v -> ", v);

	// structure changer
	// mover
	// value modifier
	// algorithm of set
	// query
	// raw memory
}

void TS::algo_permutation_sort(void)
{
    // collection sample
    std::vector<int> v { 13, 4, 19, 3, 16, 17, 14, 11, 10, 11 };
    // sort
    TS::print<int>("original  :   v-> ", v);
    std::sort(v.begin(), v.end());
    TS::print<int>("ascending :   v-> ", v);
    std::sort(v.begin(), v.end(), std::greater<>{});
    TS::print<int>("descending:   v-> ", v);

    // partial sort
    std::partial_sort(v.begin(), v.begin() + 3, v.end());
    TS::print<int>("partial sort: v-> ", v);

    // nth_element
    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    TS::print<int>("nth element:  v-> ", v);
    std::cout << "the medium is " << v[v.size() / 2] << '\n';

    // sort heap
    std::make_heap(v.begin(), v.end());
    TS::print<int>("before sort:  v-> ", v);
    std::sort_heap(v.begin(), v.end());
    TS::print<int>("after sort:   v-> ", v);

    // inplace merge
}

void TS::algo_permutation_partition(void)
{
    // partition
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    TS::print<int>("original  : v-> ", v);
    auto it = std::partition(v.begin(), v.end(), [](int elem){ return elem%2==0; });
    std::copy(v.begin(), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << " * " " ";
    std::copy(it, v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    TS::print<int>("partition : v-> ", v);

    // partition_point
    auto p = std::partition_point(v.begin(), v.end(), [](int elem){ return elem%2==0; });
    std::cout << "partition point : p-> " << *p << std::endl;
}

void TS::algo_permutation_other(void)
{
    // rotate
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    TS::print<int>("original      : v-> ", v);
    std::rotate(v.begin(), v.begin() + 2, v.end());
    TS::print<int>("after rorate  : v-> ", v);

    // shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    TS::print<int>("after shuffle : v-> ", v);

    // prev_permutation
    std::string s = "abc";
    std::sort(s.begin(), s.end(), std::greater<char>{});
    do {
        std::cout << s << ' ';
    } while(std::prev_permutation(s.begin(), s.end()));
    std::cout << "\n";

    // next_permutation
    std::sort(s.begin(), s.end(), std::less<char>{});
    do {
        std::cout << s << ' ';
    } while(std::next_permutation(s.begin(), s.end()));
    std::cout << "\n";

    // reverse
    std::sort(s.begin(), s.end(), std::less<char>());
    std::cout << "before reverse : s-> ";
    std::for_each(s.begin(), s.end(), [](char elem){ std::cout << elem << " "; });
    std::cout << "\n";
    std::reverse(s.begin(), s.end());
    std::cout << "after reverse  : s-> ";
    std::for_each(s.begin(), s.end(), [](char elem){ std::cout << elem << " "; });
    std::cout << "\n";

}

void TS::algo_secret_runes(void)
{
    std::vector<int> v { 13, 4, 19, 3, 16, 17, 14, 11, 10, 11 };
    TS::print<int>("original,         v-> ", v);

    // stable_*
    std::sort(v.begin(), v.end());
    TS::print<int>("std::sort,        v-> ", v);
    v = { 13, 4, 19, 3, 16, 17, 14, 11, 10, 11 };
    std::stable_sort(v.begin(), v.end());
    TS::print<int>("std::stable_sort, v-> ", v);

    v = { 13, 4, 19, 3, 16, 17, 14, 11, 10, 11 };
    auto predict = [](int i)->bool{ return i%2==0; };
    std::partition(v.begin(), v.end(), predict);
    TS::print<int>("std::partition,        v-> ", v);

    v = { 13, 4, 19, 3, 16, 17, 14, 11, 10, 11 };
    std::stable_partition(v.begin(), v.end(), predict);
    TS::print<int>("std::stable_partition, v-> ", v);
    std::cout << "\n";

    // is_*
    v = { 13, 4, 19, 3, 16, 17, 14, 11, 10, 11 };
    TS::print<int>("original, v-> ", v);
    bool rv = std::is_sorted(v.begin(), v.end());
    TS::print<bool>("v is sorted?       -> ", rv);
    rv = std::is_partitioned(v.begin(), v.end(), predict);
    TS::print<bool>("v is partitioned?  -> ", rv);
    rv = std::is_heap(v.begin(), v.end());
    TS::print<bool>("v is heap?         -> ", rv);
    std::cout << "\n";

    // is_*_until
    v = { 1, 2, 3, 4, 16, 17, 14, 11, 10, 11 };
    TS::print<int>("original, v-> ", v);
    auto it = std::is_sorted_until(v.begin(), v.end());
    TS::print<int>("v is sorted until : ", *it);
    it = std::is_heap_until(v.begin(), v.end());
    TS::print<int>("v is sorted until : ", *it);
    // it = std::is_partitioned_until() // in 3rd party library, Boost

    // *_copy


    // *_n


    // *_if
}

void TS::algo_queries(void)
{
    std::vector<int> v(10, 2);
    TS::print<int>("original,         v-> ", v);
    // numeric algorithms
    // count
    int times = std::count(v.begin(), v.end(), 2);
    TS::print<int>("2 appear times  : ", times);

    // accumulate
    int result = std::accumulate(v.begin(), v.end(), 0);
    TS::print<int>("sum of v        : ", result);

    // (transform_)reduce, C++ >= 17
    // result = std::reduce(std::execution::seq, v.begin(), v.end());
    // TS::print<int>(result);

    // partial_sum
    std::cout << "partial_sum     : ";
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // (transform_)inclusive_scan, not work in codeblock and VS?
    //    std::cout << "inclusive_scan  : ";
    //    std::inclusive_scan(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    //    std::cout << "exclusive_scan  : ";
    //    // (transform_)exclusive scan
    //    std::exclusive_scan(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    //    std::cout << std::endl;

    // inner_product
    v = { 2, 2, 2 };
    std::vector<int> w = { 3, 3, 3 };
    result = std::inner_product(v.begin(), v.end(), w.begin(), 0);
    TS::print<int>("inner_product   : ", result);
    std::cout << std::endl;

    // adjacent_difference
    v = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    TS::print<int>("original,            v-> ", v);
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    TS::print<int>("adjacent_differences v-> ", v);

    // sample
    std::string in = "zhangliang and tangsai", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out), 5, std::mt19937{std::random_device{}()});
    TS::print<std::string>("five random letters : ", out);
    std::cout << std::endl;
}
