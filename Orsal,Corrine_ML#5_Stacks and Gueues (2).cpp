#include <iostream>
#include <stack>
#include <string>

using namespace std;

class ExpressionConverter {
private:
    string infix;
    string postfix;

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int getPrecedence(char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0; 
    }

    bool isOperand(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool isParenthesis(char c) {
        return c == '(' || c == ')';
    }

public:
    void getInfix(string expr) {
        infix = expr;
    }

    void showInfix() {
        cout << "Infix Expression: " << infix << endl;
    }

    void showPostfix() {
        cout << "Postfix Expression: " << postfix << endl;
    }

    void convertToPostfix() {
        stack<char> operatorStack;
        
        for (size_t i = 0; i < infix.size(); ++i) {
            char c = infix[i];
            if (isOperand(c)) {
                postfix += c;
                postfix += " ";
            } else if (isOperator(c)) {
                while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                    postfix += operatorStack.top();
                    postfix += " ";
                    operatorStack.pop();
                }
                operatorStack.push(c);
            } else if (c == '(') {
                operatorStack.push(c);
            } else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfix += operatorStack.top();
                    postfix += " ";
                    operatorStack.pop();
                }
                if (!operatorStack.empty() && operatorStack.top() == '(')
                    operatorStack.pop(); // Remove '('
            }
        }

        while (!operatorStack.empty()) {
            postfix += operatorStack.top();
            postfix += " ";
            operatorStack.pop();
        }
    }
};

int main() {
    ExpressionConverter converter;

    string expressions[] = {"A + B - C", "(A + B) * C", "(A + B) * (C - D)", "A + ((B + C) * (E - F) - G) / (H - I)", "A + B * (C + D) - E / F * G + H"};
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

