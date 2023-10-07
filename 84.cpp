#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, bool& res) {
        if (!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        if (abs(l - r) > 1) res = false;
        return std::max(l, r) + 1;
    }
};

int main() {
    Solution solution;

    // Create a binary tree (balanced)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    // Check if the binary tree is balanced
    bool balanced = solution.isBalanced(root);

    // Print the result
    std::cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << std::endl;

    // Clean up memory (optional)
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
