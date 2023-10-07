#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        std::string r = s;
        std::reverse(r.begin(), r.end());
        int i = 0, j = s.size();
        while (r.substr(i, j) != s.substr(0, j)) i++, j--;
        return r.substr(0, i) + s;
    }
};

int main() {
    Solution solution;
    std::string s = "abcd"; // Replace this with your input string

    std::string shortestPal = solution.shortestPalindrome(s);

    std::cout << "Shortest Palindrome: " << shortestPal << std::endl;

    return 0;
}
