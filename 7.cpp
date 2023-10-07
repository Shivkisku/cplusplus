#include <iostream>
#include <climits> // Include this header for INT_MIN and INT_MAX

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res < INT_MIN || res > INT_MAX) ? 0 : static_cast<int>(res);
    }
};

int main() {
    Solution solution;
    int input = 123; // Replace with your input integer

    int result = solution.reverse(input);

    std::cout << "Reversed integer: " << result << std::endl;

    return 0;
}
