#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;
        TreeNode* root = new TreeNode(nums[nums.size() / 2]);
        std::vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
        std::vector<int> right(nums.begin() + nums.size() / 2 + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};

// Function to print the inorder traversal of a BST (for verification)
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Solution solution;

    // Create a sorted array
    std::vector<int> nums = {-10, -3, 0, 5, 9};

    // Convert the sorted array to a BST
    TreeNode* root = solution.sortedArrayToBST(nums);

    // Print the inorder traversal of the BST (to verify the result)
    std::cout << "Inorder Traversal of the BST:" << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (optional)
    delete root;

    return 0;
}
