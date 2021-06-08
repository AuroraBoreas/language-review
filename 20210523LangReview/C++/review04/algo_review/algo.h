#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <chrono>
#include <thread>
#include <numeric>
#include <random>
#include <string>

#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <iterator>
#include <functional>
#include <algorithm>

namespace TS
{
    template<class T>
    void print(const std::string&, const std::vector<T>&);

    auto mprint = [](const std::string& c, auto const& v) -> void {
        std::cout << c;
        for(const auto& e : v){ std::cout << e << " "; }
        std::cout << std::endl;
    };

    template<typename Container>
    bool in_quote(const Container& cont, const std::string& s)
    {
        return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
    }

    void func(const int& i);

    void algo_permutation_heap(void);

    void algo_permutation_sort(void);

    void algo_structure_changer(void);

    void algo_movers(void);

    void algo_value_modifiers(void);

    void algo_set(void);

    void algo_query_property(void);

    void algo_query_value(void);

    void algo_secret_rune(void);

    void algo_lone_island(void);


}
