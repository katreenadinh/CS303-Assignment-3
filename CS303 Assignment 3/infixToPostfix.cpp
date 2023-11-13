#include "infixToPostfix.h"

// checks if symbols used are balanced and valid
bool balancedCheck(const string& expression) {
    stack<char> stack;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return false;
            }
            else {
                char top = stack.top();
                if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    return stack.empty();
}

// returns precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    return 0; // For parentheses
}

// converts infix expression to postfix expression
string infix_to_postfix(const string& expression) {
    stack<char> stack;
    string postfix;
    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            while (!stack.empty() && stack.top() != '(' && stack.top() != '{' && stack.top() != '[') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else {
            while (!stack.empty() && stack.top() != '(' && stack.top() != '{' && stack.top() != '[' && precedence(c) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}