#include <iostream>
#include <string>

class Solution {
public:
    int titleToNumber(std::string s) {
        int res = 0;
        for (auto c : s) {
            res *= 26;
            res += c - 'A' + 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::string columnTitle = "AB"; // Replace this with your input column title

    int columnNumber = solution.titleToNumber(columnTitle);

    std::cout << "Excel Sheet Column Number: " << columnNumber << std::endl;

    return 0;
}
