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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return !p && !q;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;

    // Create two binary trees
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Check if the trees are the same
    bool result = solution.isSameTree(tree1, tree2);

    // Print the result
    if (result) {
        std::cout << "The trees are the same." << std::endl;
    } else {
        std::cout << "The trees are not the same." << std::endl;
    }

    // Clean up memory (optional)
    delete tree1;
    delete tree2;

    return 0;
}
