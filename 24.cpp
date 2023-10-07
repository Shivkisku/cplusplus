#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode res(0);
        ListNode* pre = &res, *one = head, *two = head->next;
        while (one && two) {
            one->next = two->next;
            two->next = one;
            pre->next = two;
            pre = one;
            one = one->next;
            if (one) two = one->next;
        }
        return res.next;
    }
};

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Solution solution;

    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Print the original linked list
    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // Swap nodes in pairs
    ListNode* swappedList = solution.swapPairs(head);

    // Print the swapped linked list
    std::cout << "Swapped Linked List: ";
    printLinkedList(swappedList);

    return 0;
}
