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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValid(root->left, root->val, true) || !isValid(root->right, root->val, false)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool isValid(TreeNode* root, int bound, bool isLeft) {
        return !root || (isLeft ? root->val < bound : root->val > bound) && isValid(root->left, bound, isLeft) && isValid(root->right, bound, isLeft);
    }
};

// Helper function to create a sample binary tree (change as needed)
TreeNode* createTree() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution solution;
    
    TreeNode* root = createTree(); // Change this to create your binary tree
    
    bool result = solution.isValidBST(root);
    
    if (result) {
        std::cout << "The given binary tree is a valid BST." << std::endl;
    } else {
        std::cout << "The given binary tree is not a valid BST." << std::endl;
    }
    
    return 0;
}
