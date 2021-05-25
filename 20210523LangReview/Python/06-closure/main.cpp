/*
a simple module demonstrates closure mechnsim in C++

@ZL, 20210525

[ expriment result ]
- C++ does not prevent this behavior (access local variable)
! but the behavior is not expected like Swift or JavaScript

*/

#include <iostream>
#include <functional>

namespace TS
{
    std::function<int (void)> accessLocalVariableInFunction(int n)
    {
        int total = 0;
        auto f = [&total, n]()->int{
            total += n;
            return total;
        };
        return f;
    }
}

int main() {

    std::function<int (void)> closure = TS::accessLocalVariableInFunction(1);

    std::cout << "1st, result : " << closure() << std::endl;
    std::cout << "2nd, result : " << closure() << std::endl;
    std::cout << "3rd, result : " << closure() << std::endl;

    return 0;
}
