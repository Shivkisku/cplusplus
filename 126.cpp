#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stk, op;
        int res = 0, sign = 1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = c - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + s[i + 1] - '0';
                    i++;
                }
                res += num * sign;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                stk.push(res);
                op.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res = res * op.top();
                op.pop();
                res += stk.top();
                stk.pop();
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::string expression = "(1+(4+5+2)-3)+(6+8)"; // Replace this with your input expression

    int result = solution.calculate(expression);

    std::cout << "Result of the expression: " << result << std::endl;

    return 0;
}
