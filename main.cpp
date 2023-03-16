#include <iostream>
#include "myfunctions.hpp"

int main()
{
    print(); 
    int fact{factorial(4)};
    std::cout << fact;
   [[maybe_unused]] int under{};
    return 0;
}