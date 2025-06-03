#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void generateThreeAddressCode(const string& expression) {
    istringstream iss(expression);
    vector<string> tokens;

    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    stack<string> operands;
    stack<char> operators;
    int tempCount = 1;

    for (const string& token : tokens) {
        if (isOperator(token[0])) {

            while (!operators.empty() && operators.top() >= token[0]) {

                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                string result = "t" + to_string(tempCount++) + "=" + op1 + operators.top() + op2;
                cout << result << endl;

                operands.push("t" + to_string(tempCount - 1));
                operators.pop();
            }

            operators.push(token[0]);
        } else {

            operands.push(token);
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        string result = "t" + to_string(tempCount++) + "=" + op1 + operators.top() + op2;
        cout << result << endl;

        operands.push("t" + to_string(tempCount - 1));
        operators.pop();
    }

    cout << "out=" << operands.top() << endl;
}

int main() {
    string expression;
    cout << "Please type the expression: ";
    getline(cin, expression);

    generateThreeAddressCode(expression);

    return 0;
}
