#include <iostream>
#include <vector>
#include <algorithm> // For reverse

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> v;
        dfs(root, v, 0);
        std::reverse(v.begin(), v.end());
        return v;
    }

    void dfs(TreeNode* root, std::vector<std::vector<int>>& v, int level) {
        if (!root) return;
        if (level == v.size()) v.push_back({});
        v[level].push_back(root->val);
        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
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

    // Calculate the level order traversal in reverse order
    std::vector<std::vector<int>> result = solution.levelOrderBottom(root);

    // Print the result
    std::cout << "Level Order Traversal in Reverse Order:" << std::endl;
    for (const std::vector<int>& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Clean up memory (optional)
    delete root;

    return 0;
}
