#include <iostream>
#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution solution;
    uint32_t n = 11; // Replace this with your input number

    int numberOfOnes = solution.hammingWeight(n);

    std::cout << "Number of 1 Bits in " << n << ": " << numberOfOnes << std::endl;

    return 0;
}
