#include <iostream>
#include <vector>
#include <algorithm> // Include this header for std::reverse

class Solution {
public:
    void reverseWords(std::vector<char>& str) {
        for (int i = 0; i < str.size(); i++) {
            int j = i + 1;
            while (j < str.size() && str[j] != ' ') j++;
            int a = i, b = j - 1;
            while (a < b) std::swap(str[a++], str[b--]);
            i = j;
        }
        std::reverse(str.begin(), str.end());
    }
};

int main() {
    Solution solution;
    std::vector<char> input = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    
    solution.reverseWords(input);

    std::cout << "Reversed Words: ";
    for (char c : input) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
