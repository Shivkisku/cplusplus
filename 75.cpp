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
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return DFS(1, n);
    }

    std::vector<TreeNode*> DFS(int l, int r) {
        std::vector<TreeNode*> res;
        if (l > r) return {nullptr};
        for (int i = l; i <= r; i++) {
            auto left = DFS(l, i - 1);
            auto right = DFS(i + 1, r);
            for (auto x : left) {
                for (auto y : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    // Helper function to print a binary tree (inorder traversal)
    void printTree(TreeNode* root) {
        if (root) {
            printTree(root->left);
            std::cout << root->val << " ";
            printTree(root->right);
        }
    }
};

int main() {
    Solution solution;
    int n = 3; // Change 'n' to the desired value

    std::vector<TreeNode*> trees = solution.generateTrees(n);

    // Print the generated trees
    for (int i = 0; i < trees.size(); i++) {
        std::cout << "Tree " << (i + 1) << ": ";
        solution.printTree(trees[i]);
        std::cout << std::endl;
    }

    return 0;
}
