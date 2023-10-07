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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        DFS(root, res, std::vector<int>(), 0, sum);
        return res;
    }

    void DFS(TreeNode* root, std::vector<std::vector<int>>& res, std::vector<int> path, int sum, int target) {
        if (!root) return;
        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == target) res.push_back(path);
            return;
        }
        DFS(root->left, res, path, sum, target);
        DFS(root->right, res, path, sum, target);
    }
};

void printPaths(const std::vector<std::vector<int>>& paths) {
    for (const auto& path : paths) {
        std::cout << "Path: ";
        for (int val : path) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Solution solution;

    // Create a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Find all paths with the given sum
    std::vector<std::vector<int>> paths = solution.pathSum(root, targetSum);

    // Print the paths
    printPaths(paths);

    // Clean up memory (optional)
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
