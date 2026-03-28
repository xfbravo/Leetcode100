#include <vector>
#include <algorithm>
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        int buyPrice = prices[0];
        int sellPrice = prices[0];
        int buyDay = 0;
        int sellDay = 0;
        int maxProfit = 0;
        for (int i = 1; i < n;i++){
            if(buyPrice>prices[i]){
                buyPrice = prices[i];
                buyDay = i;
                sellPrice = prices[i];
                sellDay = i;
            }
            if(sellPrice<prices[i]){
                sellPrice = prices[i];
                sellDay = i;
                maxProfit = std::max(sellPrice - buyPrice,maxProfit);
            }
        }
        return maxProfit;
    }
};