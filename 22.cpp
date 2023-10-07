#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        DFS(res, n, 0, 0, path);
        return res;
    }

    void DFS(vector<string>& res, int n, int k, int left, string& path) {
        if (left > n) return;
        if (k == n) {
            if (left == 0) res.push_back(path);
            return;
        }
        path.push_back('(');
        DFS(res, n, k, left + 1, path);
        path.pop_back();

        if (left != 0) {
            path.push_back(')');
            DFS(res, n, k + 1, left - 1, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int n = 3;  // Example input

    // Generate valid parentheses combinations
    vector<string> result = solution.generateParenthesis(n);

    // Print the result
    cout << "Valid Parentheses Combinations for n=" << n << " are:" << endl;
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}
