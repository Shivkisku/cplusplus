#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        for (int x : nums) {
            if (x == i) i++;
        }
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 4, -1, 1};  // Example input

    // Find the first missing positive integer
    int missing = solution.firstMissingPositive(nums);

    // Print the result
    cout << "The first missing positive integer is: " << missing << endl;

    return 0;
}
