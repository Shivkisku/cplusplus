#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int result = solution.minimumTotal(triangle);

    std::cout << "Minimum path sum: " << result << std::endl;

    return 0;
}
