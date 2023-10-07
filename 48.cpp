#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int distance = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            distance = std::max(distance, i + nums[i]);
            if (distance == i) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 3, 1, 1, 4};  // Example input vector

    bool result = solution.canJump(nums);

    if (result) {
        std::cout << "You can jump to the end of the array." << std::endl;
    } else {
        std::cout << "You cannot jump to the end of the array." << std::endl;
    }

    return 0;
}
