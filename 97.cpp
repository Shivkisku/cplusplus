#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, res, 0);
        return res;
    }

    void dfs(TreeNode* root, int& res, int num) {
        num = num * 10 + root->val;
        if (root->left) dfs(root->left, res, num);
        if (root->right) dfs(root->right, res, num);
        if (!root->left && !root->right) res += num;
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int result = solution.sumNumbers(root);

    std::cout << "The sum of root-to-leaf numbers is: " << result << std::endl;

    // Clean up memory (optional)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
