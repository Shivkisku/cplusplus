#include <iostream>
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::string s = "", res = "";
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        std::string path = s;
        int count = 0;
        DFS(s, 0, count, n, k, path, res);
        return res;
    }

    void DFS(std::string& s, int pos, int& count, int n, int k, std::string& path, std::string& res) {
        if (count >= k || pos == n) {
            if (++count == k) {
                res = path;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                continue;
            }
            path[pos] = s[i];
            s[i] = '0';
            DFS(s, pos + 1, count, n, k, path, res);
            s[i] = path[pos];
        }
    }
};

int main() {
    Solution solution;
    int n = 3;  // Replace with your desired value of n
    int k = 3;  // Replace with your desired value of k

    std::string result = solution.getPermutation(n, k);

    std::cout << "Permutation sequence: " << result << std::endl;

    return 0;
}
