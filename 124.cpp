#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4}; // Replace this with your input data
    int k = 2; // Replace this with your desired value of k

    int kthLargest = solution.findKthLargest(nums, k);

    std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;

    return 0;
}
