#include <iostream>
#include <algorithm> // For max

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    Solution solution;

    // Create a binary tree (you can customize this part)
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calculate the maximum depth
    int result = solution.maxDepth(root);

    // Print the result
    std::cout << "Maximum Depth of the Binary Tree: " << result << std::endl;

    // Clean up memory (optional)
    delete root;

    return 0;
}
