#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        DFS(res, candidates, 0, 0, target, path);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& candidates, int pos, int sum, int target, vector<int>& path) {
        if (sum >= target) {
            if (sum == target) res.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (i != pos && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            DFS(res, candidates, i + 1, sum + candidates[i], target, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 5};  // Example candidates
    int target = 8;  // Example target value

    // Find all unique combinations that sum up to the target
    vector<vector<int>> result = solution.combinationSum2(candidates, target);

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
