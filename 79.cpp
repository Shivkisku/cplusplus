#include <vector>
#include <deque>
#include <algorithm> // For swap
#include <iostream> // For cout and endl

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::deque<TreeNode*> cur;
        std::deque<TreeNode*> next;
        cur.push_back(root);
        int level = 0;
        res.push_back(std::vector<int>());
        while (!cur.empty()) {
            TreeNode* node = cur.front();
            cur.pop_front();
            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
            res[level].push_back(node->val);
            if (cur.empty() && !next.empty()) {
                res.push_back(std::vector<int>());
                level++;
                std::swap(cur, next);
            }
        }
        return res;
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

    // Perform level order traversal
    std::vector<std::vector<int>> result = solution.levelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Clean up memory (optional)
    delete root;

    return 0;
}
