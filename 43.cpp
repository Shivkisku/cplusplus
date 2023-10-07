#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        helper(matrix, 0, 0, matrix.size());
    }

    void helper(vector<vector<int>>& matrix, int row, int col, int size) {
        if (size == 0 || size == 1) return;
        int step = 0;
        while (step < size - 1) {
            swap(matrix[row][col + step], matrix[row + step][col + size - 1]);
            swap(matrix[row][col + step], matrix[row + size - 1 - step][col]);
            swap(matrix[row + size - 1][col + size - 1 - step], matrix[row + size - 1 - step][col]);
            step++;
        }
        helper(matrix, row + 1, col + 1, size - 2);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };  // Example input matrix

    // Rotate the matrix in place
    solution.rotate(matrix);

    // Print the rotated matrix
    cout << "Rotated matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
