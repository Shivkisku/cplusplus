#include <iostream>
#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s.front() == '0') {
            return 0;
        }
        int p1 = 1, p2 = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                p1 = 0;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
                p1 = p1 + p2;
                p2 = p1 - p2;
            } else {
                p2 = p1;
            }
        }
        return p1;
    }
};

int main() {
    Solution solution;

    // Test cases
    std::string s1 = "12";
    std::string s2 = "226";
    std::string s3 = "0";

    int result1 = solution.numDecodings(s1);
    int result2 = solution.numDecodings(s2);
    int result3 = solution.numDecodings(s3);

    std::cout << "Number of Decodings for '" << s1 << "': " << result1 << std::endl;
    std::cout << "Number of Decodings for '" << s2 << "': " << result2 << std::endl;
    std::cout << "Number of Decodings for '" << s3 << "': " << result3 << std::endl;

    return 0;
}
