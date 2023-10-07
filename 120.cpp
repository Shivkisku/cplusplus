#include <iostream>
#include <vector>
#include <utility>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
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
            if (j == numCourses) return false;
            indegree[j] = -1;
            for (auto x : graph[j]) indegree[x]--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    int numCourses = 2;
    std::vector<std::pair<int, int>> prerequisites = {{1, 0}}; // Replace this with your input data

    bool canFinishResult = solution.canFinish(numCourses, prerequisites);

    if (canFinishResult) {
        std::cout << "You can finish all courses." << std::endl;
    } else {
        std::cout << "You cannot finish all courses." << std::endl;
    }

    return 0;
}
