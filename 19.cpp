#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow(head), *fast(head);
        while (n--) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) slow = slow->next, fast = fast->next;
        slow->next = slow->next->next;
        return head;
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int n = 2;  // Example value of n

    // Print the original linked list
    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // Remove the Nth node from the end
    head = solution.removeNthFromEnd(head, n);

    // Print the updated linked list
    std::cout << "Updated Linked List: ";
    printLinkedList(head);

    return 0;
}
