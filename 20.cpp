#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty() && (c == ')' || c == ']' || c == '}')) return false;
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                char left = stk.top();
                if ((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{')) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution solution;
    string input = "()[]{}";  // Example input

    // Check if the string is valid
    bool isValid = solution.isValid(input);

    // Print the result
    if (isValid) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
