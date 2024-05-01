#include <iostream>
#include <stack>
#include <string>

using namespace std;

class ExpressionConverter {
private:
    string infix;
    string postfix;

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    void getInfix() {
        cout << "Enter the infix expression: ";
        getline(cin, infix);
    }

    void showInfix() {
        cout << "Infix Expression: " << infix << endl;
    }

    void showPostfix() {
        cout << "Postfix Expression: " << postfix << endl;
    }

    void convertToPostfix() {
        stack<char> operators;
        postfix = "";

        for (size_t i = 0; i < infix.size(); ++i) {
            char c = infix[i];
            if (isalnum(c)) {
                postfix += c;
            } else if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();
            } else { 
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty()) {
            postfix += operators.top();
            operators.pop();
        }
    }
};

int main() {
    ExpressionConverter converter;

    string expressions[] = {
        "A + B - C",
        "(A + B ) * C",
        "(A + B) * (C - D)",
        "A + ((B + C) * (E - F) - G) / (H - I)",
        "A + B * (C + D) - E / F * G + H"
    };

    for (int i = 0; i < sizeof(expressions) / sizeof(expressions[0]); ++i) {
        converter.getInfix();
        converter.showInfix();
        converter.convertToPostfix();
        converter.showPostfix();
        cout << endl;
    }

    return 0;
}

