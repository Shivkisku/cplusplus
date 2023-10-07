#include <iostream>
#include <unordered_set>
using namespace std; // Add this line to include the standard namespace

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxlen = 0, i = 0, j = 0, next = 0;
        unordered_set<char> set;
        while (j < s.size()) {
            j = i;
            while (j < s.size()) {
                if (set.size() == 1)
                    next = j;
                set.insert(s[j]);
                if (set.size() > 2) {
                    maxlen = max(maxlen, j - i);
                    i = next;
                    set.clear();
                    break;
                }
                j++;
            }
        }
        maxlen = max(maxlen, j - i);
        return maxlen;
    }
};

int main() {
    Solution solution;
    string s = "eceba"; // Replace with your test input

    int result = solution.lengthOfLongestSubstringTwoDistinct(s);

    cout << "Length of longest substring with at most two distinct characters: " << result << endl;

    return 0;
}
