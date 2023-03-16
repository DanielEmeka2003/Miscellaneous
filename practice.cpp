#include <iostream> // for cout, cin, endl and cerr
#include <cstdlib> // adapted from C, contains various Marcos, functions and etc..
#include <numbers> // for mathematical constexprs i.e std::numbers::pi... 
#include <iomanip> // for input and output manipulations
using namespace std::numbers;

int main()
{
    std::div_t x{div(1234, 10)};
    std::cout << x.quot << ' ' << x.rem;   

    return 0;
}