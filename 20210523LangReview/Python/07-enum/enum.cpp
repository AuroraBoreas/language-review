#include <iostream>

enum class Color {
    red,
    green,
    blue
};

int main()
{
    Color r = Color::red;
    switch(r)
    {
        case Color::red  : std::cout << "red\n";   break;
        case Color::green: std::cout << "green\n"; break;
        case Color::blue : std::cout << "blue\n";  break;
    }

    int n = static_cast<int>(r);
    std::cout << n << '\n';
    
    return 0;
}