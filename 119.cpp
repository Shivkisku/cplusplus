#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> ms, mt;
        for (int i = 0; i < s.size(); ++i) {
            if (ms.count(s[i]) && mt.count(t[i])) {
                if (ms[s[i]] != t[i]) {
                    return false;
                }
            } else if (ms.count(s[i]) || mt.count(t[i])) {
                return false;
            } else {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::string s = "egg";
    std::string t = "add";

    bool isIsomorphicResult = solution.isIsomorphic(s, t);

    if (isIsomorphicResult) {
        std::cout << "The strings are isomorphic." << std::endl;
    } else {
        std::cout << "The strings are not isomorphic." << std::endl;
    }

    return 0;
}
