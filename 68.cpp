#include <iostream>
#include <vector> // Include the vector header

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        auto p = deleteDuplicates(head->next);
        head->next = p;
        return p->val == head->val ? p : head;
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
