#include <iostream>

class Solution {
public:
    static double myPow(double x, int n) {
        if (n == 0) return 1;
        double t = myPow(x, n / 2);
        if (n % 2) return n < 0 ? 1 / x * t * t : x * t * t;
        else return t * t;
    }
};

int main() {
    double x = 2.0;
    int n = 10;

    double result = Solution::myPow(x, n);

    std::cout << "The result of " << x << "^" << n << " is: " << result << std::endl;

    return 0;
}
