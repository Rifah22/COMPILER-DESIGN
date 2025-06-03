#include<iostream>
#include<stack>
#include<cctype>
#include<vector>

bool isProperVariableDeclaration(const std::string& variable)
{
   if (!isalpha(variable[0]) && variable[0] != '_')
     {
        return false;
     }
   for (char c : variable)
    {
      if (!isalnum(c) && c != '_')
      {
        return false;
      }
    }
   return true;
}

bool isProperlyParenthesized(const std::string& expression)
{
    std::stack<char> parentheses;
    for (char c : expression)
    {
       if (c == '(')
        {
          parentheses.push(c);
        }
        else if (c == ')')
        {
            if (parentheses.empty())
                {
                  return false;
                }
            parentheses.pop();
        }
    }
   return parentheses.empty();
}
int main()
{
    std::vector<std::string> variables = {"R", "_S", "78ab", "Compiler_Design", "1 *"};
    std::cout << "Proper variable declaration analysis:\n";
    for (const auto& variable : variables)
    {
        std::cout << "Variable '" << variable << "' is properly declared: "
        << (isProperVariableDeclaration(variable) ? "true" : "false") << "\n";
    }
    std::vector<std::string> expressions = {"(7-5) * (60+45)", "((2+14) * 3", "20 + (5 / 2))", ")","(", "c+d"};
    std::cout << "\nProperly parenthesized expression analysis:\n";
    for (const auto& expression : expressions)
    {
        std::cout << "Expression '" << expression << "' is properly parenthesized: "
                  << (isProperlyParenthesized(expression) ? "true" : "false") << "\n";
    }
  return 0;
}
