#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        int j = i;
        while (j >= 0 && s[j] != ' ') {
            j--;
        }
        return i - j;
    }
};

int main() {
    Solution solution;
    std::string input = "JOHAR MARANGBURU";  // Replace with your desired input string

    int result = solution.lengthOfLastWord(input);

    std::cout << "Length of the last word: " << result << std::endl;

    return 0;
}
