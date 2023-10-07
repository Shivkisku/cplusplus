#include <iostream>
#include <algorithm> // Include the <algorithm> header

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL, *one = NULL, *two = NULL;
        DFS(root, pre, one, two);
        std::swap(one->val, two->val); // Use std::swap
    }

    void DFS(TreeNode* cur, TreeNode* &pre, TreeNode* &one, TreeNode* &two) {
        if (!cur) return;
        DFS(cur->left, pre, one, two);
        if (pre && cur->val < pre->val) {
            if (!one) one = pre;
            two = cur;
        }
        pre = cur;
        DFS(cur->right, pre, one, two);
    }
};

// Helper function to create a sample binary tree with swapped nodes (change as needed)
TreeNode* createTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    return root;
}

void printTree(TreeNode* root) {
    if (root) {
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
}

int main() {
    Solution solution;

    TreeNode* root = createTree(); // Change this to create your custom binary tree with swapped nodes

    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;

    solution.recoverTree(root);

    std::cout << "Recovered tree: ";
    printTree(root);
    std::cout << std::endl;

    return 0;
}
