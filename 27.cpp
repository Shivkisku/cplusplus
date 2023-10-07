#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while (j != nums.size()) {
            if (nums[j] == val) {
                j++;
            } else {
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3, 4, 5, 3};  // Example input
    int val = 3;  // Example value to remove

    // Remove instances of the specified value from the array
    int length = solution.removeElement(nums, val);

    // Print the modified array and its new length
    cout << "Modified Array: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "New Length: " << length << endl;

    return 0;
}
