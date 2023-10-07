#include <iostream>
#include <vector>
#include <utility>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
        std::vector<int> res;
        std::vector<int> indegree(numCourses);
        std::vector<std::vector<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (indegree[j] == 0) break;
            }
            if (j == numCourses) return std::vector<int>();
            indegree[j] = -1;
            for (auto x : graph[j]) indegree[x]--;
            res.push_back(j);
        }
        return res;
    }
};

int main() {
    Solution solution;
    int numCourses = 4;
    std::vector<std::pair<int, int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}; // Replace this with your input data

    std::vector<int> courseOrder = solution.findOrder(numCourses, prerequisites);

    if (courseOrder.empty()) {
        std::cout << "There is no valid course order." << std::endl;
    } else {
        std::cout << "Valid Course Order:";
        for (int course : courseOrder) {
            std::cout << " " << course;
        }
        std::cout << std::endl;
    }

    return 0;
}
