#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string tmp = s;
            sortStr(tmp);
            m[tmp].push_back(s);
        }
        for (auto x : m) res.push_back(x.second);
        return res;
    }

    void sortStr(string& s) {
        unordered_map<char, int> m;
        for (auto c : s) m[c]++;
        string res = "";
        for (int i = 0; i < 26; i++) {
            while (m['a' + i]-- > 0) res.push_back('a' + i);
        }
        s = res;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};  // Example input

    // Group the anagrams
    vector<vector<string>> groupedAnagrams = solution.groupAnagrams(strs);

    // Print the grouped anagrams
    for (const vector<string>& group : groupedAnagrams) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
