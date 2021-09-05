#include <functional>
#include <iostream>

std::function<int (void)> getInt(void);

int main()
{
    std::function<int (void)> g = getInt();
    for(int i=0; i<5; ++i)
        std::cout << g() << std::endl;

    std::cin.get();
    return 0;
}

std::function<int (void)> getInt(void)
{
    static int i(0);
    return [&](){ return ++i; };
}
