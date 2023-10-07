#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string str) {
        if (str.size() == 0) return 0;
        int cur = 0;
        while (cur < str.size() && str[cur] == ' ') cur++;
        if (cur == str.size() || (!isdigit(str[cur]) && str[cur] != '+' && str[cur] != '-')) return 0;
        int end = cur + 1;
        while (isdigit(str[end])) end++;
        std::string s = str.substr(cur, end - cur);
        int num = 0;
        int base = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '+' || s[i] == '-') break;
            int add = base * (s[i] - '0');
            if (INT_MAX - num < add || (s.size() - i > 10 && s[i] != '0'))
                return s[0] == '-' ? INT_MIN : INT_MAX;
            num += add;
            base *= 10;
        }
        if (s[0] == '-') num = -num;
        return num;
    }
};

int main() {
    Solution solution;
    std::string input = "42"; // Replace with your input string

    int result = solution.myAtoi(input);

    std::cout << "Converted integer: " << result << std::endl;

    return 0;
}
