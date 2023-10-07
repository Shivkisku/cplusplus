#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int i = 2, j = 2;
        while (j < nums.size()) {
            if (nums[j] > nums[i - 2]) {
                nums[i++] = nums[j++];
            } else {
                j++;
            }
        }
        return i;
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {1, 1, 1, 2, 2, 3};

    int result = solution.removeDuplicates(nums);

    std::cout << "Modified array: [";
    for (int i = 0; i < result; i++) {
        std::cout << nums[i];
        if (i < result - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
