#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp[0][0] = grid[0][0];

        // Initialize the first row and first column
        for (int i = 1; i < m; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < n; j++) dp[0][j] = grid[0][j] + dp[0][j - 1];

        // Fill in the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    }; // Replace with your desired grid

    int result = solution.minPathSum(grid);

    std::cout << "Minimum path sum: " << result << std::endl;

    return 0;
}
