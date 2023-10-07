#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> s;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || heights[i] < heights[s.top()])) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            s.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = solution.maximalRectangle(matrix);
    std::cout << "Maximal Rectangle Area: " << result << std::endl;

    return 0;
}
