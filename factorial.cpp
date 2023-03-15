#include <iostream>
#include "myfunctions.hpp"

int factorial(int n)
{
    if (n != 1)
    {
        int y{factorial(n - 1)};
        return n * y;
    }
    
    else
    return 1;
}