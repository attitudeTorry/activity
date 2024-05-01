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

    void processOperator(char op, stack<char>& operatorStack) {
        while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(op)) {
            postfix += operatorStack.top();
            postfix += " ";
            operatorStack.pop();
        }
        operatorStack.push(op);
    }

    void processClosingParenthesis(stack<char>& operatorStack) {
        while (!operatorStack.empty() && operatorStack.top() != '(') {
            postfix += operatorStack.top();
            postfix += " ";
            operatorStack.pop();
        }
        operatorStack.pop(); 
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

    for (string::iterator it = infix.begin(); it != infix.end(); ++it) {
        char c = *it;
        if (isalpha(c)) {
            postfix += c;
            postfix += " ";
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            processClosingParenthesis(operatorStack);
        } else if (isOperator(c)) {
            processOperator(c, operatorStack);
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

