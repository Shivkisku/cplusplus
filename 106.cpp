#include <iostream>
#include <vector>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {
            if (!p) {
                p = s.top();
                s.pop();
            }
            res.push_back(p->val);
            if (p->right) {
                s.push(p->right);
            }
            p = p->left;
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Create a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::cout << "Preorder Traversal: ";
    std::vector<int> result = solution.preorderTraversal(root);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Clean up memory (optional)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
