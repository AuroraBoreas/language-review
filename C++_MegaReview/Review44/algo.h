#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <chrono>
#include <thread>
#include <random>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace TS
{
    void inline newline(void)
    {
        std::cout << std::endl;
    }

    void inline otopic(const std::string& s)
    {
        std::cout << "\n=== " << s << " ===\n";
    }

    const int w(35);
    char const b{' '};

    inline void oformat(const std::string& s)
    {
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << s;
    }

    auto print = [](const std::string& s, auto const& v){
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << s;
        for(auto& e : v) std::cout << e << TS::b;
        TS::newline();
    };

    void inline func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << "thread " << i << " ended\n";
    }

    class IsEven
    {
    public:
        bool operator()(const int& e)
        {
            return e%2==0;
        }
    }; // class IsEven

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_property(void);
    void algo_query_value(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void aglo_lone_island(void);
}


#endif // ALGO_H_INCLUDED
