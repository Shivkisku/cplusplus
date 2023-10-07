#include <iostream>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C - A) * (D - B);
        int areaB = (G - E) * (H - F);
        if (C < E || A > G || B > H || D < F) return areaA + areaB;

        // Calculate the overlapping rectangle coordinates.
        int I = std::max(A, E);
        int J = std::max(B, F);
        int K = std::min(C, G);
        int L = std::min(D, H);

        int overlap = (K - I) * (L - J);
        return areaA + areaB - overlap;
    }
};

int main() {
    Solution solution;
    int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2; // Replace these values with your input

    int totalArea = solution.computeArea(A, B, C, D, E, F, G, H);

    std::cout << "Total Area: " << totalArea << std::endl;

    return 0;
}
