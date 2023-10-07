#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        auto v = getRow(rowIndex - 1);
        int n = v.size();
        for (int i = 1; i < n; i++)
            v[i] = (i <= n / 2) ? v[i] + v[n - i] : v[n - i];
        v.push_back(1);
        return v;
    }
};

int main() {
    Solution solution;

    int rowIndex = 4; // Adjust the rowIndex as needed
    std::vector<int> row = solution.getRow(rowIndex);

    // Print the k-th row of Pascal's Triangle
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
