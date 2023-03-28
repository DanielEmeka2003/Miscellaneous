#include "functions.hpp"


namespace input
{
    void ignoreInputBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
    }

} // namespace input

namespace input::numbers
{

    bool NumericInputValidation(std::string_view errorMessage)
    {
        bool flag{false};
        if (std::cin.fail())
        {
            std::cin.clear();
            ignoreInputBuffer();
            std::cerr << errorMessage;
            flag = true;
        }
        return flag;
    }
    
    double getInputs(std::string_view FirstInputMessage, std::string_view SecondInputMessage)
    {
        double x{};
        static int count{};
        ++count;
        
        if (count % 2 == 0)
        {   
            while (true)
            {
                std::cout << SecondInputMessage;
                std::cin >> x;
                ignoreInputBuffer();
                if (NumericInputValidation())
                std::cout << '\n';
                else
                {
                    std::cout << '\n';
                    return x;
                }
            }
        }
        
        else
        {
            while (true)
            {
                std::cout << FirstInputMessage;
                std::cin >> x;
                ignoreInputBuffer();
                if (NumericInputValidation())
                std::cout << '\n';
                else
                {
                    std::cout << '\n';
                    return x;
                }
            } 
        }
    }
    
} // namespace input::numbers
