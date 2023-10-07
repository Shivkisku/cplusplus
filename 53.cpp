#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int len = 0;
        ListNode* p = head;
        while (p) p = p->next, len++;
        k = k % len;
        if (k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while (k > 0) fast = fast->next, k--;
        while (fast->next) fast = fast->next, slow = slow->next;

        ListNode* res = slow->next;

        slow->next = nullptr;
        fast->next = head;

        return res;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedListFromArray(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
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

    // Create a linked list from an array
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createLinkedListFromArray(arr, n);

    int k = 2; // Replace with your desired value of k

    // Call the rotateRight function
    ListNode* rotatedHead = solution.rotateRight(head, k);

    // Print the resulting linked list
    printLinkedList(rotatedHead);

    return 0;
}
