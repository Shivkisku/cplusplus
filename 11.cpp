#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0, minLeft = 0, minRight = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] < minRight) continue;
            minLeft = 0;
            for (int j = 0; j < i; j++) {
                if (height[j] < minLeft) continue;
                maxArea = std::max(maxArea, std::min(height[i], height[j]) * (i - j));
                minLeft = std::max(minLeft, height[j]);
            }
            minRight = std::max(minRight, height[i]);
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Replace with your input vector

    int result = solution.maxArea(height);

    std::cout << "Maximum area of container: " << result << std::endl;

    return 0;
}
