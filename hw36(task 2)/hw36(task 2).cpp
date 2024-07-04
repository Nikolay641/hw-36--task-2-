#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::stack;
using std::string;

void fromPoland(string expression) {
    stack<int> s;
    for (int i = 0; i < expression.size(); i++) {
        if(isdigit(expression[i])){
            int start = i;
            while (i < expression.size() && (isdigit(expression[i]))) {
                i++;
            }
            s.push(std::stoi(expression.substr(start, i - start)));
        }
        else if (expression[i] == ' ') {
            continue;
        }
        else {
            if (s.size() < 2) {
                return;
            }
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            if (expression[i] == '+') {
                s.push(operand1 + operand2);
            }
            else if (expression[i] == '-') {
                s.push(operand1 - operand2);
            }
            else if (expression[i] == '*') {
                s.push(operand1 * operand2);
            }
            else if (expression[i] == '/') {
                if (operand2 == 0) {
                    return;
                }
                s.push(operand1 / operand2);
            }
            else {
                return;
            }
        }
    }
    cout << "Result: " << s.top() << endl;
}

int main()
{
    fromPoland("1 2 +");
}