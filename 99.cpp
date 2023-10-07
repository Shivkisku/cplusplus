#include <iostream>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n(gas.size()), sum(0), total(0), res(0);
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                res = i + 1;
                sum = 0;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? res : -1;
    }
};

int main() {
    Solution solution;

    // Example input
    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};

    // Find the starting gas station index
    int result = solution.canCompleteCircuit(gas, cost);

    // Print the result
    if (result != -1) {
        std::cout << "You can start from gas station " << result << std::endl;
    } else {
        std::cout << "You can't complete the circuit." << std::endl;
    }

    return 0;
}
