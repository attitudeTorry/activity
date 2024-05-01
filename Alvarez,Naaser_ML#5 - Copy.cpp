#include <iostream>
#include <stack>
#include <string>
#include <cctype> 

using namespace std;

class InfixToPostfix {
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
            if (isspace(c)) {
                continue; 
            } else if (isOperand(c)) {
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

private:
    string infix;
    string postfix;

    bool isOperand(char c) {
        return isalpha(c) || isdigit(c);
    }

    int precedence(char op) {
       
        return 0; 
    }
}; 

int main() {
    char choice;
    do {
        InfixToPostfix converter;
        converter.getInfix();
        converter.convertToPostfix();
        converter.showInfix();
        converter.showPostfix();
        
        cout << "Do you want to enter another infix expression? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}


