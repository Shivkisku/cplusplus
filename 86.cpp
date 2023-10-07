#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main() {
    Solution solution;

    // Create a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Check if there is a path with the given sum
    bool hasPath = solution.hasPathSum(root, targetSum);

    // Print the result
    std::cout << "Has Path Sum " << targetSum << "? " << (hasPath ? "Yes" : "No") << std::endl;

    // Clean up memory (optional)
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
