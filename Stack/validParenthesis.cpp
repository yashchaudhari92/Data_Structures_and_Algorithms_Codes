// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([])"
// Output: true

// Example 5:
// Input: s = "([)]"
// Output: false


// Code :- 


#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:

    bool isValid(string str) {

        stack<char> s;

        for(int i = 0; i < str.size(); i++) {

            char ch = str[i];

            // Opening brackets
            if(ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            }

            else {

                // Check if stack is empty
                if(s.empty()) {
                    return false;
                }

                // Get top element
                char top = s.top();

                // Matching conditions
                if(
                    (top == '(' && ch == ')') ||
                    (top == '[' && ch == ']') ||
                    (top == '{' && ch == '}')
                ) {
                    s.pop();
                }

                else {
                    return false;
                }
            }
        }

        // Stack must be empty
        return s.empty();
    }
};

int main() {

    Solution obj;

    string str;

    cout << "Enter parentheses string: ";
    cin >> str;

    if(obj.isValid(str)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}
