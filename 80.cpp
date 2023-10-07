#include <iostream>
#include <vector>
#include <deque>
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::deque<TreeNode*> cur, next;
        cur.push_back(root);
        std::vector<int> v;
        int level = 0;
        while (!cur.empty()) {
            auto p = cur.front();
            cur.pop_front();
            v.push_back(p->val);
            if (p->left) next.push_back(p->left);
            if (p->right) next.push_back(p->right);
            if (cur.empty()) {
                if (level++ % 2) std::reverse(v.begin(), v.end());
                res.push_back(v);
                v.clear();
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

    // Perform zigzag level order traversal
    std::vector<std::vector<int>> result = solution.zigzagLevelOrder(root);

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
