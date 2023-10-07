#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(res, nums, 0, std::vector<int>());
        return res;
    }
private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& nums, int pos, std::vector<int> comb) {
        if (pos >= nums.size()) {
            for (auto x : res) {
                if (isEqual(x, comb)) {
                    return;
                }
            }
            res.push_back(comb);
            return;
        }
        backtrack(res, nums, pos + 1, comb);
        comb.push_back(nums[pos]);
        backtrack(res, nums, pos + 1, comb);
    }

    bool isEqual(std::vector<int>& v1, std::vector<int>& v2) {
        if (v1.size() != v2.size()) {
            return false;
        }
        std::unordered_map<int, int> m;
        for (auto x : v1) {
            m[x]++;
        }
        for (auto x : v2) {
            if (--m[x] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test case
    std::vector<int> nums = {1, 2, 2};

    std::vector<std::vector<int>> result = solution.subsetsWithDup(nums);

    std::cout << "Subsets with Duplicates:" << std::endl;
    for (const std::vector<int>& subset : result) {
        std::cout << "[ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
