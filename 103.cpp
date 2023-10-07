#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto one = head, two = head;
        while (two && two->next) {
            one = one->next;
            two = two->next->next;
            if (one == two) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Create a linked list with a cycle for testing
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // This creates a cycle

    bool result = solution.hasCycle(head);

    if (result) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    // Clean up memory (optional)
    delete head;
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
