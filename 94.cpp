#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;
        std::vector<int> buy(prices.size());
        std::vector<int> dp(prices.size());
        buy[0] = prices[0];
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy[i] = std::min(buy[i - 1], prices[i]);
            dp[i] = std::max(dp[i - 1], prices[i] - buy[i - 1]);
        }
        return dp[prices.size() - 1];
    }
};

int main() {
    Solution solution;

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = solution.maxProfit(prices);

    std::cout << "Maximum profit: " << result << std::endl;

    return 0;
}
