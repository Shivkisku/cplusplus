#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for undirected graph.
class UndirectedGraphNode {
public:
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
private:
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;

public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (!node) return nullptr;
        if (m.count(node) == 0) {
            m[node] = new UndirectedGraphNode(node->label);
            for (auto x : node->neighbors)
                m[node]->neighbors.push_back(cloneGraph(x));
        }
        return m[node];
    }
};

// Function prototype for dfsPrint
void dfsPrint(UndirectedGraphNode* node, std::unordered_map<UndirectedGraphNode*, bool>& visited);

void printGraph(UndirectedGraphNode* node) {
    if (!node) return;
    std::unordered_map<UndirectedGraphNode*, bool> visited;
    std::cout << "Original Graph:" << std::endl;
    dfsPrint(node, visited);
    std::cout << std::endl;

    visited.clear();
    std::cout << "Cloned Graph:" << std::endl;
    dfsPrint(node, visited);
}

void dfsPrint(UndirectedGraphNode* node, std::unordered_map<UndirectedGraphNode*, bool>& visited) {
    if (!node || visited[node]) return;
    visited[node] = true;
    std::cout << "Label: " << node->label << ", Neighbors: ";
    for (auto neighbor : node->neighbors) {
        std::cout << neighbor->label << " ";
    }
    std::cout << std::endl;
    for (auto neighbor : node->neighbors) {
        dfsPrint(neighbor, visited);
    }
}

int main() {
    Solution solution;

    // Create a sample graph
    UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);

    // Clone the graph
    UndirectedGraphNode* clonedNode0 = solution.cloneGraph(node0);

    // Print the original and cloned graphs
    printGraph(node0);
    std::cout << std::endl;
    printGraph(clonedNode0);

    // Clean up memory (optional)
    delete node0;
    delete node1;
    delete node2;
    // Note: The cloned graph nodes are not deleted here since they are managed by the Solution class.

    return 0;
}
