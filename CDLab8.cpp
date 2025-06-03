#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char input[100];
    std::string startCondition = "";


    while (true)
        {
        std::cout << "Enter input (Type 'quit' to exit): ";
        std::cin >> input;

        if (std::string(input) == "quit")
        {
            break;
        } else if (std::string(input) == "#")
        {
            startCondition = "RULE1";
        } else if (std::string(input) == "##")
        {
            startCondition = "RULE2";
        } else {
            if (startCondition == "RULE1")
            {
                // Apply RULE1
                bool valid = true;
                for (char c : input)
                {
                    if (!(std::isdigit(c) || std::islower(c)))
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    std::cout << "RULE1: Valid input." << std::endl;
                } else
                {
                    std::cout << "RULE1: Invalid input." << std::endl;
                }
            }
        else if (startCondition == "RULE2")
            {
                // Apply RULE2
                bool valid = true;
                for (char c : input) {

                    if (!(std::isdigit(c) || std::islower(c) || std::isupper(c)))
                    {

                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    std::cout << "RULE2: Valid input." << std::endl;
                } else {
                    std::cout << "RULE2: Invalid input." << std::endl;
                }
            }
            else
            {
                std::cout << "No active rule. Enter '#' or '##' to activate a rule." << std::endl;
            }
        }
    }

    return 0;
}


