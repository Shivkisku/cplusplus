#include <iostream>
#include <deque>

// Definition for a binary tree node with "next" pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        std::deque<TreeLinkNode*> cur;
        std::deque<TreeLinkNode*> next;
        cur.push_back(root);
        while (!cur.empty()) {
            TreeLinkNode* node = cur.front();
            cur.pop_front();
            node->next = cur.empty() ? nullptr : cur.front();
            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
            if (cur.empty()) std::swap(cur, next);
        }
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    // Connect nodes
    solution.connect(root);

    // Print the "next" pointers to check the connections
    TreeLinkNode* node = root;
    while (node) {
        TreeLinkNode* levelNode = node;
        while (levelNode) {
            std::cout << levelNode->val;
            if (levelNode->next) {
                std::cout << " -> ";
            } else {
                std::cout << " -> nullptr";
            }
            levelNode = levelNode->next;
        }
        std::cout << std::endl;
        node = node->left;
    }

    // Clean up memory (optional)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
