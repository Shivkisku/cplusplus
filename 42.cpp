#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        DFS(res, nums, 0);
        return res;
    }

    void DFS(vector<vector<int>>& res, vector<int> nums, int pos) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[pos]) continue;
            swap(nums[pos], nums[i]);
            DFS(res, nums, pos + 1);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};  // Example input with duplicates

    // Generate all unique permutations
    vector<vector<int>> uniquePermutations = solution.permuteUnique(nums);

    // Print the unique permutations
    cout << "All unique permutations of ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << " are:" << endl;

    for (const vector<int>& perm : uniquePermutations) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
