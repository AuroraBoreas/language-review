#include "ctor.h"
#include <vector>

int main()
{
    TS::Base b1 = TS::Base();
    TS::Base b2 = TS::Base(1);

    TS::Base b3;
    b3 = b2;

    std::vector<TS::Base> v;
    v.emplace_back(TS::Base());

    return 0;
}
