#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> m({
            {'I', 1}, {'X', 10}, {'C', 100}, {'M', 1000},
            {'V', 5}, {'L', 50}, {'D', 500}
        });
        
        if (s.empty()) return 0;
        
        int sum = m[s.back()];
        for (int i = s.size() - 2; i >= 0; i--) {
            if (m[s[i]] >= m[s[i + 1]]) {
                sum += m[s[i]];
            } else {
                sum -= m[s[i]];
            }
        }
        
        return sum;
    }
};

int main() {
    Solution solution;
    std::string input = "MCMXCIV"; // Replace with your input Roman numeral string

    int result = solution.romanToInt(input);

    std::cout << "Integer representation: " << result << std::endl;

    return 0;
}
