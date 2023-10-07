#include <iostream>
#include <string>

class Solution {
public:
    std::string convertToTitle(int n) {
        std::string res;
        char c;
        while (n) {
            c = 'A' + (n - 1) % 26;
            res = c + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 28; // Replace this with your input number

    std::string columnTitle = solution.convertToTitle(n);

    std::cout << "Excel Sheet Column Title: " << columnTitle << std::endl;

    return 0;
}
