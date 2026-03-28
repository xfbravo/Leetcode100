#include <vector>
class Solution
{
public:
    //np 问题，转化为0-1背包，装下sum/2的东西
    bool canPartition(std::vector<int> &nums)
    {
        int n = nums.size();
        if(n<=1)
            return false;
        int sum = 0;
        int maxNum = 0;
        for (int num : nums)
        {
            sum += num;
            maxNum = std::max(maxNum, num);
        }
        if(sum%2!=0)
            return false;
        int target = sum / 2;
        if(maxNum>target){
            return false;
        }
        //dp[i][j]表示0...i选取若干数，是否存在和为j的方案
        //d[i][j] = d[i-1][j-nums[i]]|d[i-1][j]  , j>nums[i]
        //        = d[i-1][j]                    ,j<nums[i]
        std::vector<std::vector<int>> dp(n, std::vector<int>(target + 1, 0));
        for (int i = 0; i < n;i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n;i++){
            int num = nums[i];
            for (int j = 1; j <= target;j++){
                if(j<num){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
            }
        }
        return dp[n - 1][target];
    }
};