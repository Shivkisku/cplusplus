#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
private:
    std::unordered_map<std::string, int> m;
    std::unordered_map<std::string, bool> dp;

public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        for (auto x : wordDict) m[x]++;
        return DFS(s);
    }

    bool DFS(std::string s) {
        if (dp.count(s)) return dp[s];
        if (s.empty()) return true;
        bool found = false;
        for (int i = 1; i <= s.size() && !found; i++)
            if (m.count(s.substr(0, i))) found |= DFS(s.substr(i));
        dp[s] = found;
        return found;
    }
};

int main() {
    Solution solution;

    std::string s = "leetcode";
    std::vector<std::string> wordDict = { "leet", "code" };

    bool result = solution.wordBreak(s, wordDict);

    if (result) {
        std::cout << "The string can be segmented into dictionary words." << std::endl;
    } else {
        std::cout << "The string cannot be segmented into dictionary words." << std::endl;
    }

    return 0;
}
