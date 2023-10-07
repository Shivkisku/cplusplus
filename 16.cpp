#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int diff = INT_MAX, res = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target) return target;
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    res = sum;
                }
                (sum > target) ? hi-- : lo++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> input = {-1, 2, 1, -4}; // Replace with your input vector of integers
    int target = 1; // Replace with your target value

    int result = solution.threeSumClosest(input, target);

    std::cout << "Closest three-sum to target: " << result << std::endl;

    return 0;
}
