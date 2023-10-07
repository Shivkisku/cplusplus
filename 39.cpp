#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (s.empty()) {
            if (p[0] == '*') return isMatch(s, p.substr(1));
            else return false;
        }
        if (p[0] != '?' && p[0] != '*' && p[0] != s[0]) return false;
        if (p[0] == '*') {
            for (int i = 0; i <= s.size(); i++) {
                if (isMatch(s.substr(i), p.substr(1))) return true;
            }
            return false;
        }
        return isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution solution;
    string s = "adceb";  // Example input string
    string p = "*a*b";  // Example wildcard pattern

    // Check if the string matches the wildcard pattern
    bool isMatching = solution.isMatch(s, p);

    // Print the result
    cout << "The string '" << s << "' matches the pattern '" << p << "': " << (isMatching ? "true" : "false") << endl;

    return 0;
}
