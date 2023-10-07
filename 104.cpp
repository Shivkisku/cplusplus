#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto one = head, two = head, meet = head;

        // Step 1: Find the meeting point (if a cycle exists)
        while (two && two->next) {
            one = one->next;
            two = two->next->next;
            if (one == two) {
                meet = one;
                break;
            }
        }

        // Step 2: If no cycle was found, return NULL
        if (!two || !two->next) {
            return NULL;
        }

        // Step 3: Find the start of the cycle
        auto p = head;
        while (p != meet) {
            p = p->next;
            meet = meet->next;
        }

        return p;
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

    ListNode *result = solution.detectCycle(head);

    if (result) {
        std::cout << "The cycle begins at node with value " << result->val << std::endl;
    } else {
        std::cout << "No cycle found in the linked list." << std::endl;
    }

    // Clean up memory (optional)
    delete head;
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
