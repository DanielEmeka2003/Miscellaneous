#include "learning.hpp"


int main( [[maybe_unused]]int argc,  [[maybe_unused]]char *argv[])
{
    gGameIsRunning = initialization();

    setup();
    while (gGameIsRunning)
    {
        processInput();    
        update();   
        render();            
    }
    

    cleanup();    
    return EXIT_SUCCESS;
}
