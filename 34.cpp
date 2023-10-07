#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res, candidates, 0, 0, target, comb);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, int pos, int sum, int target, vector<int>& comb) {
        if (sum > target || pos == candidates.size()) return;
        if (sum == target) {
            res.push_back(comb);
            return;
        }
        backtrack(res, candidates, pos + 1, sum, target, comb);
        comb.push_back(candidates[pos]);
        backtrack(res, candidates, pos, sum + candidates[pos], target, comb);
        comb.pop_back();
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};  // Example candidates
    int target = 7;  // Example target value

    // Find all unique combinations that sum up to the target
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // Print the result
    cout << "Unique combinations that sum up to " << target << ":" << endl;
    for (const vector<int>& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
