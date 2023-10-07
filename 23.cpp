#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        for (int i = 0, j = 1; j < lists.size(); i++, j++)
            lists[j] = mergeTwoLists(lists[i], lists[j]);
        return *(lists.end() - 1);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode head(0);
        ListNode* cur = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return head.next;
    }
};

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;

    // Create three sorted linked lists
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    // Store the linked lists in a vector
    vector<ListNode*> lists = { l1, l2, l3 };

    // Merge the k sorted lists
    ListNode* mergedList = solution.mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}
