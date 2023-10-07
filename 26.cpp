#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            while (j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
            nums[i++] = nums[j++];
        }
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5};  // Example input

    // Remove duplicates from the sorted array
    int length = solution.removeDuplicates(nums);

    // Print the modified array and its length
    cout << "Modified Array: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "New Length: " << length << endl;

    return 0;
}
