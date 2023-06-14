#include "gfunctions.h"
#include "Random.h"
#include "customTypes.h"
#include "miscellany.h"
#include "squareGame.h"
#include "fPuzzleGame.h"
#include "guessGame.h"
#include "logicGame.h"

class A
{
    public:
    int a{34}, c{567};
    
    A() = default;
    A(int b): a{b} {}
    A(const A& b){ a = b.a; };
    A(A&& b): a{std::move(b.a)} {}
};

int main( [[maybe_unused]]int argc, [[maybe_unused]]char* argv[] ) 
{ 
    namespace fs = std::filesystem;
    
    
    int x{};
    int y{ x++ };
    std::cout << x << ' ' << y << '\n';

    return EXIT_SUCCESS;
}

