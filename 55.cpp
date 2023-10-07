#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<int> dp(n);
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    }; // Replace with your desired obstacleGrid

    int result = solution.uniquePathsWithObstacles(obstacleGrid);

    std::cout << "Number of unique paths: " << result << std::endl;

    return 0;
}
