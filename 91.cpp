#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        auto v = generate(numRows - 1);
        auto lastRow = *(v.end() - 1);
        std::vector<int> res(1, 1);
        for (int i = 0; i < lastRow.size() - 1; i++) res.push_back(lastRow[i] + lastRow[i + 1]);
        res.push_back(1);
        v.push_back(res);
        return v;
    }
};

int main() {
    Solution solution;

    int numRows = 5; // Adjust the number of rows as needed
    std::vector<std::vector<int>> pascalsTriangle = solution.generate(numRows);

    // Print Pascal's Triangle
    for (const auto& row : pascalsTriangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
