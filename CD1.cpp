#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;
string removeDuplicates(const string& input)
{
    string result;
    unordered_set<char> seen;
    for (char c : input)
    {
       if (seen.find(c) == seen.end())
        {
            result=result+c;
            seen.insert(c);
        }
    }
    return result;
}
string removeSpaces(const string& input)
{
    string result;
    for (char c : input)
    {
        if (!isspace(c))
        {
            result=result+c;
        }
    }
  return result;
}
int main()
{
   srand(static_cast<unsigned int>(time(nullptr)));
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    string withoutDuplicates = removeDuplicates(input);
    cout << "String without repeated characters: " << withoutDuplicates << endl;
    string withoutSpaces = removeSpaces(input);
    cout << "String without spaces: " << withoutSpaces << endl;
    cout << "Total string value: " << input.length() << endl;
    cout << "Printing the string with a random pattern:" << endl;
    int printedChars = 0;
    while (printedChars < input.length())
    {
        int randomIndex = rand() % input.length();
        cout << input[randomIndex];
        printedChars++;
    }
    cout << endl;
 return 0;
}
