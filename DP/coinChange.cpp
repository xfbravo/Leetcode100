#include <vector>
#include <algorithm>
//[1,2,5]
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
// 1, 1, 2, 2,-1,-1,-1,-1,-1, -1, -1
class Solution
{
public:
    // int coinChange(std::vector<int> &coins, int amount)
    // {
    //     std::vector<int> dp(amount + 1, -1);
    //     std::sort(coins.begin(), coins.end());
    //     int n = coins.size();
    //     dp[0] = 0;
    //     for (int i = 1; i <= amount; i++)
    //     {
    //         // 对于每一种金额的零钱
    //         for (int j = 0; j < n; j++)
    //         {
    //             // 计算该面额减去零钱面额的complement
    //             int complement = i - coins[j];
    //             // 如果complement<0，说明零钱面额太大，找不到合适的，直接break
    //             if (complement < 0)
    //             {
    //                 break;
    //             }
    //             // 如果 complement=0，说明正好有该面额的零钱，只需要一个就行
    //             if (complement == 0)
    //             {
    //                 dp[i] = 1;
    //                 break;
    //             }
    //             // 如果complement>0，查看complement最少需要多少个零钱，只需要dp[complement]+1就可以
    //             // temp表示complement面额所需的最少零钱数量
    //             int temp = dp[complement];
    //             // 如果temp<0，说明这个面额不可以用零钱组成，
    //             if (temp < 0)
    //             {
    //                 continue;
    //             }
    //             // 如果temp>=0，说明这个面额可以用零钱组成
    //             else
    //             {
    //                 // 如果dp[i]=-1，说明这是第一次比较，直接让dp[i]=temp+1
    //                 if (dp[i] == -1)
    //                 {
    //                     dp[i] = temp + 1;
    //                 }
    //                 else
    //                 {
    //                     // 如果不是第一次，那么取最小值
    //                     dp[i] = std::min(dp[i], temp + 1);
    //                 }
    //             }
    //         }
    //     }
    //     return dp[amount];
    // }
    int coinChange(std::vector<int> &coins, int amount)
    {
        const int INF = amount + 1;
        std::vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int coin : coins)
        {
            for (int x = coin; x <= amount; ++x)
            {
                dp[x] = std::min(dp[x], dp[x - coin] + 1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
int main()
{
    Solution s;
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans = s.coinChange(coins, amount);
}