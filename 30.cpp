#include <iostream>
#include <vector>
#include <algorithm> // Include this header for upper_bound
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (lo > hi) return {-1, -1};
        return {lo, hi};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 8, 10};  // Example sorted array
    int target = 8;  // Example target value

    // Search for the first and last positions of the target value
    vector<int> result = solution.searchRange(nums, target);

    // Print the result
    if (result[0] != -1) {
        cout << "The first occurrence of " << target << " is at index " << result[0] << endl;
        cout << "The last occurrence of " << target << " is at index " << result[1] << endl;
    } else {
        cout << target << " not found in the array" << endl;
    }

    return 0;
}
