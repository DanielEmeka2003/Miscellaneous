#include "functions.h"


namespace numeric
{
    void ignoreInputBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
    }

} // namespace input

namespace numeric::numbers
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
    
    double getInputs_s(std::string_view InputMessage)
    {
        double x{};
        
        while (true)
        {
            std::cout << InputMessage;
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
    
    double getInputs_d()
    {
        std::string_view FirstInputMessage {"Enter a number: "}; 
        std::string_view SecondInputMessage {"Enter another: "};
        
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

} // namespace numeric::numbers
