#include <iostream>
#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string M[] = {"", "M", "MM", "MMM"};
        std::string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};

int main() {
    Solution solution;
    int input = 3999; // Replace with your input integer

    std::string result = solution.intToRoman(input);

    std::cout << "Roman numeral representation: " << result << std::endl;

    return 0;
}
