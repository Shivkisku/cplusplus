#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }

    int DFS(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int left = std::max(0, DFS(root->left, maxSum));
        int right = std::max(0, DFS(root->right, maxSum));
        maxSum = std::max(maxSum, left + right + root->val);
        return std::max(left, right) + root->val;
    }
};

int main() {
    Solution solution;

    // Construct a sample binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    int result = solution.maxPathSum(root);

    std::cout << "Maximum path sum: " << result << std::endl;

    // Don't forget to free memory (delete the tree nodes) to prevent memory leaks

    return 0;
}
