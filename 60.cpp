#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        int lo = 1, hi = x;
        while (true) {
            int mid = lo + (hi - lo) / 2;
            if (mid > x / mid) hi = mid - 1;
            else if (mid + 1 > x / (mid + 1)) return mid;
            else lo = mid + 1;
        }
    }
};

int main() {
    Solution solution;

    int x = 16; // Replace with the integer for which you want to find the square root

    int result = solution.mySqrt(x);

    std::cout << "The square root of " << x << " is: " << result << std::endl;

    return 0;
}
