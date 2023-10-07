#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return (x == y || x == y / 10);
    }
};

int main() {
    Solution solution;
    int input = 121; // Replace with your input integer

    bool result = solution.isPalindrome(input);

    std::cout << "Is the integer a palindrome? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
