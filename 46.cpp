#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // dp[i] = max(dp[i - 1] + A[i], A[i])
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            maxSum = std::max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  // Example input array

    int result = solution.maxSubArray(nums);

    std::cout << "The maximum subarray sum is: " << result << std::endl;

    return 0;
}
