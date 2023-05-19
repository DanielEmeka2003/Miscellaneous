#include "functions.h"

namespace text
{
    std::string_view getInputs(std::string_view InputMessage)
    {
        std::cout << InputMessage;
        static std::string input{};
        std::getline(std::cin >> std::ws, input); 
        return input; 
    }

    char getChar(std::string_view InputMessage)
    {
        std::cout << InputMessage;
        char ch{};
        std::cin >> ch;
        numeric::ignoreInputBuffer();
        return ch;
    }


} // namespace text
