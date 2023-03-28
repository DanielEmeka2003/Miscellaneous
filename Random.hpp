#ifndef RANDOM_H
#define RAMDOM_H

#include "includes.hpp"

namespace random
{
    //std::mt19937 rNumbers32{(unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()};
    //std::mt19937 rNumbers32{std::random_device{}()};
    //std::random_device rd;
    //std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    //std::mt19937 rNumbers32{ss};
    //std::uniform_int_distribution die6{1, 6}; 
    inline std::mt19937 init()
    {
       std::random_device rd; 
       std::seed_seq ss{(unsigned int)std::chrono::steady_clock::now().time_since_epoch().count(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
       return std::mt19937{ss};
    }
    
    std::mt19937 mt{init()};

    inline int get(int min, int max)
    {
        std::uniform_int_distribution range{min, max}; 
        return range(mt);
    }


} // namespace random











#endif