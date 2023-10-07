#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        std::string res = strs[0];
        for (auto s : strs) res = match(res, s);
        return res;
    }

    std::string match(const std::string& pre, const std::string& s) {
        int i = 0, len = std::min(pre.size(), s.size());
        for (; i < len; i++) if (s[i] != pre[i]) break;
        return pre.substr(0, i);
    }
};

int main() {
    Solution solution;
    std::vector<std::string> input = {"flower", "flow", "flight"}; // Replace with your input vector of strings

    std::string result = solution.longestCommonPrefix(input);

    std::cout << "Longest common prefix: " << result << std::endl;

    return 0;
}
