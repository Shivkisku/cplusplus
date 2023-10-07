#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        int i = 0, j = 0, sum = 0, len = nums.size();
        while (j < nums.size()) {
            while (j < nums.size() && sum < s) sum += nums[j++];
            if (i == 0 && sum < s) return 0;
            while (sum - nums[i] >= s) sum -= nums[i++];
            len = std::min(len, j - i);
            sum -= nums[i++];
        }
        return len;
    }
};

int main() {
    Solution solution;
    int s = 7;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3}; // Replace this with your input data

    int minLength = solution.minSubArrayLen(s, nums);

    std::cout << "Minimum Length of Subarray: " << minLength << std::endl;

    return 0;
}
