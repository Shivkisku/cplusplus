#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = solution.twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices of the two numbers that add up to the target: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
