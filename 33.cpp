#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            int count = 1;
            while (i < s.size() - 1 && s[i] == s[i + 1]) i++, count++;
            res.append(to_string(count) + s[i]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 5;  // Example value of n

    // Generate the nth term of the "count-and-say" sequence
    string result = solution.countAndSay(n);

    // Print the result
    cout << "The " << n << "th term of the 'count-and-say' sequence is: " << result << endl;

    return 0;
}
