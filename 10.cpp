#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (p.empty()) return s.empty();
        if (s.empty()) return p.empty() || (p[1] == '*' ? isMatch(s, p.substr(2)) : false);
        if (p[0] != '.' && s[0] != p[0]) return p[1] == '*' ? isMatch(s, p.substr(2)) : false;
        if (p[1] == '*') return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
        return isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution solution;
    std::string s = "aa";
    std::string p = "a*"; // Replace with your input strings

    bool result = solution.isMatch(s, p);

    std::cout << "Does s match p? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
