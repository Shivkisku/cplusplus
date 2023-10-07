#include <iostream>
#include <string>
#include <algorithm> // Include the algorithm header for reverse

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int carry = 0;
        std::string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int num1 = i < 0 ? 0 : a[i] - '0';
            int num2 = j < 0 ? 0 : b[j] - '0';
            int sum = num1 + num2 + carry;
            s.push_back(sum % 2 + '0');
            carry = sum / 2;
            i--;
            j--;
        }
        std::reverse(s.begin(), s.end()); // Use std::reverse from algorithm header
        return s;
    }
};

int main() {
    Solution solution;

    std::string a = "1011"; // Replace with your desired input
    std::string b = "1101"; // Replace with your desired input

    std::string result = solution.addBinary(a, b);

    std::cout << "Result of binary addition: " << result << std::endl;

    return 0;
}
