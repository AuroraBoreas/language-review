#include <iostream>
#include <bitset>
#include <numeric>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>

#include <iterator>

#include <random>

int main()
{
    std::cout << std::bitset<std::numeric_limits<unsigned long>::digits>(267) << std::endl;
    std::vector<int> v(2, 3);
    for(auto& e : v) { std::cout << e << " "; }
    std::cout << std::endl;

    std::vector<int> w(2, 4);
    std::merge(v.begin(), v.end(), w.begin(), w.end(), std::ostream_iterator<int>(std::cout, " "));

    std::list<int> u;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::cout << "\nstd::sample, -> ";
    std::sample(v.begin(), v.end(), std::inserter(u, u.begin()), 3, mt);
    std::copy(u.begin(), u.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
