#pragma once

#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool balancedCheck(const string& expression);
int precedence(char c);
string infix_to_postfix(const string& expression);
