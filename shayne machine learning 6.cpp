#include <iostream>
#include <stack>
#include <string>

using namespace std;

class InfixToPostfixConverter {
private:
    string infixExpression;
    string postfixExpression;

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

public:
    void getInfix(const string& infix) {
        infixExpression = infix;
    }

    void showInfix() {
        cout << "Infix Expression: " << infixExpression << endl;
    }

    void showPostfix() {
        cout << "Postfix Expression: " << postfixExpression << endl;
    }

    void convertToPostfix() {
        stack<char> s;
        postfixExpression = "";

        for (int i = 0; i < infixExpression.length(); ++i) {
            char c = infixExpression[i];
            if (isalnum(c)) {
                postfixExpression += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfixExpression += s.top();
                    s.pop();
                }
                s.pop(); // Discard '('
            } else { // Operator
                while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                    postfixExpression += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while (!s.empty()) {
            postfixExpression += s.top();
            s.pop();
        }
    }
};

int main() {
    InfixToPostfixConverter converter;

    // Test expressions
    string expressions[] = {
        "A + B - C",
        "(A + B) * C",
        "(A + B) * (C - D)",
        "A + ((B + C) * (E - F) - G) / (H - I)",
        "A + B * (C + D) - E / F * G + H"
    };

    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < numExpressions; ++i) {
        converter.getInfix(expressions[i]);
        converter.showInfix();
        converter.convertToPostfix();
        converter.showPostfix();
        cout << endl;
    }

    return 0;
}

