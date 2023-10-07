#include <iostream>
#include <vector> // Include this header for std::vector

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* l = new ListNode(0);
        l->next = head;
        int x = m, y = n - m;
        while (--x) {
            l = l->next;
        }
        ListNode* pre = l->next, *cur = pre->next, *next;
        while (y--) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        l->next->next = cur;
        l->next = pre;
        return m == 1 ? pre : head;
    }
};

// Helper function to create a linked list from an array of values
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

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

    // Test case
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    int m = 2, n = 4;
    ListNode* reversed = solution.reverseBetween(head, m, n);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    std::cout << "Reversed Linked List from " << m << " to " << n << ": ";
    printLinkedList(reversed);

    return 0;
}
