#include <iostream>
#include <string>
#include <unordered_map>
#include <climits> // Add this line

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> m;
        int i = 0, j = 0, count = 0, minLen = INT_MAX;
        std::string res = "";
        for (auto x : t) m[x]++, count++;
        while (j < s.size()) {
            if (m[s[j++]]-- > 0) count--;
            if (count == 0) {
                while (m[s[i]] < 0) m[s[i++]]++;
                int len = j - i;
                if (len < minLen) {
                    minLen = len;
                    res = s.substr(i, len);
                }
                m[s[i++]]++;
                count++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";

    std::string result = solution.minWindow(s, t);

    std::cout << "Minimum Window Substring: " << result << std::endl;

    return 0;
}
