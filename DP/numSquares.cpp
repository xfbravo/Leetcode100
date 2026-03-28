#include <vector>
#include <algorithm>
// 1,2,3,4,5,6,7,8,9,10,11,12
// 1,2,3,1,2,3,4,2,1,2
class Solution
{
public:
    int numSquares(int n){
        std::vector<int> dp(n+1, INT_MAX / 2);
        dp[0] = 0;
        dp[1] = 1;
        if(n<=1){
            return dp[n];
        }
        for (int i = 2; i <= n;i++){
            int j = 1;
            for (; j * j <= i;j++){
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
            if((j-1)*(j-1)==n){
                dp[i] = 1;
            }
        }
        return dp[n];
    }
};