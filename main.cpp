#include <iostream>
#include "myfunctions.hpp"

int main()
{
    print();
    int64_t fact{factorial(16)};
    std::cout << fact;
    return 0;
}