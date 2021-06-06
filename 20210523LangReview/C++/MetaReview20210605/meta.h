#ifndef META_H_INCLUDED
#define META_H_INCLUDED

/*
c++, algorithm review

@ZL, 20210605
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <string>
#include <string_view>
#include <random>

namespace TS
{
    template<class T>
    void print(const std::string& comment, std::vector<T> v);

    template<class T>
    void print(const std::string& comment, std::set<T> s);

    template<typename U>
    void print(const std::string& comment, U result);

	void algo_permutation_heap(void);
	void algo_permutation_sort(void);
	void algo_permutation_partition(void);
	void algo_permutation_other(void);
	void algo_secret_runes(void);

	void algo_queries(void);
	void algo_query_property(void);
	void algo_search_value(void);

	void algo_of_set(void);
}

#endif // META_H_INCLUDED
