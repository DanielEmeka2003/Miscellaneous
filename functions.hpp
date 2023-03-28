#ifndef FUNCTIONS_HPP
#define FUNCTONS_HPP

#include "includes.hpp"
#include "constants.hpp"
#include "Random.hpp"

using namespace std::literals;
using namespace std::numbers; 

namespace input 
{
    void ignoreInputBuffer(); 
} // namespace input 


namespace input::numbers
{
    bool NumericInputValidation(std::string_view errorMessage = "Try again!");
    double getInputs(std::string_view FirstInputMessage = "Enter a number: ", std::string_view SecondInputMessage = "Enter another: ");  
} // namespace numbers

namespace practice
{
    char getArithmetic();
    void arithmeticCalculations(double x, char ch, double y);
    void calculateHeightOfTheBall(double height); 
    bool isEven(int integer); 
} // namespace practice


#endif