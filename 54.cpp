#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution solution;

    int m = 3; // Replace with your desired value of m
    int n = 7; // Replace with your desired value of n

    int result = solution.uniquePaths(m, n);

    std::cout << "Number of unique paths: " << result << std::endl;

    return 0;
}
