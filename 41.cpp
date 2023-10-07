#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        DFS(res, nums, 0);
        return res;
    }

    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            DFS(res, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};  // Example input

    // Generate all possible permutations
    vector<vector<int>> permutations = solution.permute(nums);

    // Print the permutations
    cout << "All possible permutations of ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << " are:" << endl;

    for (const vector<int>& perm : permutations) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
