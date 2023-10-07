#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (auto x : nums) {
            if (count == 0) candidate = x;
            if (candidate == x) count++;
            else count--;
        }
        return candidate;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Replace this with your input data

    int majority = solution.majorityElement(nums);

    std::cout << "The majority element is: " << majority << std::endl;

    return 0;
}
