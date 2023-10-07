#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_map<char, int>> row(n);
        vector<unordered_map<char, int>> col(n);
        vector<vector<unordered_map<char, int>>> sub(n / 3, vector<unordered_map<char, int>>(n / 3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (row[i][c]++ > 0 || col[j][c]++ > 0 || sub[i / 3][j / 3][c]++ > 0) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Check the validity of the Sudoku board
    bool isValid = solution.isValidSudoku(board);

    // Print the result
    if (isValid) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}
