#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        ListNode* slow(head), *fast(head), *next;
        while (fast) {
            int i = k - 1;
            while (fast && i--) fast = fast->next;
            if (fast) {
                next = fast->next;
                reverse(pre, slow, fast, next);
                pre = slow;
                slow = next;
                fast = next;
            }
        }
        return res->next;
    }

    void reverse(ListNode* left, ListNode* start, ListNode* end, ListNode* right) {
        ListNode* pre(left), *cur(start), *next;
        ListNode* tmp = start;
        while (cur != right) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left->next = pre;
        tmp->next = right;
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
    head->next->next->next->next = new ListNode(5);

    int k = 3;  // Example value of k

    // Print the original linked list
    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse nodes in k-groups
    ListNode* reversedList = solution.reverseKGroup(head, k);

    // Print the reversed linked list
    std::cout << "Reversed Linked List in " << k << "-groups: ";
    printLinkedList(reversedList);

    return 0;
}
