#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9) digits[i--] = 0;
        if (i < 0) digits.insert(digits.begin(), 1); // Insert 1 at the beginning if needed
        else digits[i]++;
        return digits;
    }
};

int main() {
    Solution solution;

    std::vector<int> digits = {1, 2, 3}; // Replace with your desired input

    std::vector<int> result = solution.plusOne(digits);

    std::cout << "Result after adding one: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
