#include <vector>
#include <algorithm>
/*
2 , 3 ,-2 , 4 ,  5 ,  8 ,  -4 ,   2 ,    -10,    0 , 9
2   6  -12 -48 -240 -1920  7680  15360  -153600  0 , 9
*/
class Solution
{
public:
    // int maxProduct(std::vector<int> &nums)
    // {
    //     int n = nums.size();
    //     std::vector<int> dp(n,0);
    //     dp[0] = nums[0];
    //     for (int i = 1; i < n;i++){
    //         int num = nums[i];
    //         if(dp[i-1]==0){
    //             dp[i] = nums[i];
    //             continue;
    //         }
    //         dp[i] = dp[i - 1] * num;
    //     }
    //     int max = INT_MIN;
    //     bool firstNegtive=false;
    //     int firstNeg = 0;
    //     for (int i = 0; i < n;i++){
    //         if(dp[i]==0){
    //             firstNegtive = false;
    //             max = std::max(0, max);
    //             continue;
    //         }
    //         if(dp[i]<0&&firstNegtive==false){
    //             firstNegtive = true;
    //             firstNeg = dp[i];
    //             max = std::max(max, firstNeg);
    //             continue;
    //         }
    //         int num = dp[i] > 0 ? dp[i] : dp[i] / firstNeg;
    //         max = std::max(max, num);
    //     }
    //     return max;
    // }
    // int maxProduct(std::vector<int> &nums)
    // {
    //     int n = nums.size();
    //     if(n==1){
    //         return nums[0];
    //     }
    //     std::vector<int> dp_max(n, 0);
    //     dp_max[0] = nums[0];
    //     std::vector<int> dp_min(n, 0);
    //     dp_min[0] = nums[0];
    //     int i = 1;
    //     if(nums[0]==0){
    //         i = 2;
    //         dp_max[1] = dp_min[1] = nums[1];
    //     }
    //     for (; i < n; i++)
    //     {
    //         int num = nums[i];
    //         if(num == 0){
    //             dp_max[i] = dp_min[i] = 0;
    //             if(i+1<n){
    //                 dp_max[i + 1] = dp_min[i + 1] = nums[i + 1];
    //                 i++;
    //                 continue;
    //             }
    //         }
    //         else if (num > 0)
    //         {
    //             dp_max[i] = std::max(dp_max[i - 1] * num,num);
    //             dp_min[i] = std::min(dp_min[i - 1] * num,num);
    //         }else{
    //             dp_max[i] = std::max(dp_min[i - 1] * num,num);
    //             dp_min[i] = std::min(dp_max[i - 1] * num,num);
    //         }
    //     }
    //     int max = INT_MIN;
    //     for (int i = 0; i < n;i++){
    //         max = std::max(max, dp_max[i]);
    //     }
    //     return max;
    // }
    int maxProduct(std::vector<int> &nums){
        int n = nums.size();
        std::vector<int> dp_max(n, 0), dp_min(n, 0);
        dp_max[0] = dp_min[0] = nums[0];
        int max = INT_MIN;
        for (int i = 1; i < n;i++){
            dp_max[i] = std::max(std::max(nums[i] * dp_max[i - 1], nums[i] * dp_min[i - 1]), nums[i]);
            dp_min[i] = std::min(std::min(nums[i] * dp_max[i - 1], nums[i] * dp_min[i - 1]), nums[i]);
            max = std::max(max, dp_max[i]);
        }
        return max;
    }
};