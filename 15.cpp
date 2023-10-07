#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int lo = i + 1;
            for (int hi = nums.size() - 1; hi > lo; hi--) {
                if (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]) continue;
                while (nums[lo] < -(nums[i] + nums[hi])) lo++;
                if (lo < hi && (nums[i] + nums[lo] + nums[hi]) == 0) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> input = {-1, 0, 1, 2, -1, -4}; // Replace with your input vector of integers

    std::vector<std::vector<int>> result = solution.threeSum(input);

    std::cout << "Triplets that sum up to zero:" << std::endl;
    for (const auto& triplet : result) {
        std::cout << "[";
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
