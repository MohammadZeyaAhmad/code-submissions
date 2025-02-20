/* You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isOperator(const string& ch) {
        return ch == "+" || ch == "-" || ch == "*" || ch == "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                if (st.size() < 2) {
                    throw invalid_argument("Invalid RPN expression: not enough operands.");
                }

                int second = st.top(); st.pop();
                int first = st.top(); st.pop();

                // Using ternary operator for operations
                int result = token == "+" ? first + second :
                             token == "-" ? first - second :
                             token == "*" ? first * second :
                                            first / second; // Division

                st.push(result);
            } else {
                try {
                    st.push(stoi(token));
                } catch (const exception& e) {
                    throw invalid_argument("Invalid token: " + token);
                }
            }
        }

        if (st.size() != 1) {
            throw invalid_argument("Invalid RPN expression: stack does not contain exactly one result.");
        }

        return st.top();
    }
};



  
