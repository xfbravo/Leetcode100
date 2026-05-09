#include <vector>
#include <algorithm>
class Solution
{
public:
    // LeetCode 309. Best Time to Buy and Sell Stock with Cooldown
    /*
    dp[i][j]表示第i天状态为j的最大利润，j=0表示不持有股票，j=1表示持有股票,j=2表示处于冷冻期
    状态转移方程：
    dp[i][0] = max(dp[i-1][0],dp[i-1][2])
    dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i])
    dp[i][2] = dp[i-1][1] + prices[i]
    */
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return std::max(dp[n - 1][0], dp[n - 1][2]);
    }
};