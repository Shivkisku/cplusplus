#include <iostream>
#include <unordered_map>

// Definition for a Node.
class RandomListNode {
public:
    int val;
    RandomListNode* next;
    RandomListNode* random;
    RandomListNode(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (!head) return nullptr;

        // Create a mapping between original nodes and copied nodes
        std::unordered_map<RandomListNode*, RandomListNode*> nodeMap;

        // Create a new head for the copied list
        RandomListNode* newHead = new RandomListNode(head->val);
        RandomListNode* current = head;
        RandomListNode* newCurrent = newHead;

        // Map the original head to the copied head
        nodeMap[current] = newCurrent;

        // Copy the next pointers
        while (current->next) {
            newCurrent->next = new RandomListNode(current->next->val);
            current = current->next;
            newCurrent = newCurrent->next;
            nodeMap[current] = newCurrent;
        }

        // Reset the pointers for traversal
        current = head;
        newCurrent = newHead;

        // Copy the random pointers
        while (current) {
            newCurrent->random = nodeMap[current->random];
            current = current->next;
            newCurrent = newCurrent->next;
        }

        return newHead;
    }
};

// Function to print the linked list
void printRandomList(RandomListNode* head) {
    RandomListNode* current = head;
    while (current) {
        std::cout << "Node(" << current->val << ", ";
        if (current->random) {
            std::cout << current->random->val << ")";
        } else {
            std::cout << "null)";
        }
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example input: Create a linked list with random pointers
    RandomListNode* head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    // Copy the linked list
    RandomListNode* copiedHead = solution.copyRandomList(head);

    // Print the original and copied linked lists
    std::cout << "Original Linked List:" << std::endl;
    printRandomList(head);

    std::cout << "Copied Linked List:" << std::endl;
    printRandomList(copiedHead);

    return 0;
}
