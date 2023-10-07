#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
        std::vector<std::string> res;
        if (nums.empty()) {
            res.push_back((lower == upper) ? std::to_string(lower) : std::to_string(lower) + "->" + std::to_string(upper));
            return res;
        }
        int cur = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            std::string s = "";
            if (nums[i] > cur) s += std::to_string(cur++);
            if (nums[i] > cur) s += "->" + std::to_string(nums[i] - 1);
            cur = nums[i] + 1;
            if (!s.empty()) res.push_back(s);
        }
        if (nums.back() == upper - 1) res.push_back(std::to_string(upper));
        else if (nums.back() < upper) res.push_back(std::to_string(nums.back() + 1) + "->" + std::to_string(upper));
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    std::vector<std::string> missingRanges = solution.findMissingRanges(nums, lower, upper);

    std::cout << "Missing Ranges:" << std::endl;
    for (const std::string& range : missingRanges) {
        std::cout << range << std::endl;
    }

    return 0;
}
