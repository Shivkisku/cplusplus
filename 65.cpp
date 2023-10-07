#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, std::vector<int>(), res);
        return res;
    }

    void backtrack(std::vector<int>& nums, int k, std::vector<int> subset, std::vector<std::vector<int>>& res) {
        if (k == nums.size()) {
            res.push_back(subset);
            return;
        }
        backtrack(nums, k + 1, subset, res);
        subset.push_back(nums[k]);
        backtrack(nums, k + 1, subset, res);
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {1, 2, 3};

    std::vector<std::vector<int>> result = solution.subsets(nums);

    std::cout << "Subsets:" << std::endl;
    for (const std::vector<int>& subset : result) {
        std::cout << "[ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
