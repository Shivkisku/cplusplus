#include <iostream>
#include <cctype> // For isalnum function
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !std::isalnum(s[i])) i++;
            while (i < j && !std::isalnum(s[j])) j--;
            if (std::tolower(s[i++]) != std::tolower(s[j--])) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    std::string input = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(input);

    if (result) {
        std::cout << "The input string is a palindrome." << std::endl;
    } else {
        std::cout << "The input string is not a palindrome." << std::endl;
    }

    return 0;
}
