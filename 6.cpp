#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::vector<std::string> v(numRows, "");
        int d = 1;
        int row = 0;
        for (auto c : s) {
            v[row].push_back(c);
            row += d;
            if (row == numRows - 1) d = -1;
            if (row == 0) d = 1;
        }
        std::string res;
        for (auto x : v) res.append(x);
        return res;
    }
};

int main() {
    Solution solution;
    std::string input = "PAYPALISHIRING"; // Replace with your input string
    int numRows = 3; // Replace with the number of rows

    std::string result = solution.convert(input, numRows);

    std::cout << "ZigZag conversion: " << result << std::endl;

    return 0;
}
