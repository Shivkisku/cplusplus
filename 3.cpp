#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> m;
        int maxlen = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            m[s[j]]++;
            while (m[s[j]] > 1) {
                m[s[i++]]--;
            }
            maxlen = std::max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution solution;
    std::string input = "abcabcbb"; // Replace with your input string

    int result = solution.lengthOfLongestSubstring(input);

    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

    return 0;
}
