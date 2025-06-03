#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    std::string code;
    std::cout << "Enter your C++ code:\n";
    while (!std::cin.eof())
    {
        std::string line;
        std::getline(std::cin, line);
        code += line + "\n";
    }
    std::regex declarationRegex(R"(\s+(\w+)\s+(\w+)\s*\([^\)]*\);)");
    std::regex definitionRegex(R"(\s+\w+\s+(\w+)\s*\([^\)]*\)\s*\{)");

    std::smatch match;
    std::string::const_iterator searchStart(code.cbegin());

    std::cout << "Function Declarations:" << std::endl;
    while (std::regex_search(searchStart, code.cend(), match, declarationRegex))
    {
        std::cout << match[1] << " " << match[2] << std::endl;
        searchStart = match.suffix().first;
    }

    searchStart = code.cbegin();
    std::cout << "\nFunction Definitions:" << std::endl;
    while (std::regex_search(searchStart, code.cend(), match, definitionRegex))
    {
        std::cout << match[1] << " " << match[2] << std::endl;
        searchStart = match.suffix().first;
    }

    return 0;
}
