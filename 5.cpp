#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() == 0 || s.size() == 1) return s;
        std::string res;
        int maxlen = 0;
        for (int i = 0; i < s.size() - maxlen; i++) {
            for (int j = s.size() - 1; j >= i + maxlen; j--) {
                if (s[j] != s[i]) continue;
                std::string str = s.substr(i, j - i + 1);
                if (isPalindrome(str) && str.size() > maxlen) {
                    maxlen = str.size();
                    res = str;
                }
            }
        }
        return res;
    }

    bool isPalindrome(std::string s) {
        if (s.size() == 0 || s.size() == 1) return true;
        int i(0), j(s.size() - 1);
        while (s[i] == s[j] && i < j) i++, j--;
        return i >= j;
    }
};

int main() {
    Solution solution;
    std::string input = "babad"; // Replace with your input string

    std::string result = solution.longestPalindrome(input);

    std::cout << "Longest palindromic substring: " << result << std::endl;

    return 0;
}
