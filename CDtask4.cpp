#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ofstream inputFile("input.txt");
    inputFile<<"//#include<iostream>\n";
    inputFile<<"//using namespace std;\n";
    inputFile<<"int main()\n";
    inputFile<<"{\n";
    inputFile<<"int a=5,b=3;\n";
    inputFile<<"int sum=a+b;\n";
    inputFile<<"cout<<\"sum:\"<<sum;\n";
    inputFile<<"return 0;\n";
    inputFile<<"}\n";
    inputFile.close();

    ifstream file("input.txt");
    string line;
    vector<string>comments,keywords,identifiers,literals;
    set<string> cppKeywords =
    {
        "and", "and_eq", "auto", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "const",
        "continue",  "default", "delete", "do", "double", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "if", "inline", "int", "long",  "namespace", "new", "not", "nullptr",
        "operator", "or", "private", "protected", "public", "register","return", "short", "signed", "sizeof", "static",
        "switch", "template", "this", "throw", "true","try", "typedef", "typeid", "typename", "union",
        "unsigned", "using", "virtual", "void","volatile", "while"
    };

    while (getline(file, line))
        {
        if (line.find("//") != string::npos)
          {
            comments.push_back(line);
          }
        else
          {
            stringstream ss(line);
            string word;
            while (ss>>word)
            {
                if (isalpha(word[0]))
                {
                    if (cppKeywords.count(word)>0)
                    {
                      keywords.push_back(word);
                    }
                    else
                    {
                      identifiers.push_back(word);
                    }
                }
                else if (isdigit(word[0]))
                {
                literals.push_back(word);
                }
            }
        }
    }
    for (const string& comment : comments)
    {
     cout << "Comment\t\t" << comment << endl;
    }
    for (const string& keyword : keywords)
    {
     cout << "Keyword\t\t" << keyword << endl;
    }
    for (const string& identifier : identifiers)
    {
     cout << "Identifier\t" << identifier << endl;
    }
    for (const string& literal : literals)
    {
     cout << "Literal\t\t" << literal << endl;
    }
    file.close();
    return 0;
}
