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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return root->left && root->right ? std::min(l, r) + 1 : l + r + 1;
    }
};

int main() {
    Solution solution;

    // Create a binary tree (with minimum depth)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);

    // Calculate the minimum depth of the binary tree
    int minDepth = solution.minDepth(root);

    // Print the minimum depth
    std::cout << "Minimum Depth: " << minDepth << std::endl;

    // Clean up memory (optional)
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
