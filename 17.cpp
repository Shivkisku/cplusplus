#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        vector<string> letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        DFS(digits, 0, path, res, letter);
        return res;
    }

    void DFS(string digits, int pos, string& path, vector<string>& res, vector<string>& letter) {
        if (pos == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto c : letter[digits[pos] - '0']) {
            path.push_back(c);
            DFS(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }
};

int main() {
    Solution solution;
    string digits = "23";  // Example input
    vector<string> result = solution.letterCombinations(digits);

    // Print the result
    cout << "Letter Combinations for " << digits << " are:" << endl;
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
