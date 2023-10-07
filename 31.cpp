#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid = lo + (hi - lo) / 2;
        while (lo <= hi) {
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
            mid = lo + (hi - lo) / 2;
        }
        return lo;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};  // Example sorted array
    int target = 5;  // Example target value

    // Find the index at which the target should be inserted
    int index = solution.searchInsert(nums, target);

    // Print the result
    cout << "The target " << target << " should be inserted at index " << index << endl;

    return 0;
}
