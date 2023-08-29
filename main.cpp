#include <iostream>
//#include <fstream>

#include <cstdlib> 
#include <cstdint>
#include <typeinfo>
#include <type_traits>
#include <cstddef>
#include <iomanip>
#include <utility>

#include <string>
#include <string_view>

#include <cassert>
#include <bitset> 
#include <format>

#include <chrono>
#include <thread>

#include <array>
#include <vector>

#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

#include <map>

#include "myfunctions1.h"
// #include "card.h"
// #include "player.h"
// #include "dealer.h"
#include "timer.h"

#define TEST_1

using namespace std::string_literals;
using namespace std::chrono;

void sleepMainThread(nanoseconds time_in_nanosecs_to_sleep)
{
    //#include <thread> needed for this
    std::this_thread::sleep_for(time_in_nanosecs_to_sleep);
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{ 
    //std::system("chcp 65001");
    Myfcn::Timer timer{};

   #ifdef TEST_1
    char choice{};
    while (choice != 'q')
    {
        std::cout << "Enter choice[s-start, r-restart, p-pause, u-unpause, z-zerotime, q-quit]: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'q': break;
        case 's': timer.start(); break;
        case 'r': timer.restart(); break;
        case 'p': timer.pause(); break;
        case 'u': timer.unpause(); break;
        case 'z': timer.zeroTime(); break;
        default: std::cout << "Not valid!\n"; break;
        }

        std::cout << '\n';

        auto timeR{timer.getTime()};
        std::cout << "nanoseconds:\t" << timeR << '\n';
        std::cout << "miroseconds:\t" << duration_cast<microseconds>(timeR) << '\n';
        std::cout << "milliseconds:\t" << duration_cast<milliseconds>(timeR) << '\n';
        std::cout << "seconds:\t" << duration_cast<seconds>(timeR) << '\n';

        std::cout << '\n';
    }
   #endif

   #ifdef TEST_2
    timer.start();
    //some bogus time in nanoseconds to sleep for.
    sleepMainThread(5'121'131'140ns);
    timer.pause();

    auto elapsed{timer.getTime()};

    std::cout << "nanoseconds:\t" << elapsed << '\n';
    std::cout << "miroseconds:\t" << duration_cast<microseconds>(elapsed) << '\n';
    std::cout << "milliseconds:\t" << duration_cast<milliseconds>(elapsed) << '\n';
    std::cout << "seconds:\t" << duration_cast<seconds>(elapsed) << '\n';
   #endif

    
    return EXIT_SUCCESS;
}  











