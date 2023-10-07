#include <iostream>
#include <vector>  // Include vector header

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode res(0);
        res.next = head;
        ListNode* pre = &res, *cur = head, *next = cur ? cur->next : NULL;
        while (cur) {
            bool dup = false;
            while (next && next->val == cur->val) {
                dup = true;
                next = next->next;
            }
            if (dup) {
                cur = next;
                next = next ? next->next : NULL;
                pre->next = cur;
            } else {
                pre = cur;
                cur = next;
                next = next ? next->next : NULL;
            }
        }
        return res.next;
    }
};

// Utility function to create a linked list from an array of values
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Sample input: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    std::vector<int> values = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = createLinkedList(values);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    ListNode* result = solution.deleteDuplicates(head);

    std::cout << "Modified linked list: ";
    printLinkedList(result);

    return 0;
}
