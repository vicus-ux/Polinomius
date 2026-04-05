#include <iostream>
#include <string>

#include "mainer.h"

int main()
{
    Calculator Polsha;
    SortedMap<std::string, Polinom> peremSortedMap;
    BlackRedTree<std::string, Polinom> peremBlackRedTree;
    Hash<std::string, Polinom> peremHash;
    int whatToUse = 1;
    while (true)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
        //
        if (input.empty())
        {
            continue;
        }
        //
        try
        {
            Polinom result;
            switch (whatToUse)
            {
            case 1:
                result = Polsha.ArithmeticCalculator(input, peremSortedMap);
                break;
            case 2:
                result = Polsha.ArithmeticCalculator(input, peremBlackRedTree);
                break;
            case 3:
                result = Polsha.ArithmeticCalculator(input, peremHash);
                break;
            default:
                break;
            }
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::exception& excep)
        {
            std::cout << "Error: " << excep.what() << std::endl;
        }
    }
    return 0;
}