#include <iostream>
#include <vector> // Include the <vector> header

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode right(0);
        ListNode* l = &left;
        ListNode* r = &right;
        ListNode* cur = head;
        
        while (cur) {
            if (cur->val < x) {
                l->next = cur;
                l = l->next;
            } else {
                r->next = cur;
                r = r->next;
            }
            cur = cur->next;
        }
        
        // Terminate the right list to avoid cycles
        r->next = nullptr;
        
        // Connect the two lists
        l->next = right.next;
        
        return left.next;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return dummy.next;
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
    std::vector<int> values = {1, 4, 3, 2, 5, 2};
    ListNode* head = createLinkedList(values);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    int x = 3;
    ListNode* result = solution.partition(head, x);

    std::cout << "Partitioned Linked List: ";
    printLinkedList(result);

    // Clean up the dynamically allocated memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
