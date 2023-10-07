#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int res = 0;
        for(auto& x: nums) res ^= x;
        return res;
    }
};

int main() {
    Solution solution;

    // Example input
    std::vector<int> nums = {4, 1, 2, 1, 2};

    // Find the single number
    int result = solution.singleNumber(nums);

    // Print the result
    std::cout << "The single number is: " << result << std::endl;

    return 0;
}
