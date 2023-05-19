#if !defined(FUNCTIONS_H)
#define FUNCTIONS_H

#pragma once

#include "includes.h"
#include "constants.h"

using namespace std::literals; 
using namespace std::numbers; 

namespace numeric 
{
    void ignoreInputBuffer(); 
} // namespace input 

namespace numeric::numbers
{
    bool NumericInputValidation(std::string_view errorMessage = "Try again!"); 
    double getInputs_d();  
    double getInputs_s(std::string_view InputMessage = "Enter a number: ");  
} // namespace numeric::numbers
namespace practice
{
    char getArithmetic();
    void arithmeticCalculations(double x, char ch, double y);
    void calculateHeightOfTheBall(double height); 
    bool isEven(int integer); 
    bool isPrime(int number);
} // namespace practice

namespace text
{
    std::string_view getInputs(std::string_view InputMessage = "Enter anything you want: ");
    char getChar(std::string_view InputMessage = "Enter anything character you want: ");  
} // namespace text


#endif // FUNCTIONS_H
